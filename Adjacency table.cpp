//Adjacency.cpp
#include <cstdlib>
#include <vector>
#include "iostream"
using namespace std;

const int MAXV = 1000;
const int INF = 1000000000;

struct Node{
    int v,dis;
};

int n, graph[MAXV][MAXV];
int d[MAXV];
bool vis[MAXV] = {false};
vector<Node> adjacent[MAXV];

void dijkstra(int s) {
    fill(d, d + MAXV, INF);
    d[s] = 0;
    for (int i = 0; i < n; ++i) {
        int u = -1;
        int MIN = INF;
        for (int j = 0; j < n; ++j) {
            if (!vis[j] && d[j] < MIN) {
                u = j;
                MIN = d[j];
            }
        }

        if (u == -1)
            return;
        vis[u] = true;
        for (int v = 0; v < adjacent[u].size(); ++v) {
            int v=adjacent[u][v].v;
            if (!vis[v] && d[u] + adjacent[u][v].dis < d[v]) {
                d[v] = d[u] + adjacent[u][v].dis;
            }
        }
    }
}

int main(void){


    system("pause");
    return 0;
}


