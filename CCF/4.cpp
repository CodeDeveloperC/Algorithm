//4
#include <vector>
#include "iostream"

using namespace std;

const int MAXV = 10010;
const int INF = 100000000;

struct Node {
    int v;
    int cost;
};

vector<Node> adj[MAXV];
int d[MAXV];
bool vis[MAXV] = {false};
int n, m;

void dj(int s) {
    fill(d, d + n, INF);
    d[s] = 0;

    for (int i = 0; i < n - 1; ++i) {
        int u = -1, MIN = INF;
        for (int j = 0; j < n; ++j) {
            if (!vis[j] && d[j] < MIN) {
                u = j;
                MIN = d[j];
            }
        }

        if (u == -1) {
            return;
        }
        vis[u] = true;
        for (int j = 0; j < adj[u].size(); ++j) {
            int v = adj[u][i].v;
            int cost = adj[u][i].cost;
            if (!vis[v] && d[u]!=INF && d[u] + cost < d[v]) {
                d[v] = d[u] + cost;
            }
        }
    }
}

int main() {
//    cin >> n >> m;
//    int a,b,c;
//    Node node;
//
//    for (int i = 0; i < m; ++i) {
//        cin>>a>>b>>c;
//        node.v=b;
//        node.cost=c;
//        adj[a].push_back(node);
//    }
    n=6,m=6;
    Node node;
    node.v=2;node.cost=4;adj[1].push_back(node);
    node.v=3;node.cost=4;adj[2].push_back(node);
    node.v=6;node.cost=7;adj[3].push_back(node);
    node.v=4;node.cost=2;adj[1].push_back(node);
    node.v=5;node.cost=5;adj[4].push_back(node);
    node.v=6;node.cost=6;adj[5].push_back(node);


    dj(1);
    cout<<d[6]<<endl;

    return 0;
}

