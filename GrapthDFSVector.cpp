//GraphDFSVector.cpp
#include <cstdlib>
#include <vector>
#include "iostream"

using namespace std;


const int MAXV = 1000;
const int INF = 1000000000;

vector<int> adjacent[MAXV];
int n;
bool vis[MAXV] = {false};

void dfs(int u, int depth) {
    vis[u] = true;
    for (int i = 0; i < adjacent[u].size(); ++i) {
        int v = adjacent[u][i];
        if (!vis[v]) {
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



