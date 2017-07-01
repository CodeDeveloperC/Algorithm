
#include <vector>
#include <queue>
#include "iostream"

using namespace std;

const int MAXV = 100010;
const int INF = 100000000;

struct Node {
    int v;
    int cost;
};

vector<Node> adj[MAXV];
int n, m;

int MAX = 0;
int maxArray[MAXV] = { 0 };
int MINMAX = INF;
void dfs(int u, int depth){
    for (int j = 0; j < adj[u].size(); j++){
        int v = adj[u][j].v;

        if (adj[u][j].cost > maxArray[depth - 1]){
            maxArray[depth] = adj[u][j].cost;
        }
        else {
            maxArray[depth] = maxArray[depth - 1];
        }

        if (v == n){
            if(MINMAX>maxArray[depth]){
                MINMAX = maxArray[depth];
            }
            //	MINMAX = MINMAX<maxArray[depth] ? MINMAX : maxArray[depth];
            return;
        }
        dfs(v, depth + 1);
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

    n = 6, m = 6;
    int MIN = INF;
    Node node;
    node.v = 2; node.cost = 4; adj[1].push_back(node);
    node.v = 3; node.cost = 4; adj[2].push_back(node);
    node.v = 6; node.cost = 7; adj[3].push_back(node);
    node.v = 4; node.cost = 2; adj[1].push_back(node);
    node.v = 5; node.cost = 5; adj[4].push_back(node);
    node.v = 6; node.cost = 6; adj[5].push_back(node);

    maxArray[0]=0;

    dfs(1, 1);

    cout << MINMAX << endl;

    return 0;
}

