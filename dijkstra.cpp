//dijkstra.cpp
#include <cstdlib>
#include "iostream"

using namespace std;


const int MAXV = 1000;
const int INF = 1000000000;

int n, graph[MAXV][MAXV], m, s;
int d[MAXV];
bool vis[MAXV] = {false};

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
        for (int v = 0; v < n; ++v) {
            if (!vis[u] && graph[u][v] != INF && d[u] + graph[u][v] < d[v]) {
                d[v] = d[u] + graph[u][v];
            }
        }
    }
}


int main(void) {

    int u, v, w;
    cin >> u >> v >> s;
    fill(graph[0], graph[0] + MAXV, INF);
    for (int i = 0; i < m; ++i) {
        cin >> u >> v >> w;
        graph[u][v] = w;
    }

    dijkstra(s);

    for (int i = 0; i < n; ++i) {
        cout << d[i] << " ";
    }
    cout << endl;

    system("pause");
    return 0;
}



