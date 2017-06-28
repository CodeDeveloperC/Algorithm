#include <cstdlib>
#include <vector>
#include <queue>
#include "iostream"

using namespace std;

const int maxn = 10010;
struct Node {
    int data;
    vector child;
} node[maxn];

int index = 0;

int newNode(int v) {
    node[index].data = v;
    node[index].child.clear();
    return index++;
}

void preOrder(int root){
    cout << node[root].data << " ";
    for (int i = 0; i < node[root].child.size(); ++i) {
        preOrder(node[root].child[i]);
    }
}

void layerOrder(int root){
    queue<int > queue1;
    queue1.push(root);

    while (!queue1.empty()) {
        int front = queue1.front();
        cout << node[front].data << " ";
        queue1.pop();
        for (int i = 0; i < node[root].child.size(); ++i) {
            queue1.push(node[front].child[i]);
        }
    }
}

int main(void) {


    system("pause");
    return 0;
}
