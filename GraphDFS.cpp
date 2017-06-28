//GraphDFS.cpp
#include <cstdlib>
#include "iostream"

using namespace std;

const int MAXV = 1000;
const int INF = 1000000000;

int n, graph[MAXV][MAXV];
bool vis[MAXV] = {false};

void dfs(int u, int depth) {
    vis[u] = true;
    for (int v = 0; v < n; ++v) {
        if (!vis[v] && graph[u][v] != INF) {
            dfs(v, depth + 1);
        }
    }
}

void dfsTraverse() {
    for (int u = 0; u < n; ++u) {
        if (!vis[u]) {
            dfs(u, 1);
        }
    }
}

int main(void) {


    system("pause");
    return 0;
}



