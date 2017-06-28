//p305.cpp
#include <cstdlib>
#include <vector>
#include <queue>
#include <algorithm>
#include "iostream"

using namespace std;

const int maxn = 110;
struct Node {
    int weight;
    vector<int> child;
} node[maxn];

int index = 0;
int n, m, S;
int path[maxn];

bool cmp(int a, int b) {
    return node[a].weight > node[b].weight;
}

void dfs(int index, int numNode, int sum) {
    if (sum > S) {
        return;
    }

    if (sum == S) {
        if (node[index].child.size() != 0) {
            return;
        }

        for (int i = 0; i < numNode; ++i) {
            cout << node[path[i]].weight;
            if (i < numNode - 1) {
                cout << " ";
            } else {
                cout << endl;
            }
        }

        return;
    }

    for (int i = 0; i < node[index].child.size(); ++i) {
        int child = node[index].child[i];
        path[numNode] = child;
        dfs(child, numNode + 1, sum + node[child].weight);
    }
}

int newNode(int v) {
    node[index].weight = v;
    node[index].child.clear();
    return index++;
}

void preOrder(int root) {
    cout << node[root].weight << " ";
    for (int i = 0; i < node[root].child.size(); ++i) {
        preOrder(node[root].child[i]);
    }
}

void layerOrder(int root) {
    queue<int> queue1;
    queue1.push(root);

    while (!queue1.empty()) {
        int front = queue1.front();
        cout << node[front].weight << " ";
        queue1.pop();
        for (int i = 0; i < node[root].child.size(); ++i) {
            queue1.push(node[front].child[i]);
        }
    }
}

int main(void) {

    cin>>n>>m>>S;
    for (int i = 0; i < n; ++i) {
        cin >> node[i].weight;
    }

    int id,k,child;
    for (int i = 0; i < m; ++i) {
        cin>>id>>k;
        for (int j = 0; j < k; ++j) {
            cin >> child;
            node[id].child.push_back(child);
        }

        sort(node[id].child.begin(), node[id].child.end(),cmp);
    }

    path[0] = 0;
    dfs(0, 1, node[0].weight);

    system("pause");
    return 0;
}



