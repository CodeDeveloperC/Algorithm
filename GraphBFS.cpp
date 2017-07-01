//GraphBFS.cpp
#include <cstdlib>
#include <queue>
#include "iostream"

using namespace std;

const int MAXV = 1000;
const int INF = 1000000000;

int n, graph[MAXV][MAXV];
bool inq[MAXV] = {false};

void bfs(int u) {
    queue<int> queue1;
    queue1.push(u);
    inq[u] = true;
    while (!queue1.empty()) {
        int u = queue1.front();
        queue1.pop();
        for (int v = 0; v < n; ++v) {
            if (!inq[v] && graph[u][v] != INF) {
                queue1.push(v);
                inq[v] = true;
            }
        }
    }
}

void dfsTraverse() {
    for (int u = 0; u < n; ++u) {
        if (!inq[u]) {
            bfs(u);
        }
    }
}

int main(void) {


    system("pause");
    return 0;
}


