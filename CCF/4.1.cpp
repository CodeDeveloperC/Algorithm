


//4
#include <vector>
#include <queue>
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
vector<vector<int> > vv;
bool vis[MAXV] = { false };
bool inq[MAXV] = { false };
int n, m;

int MAX = 0;
vector<int> maxArray;
int MINMAX=INF;
void dfs(int u, int depth){
    for (int j = 0; j < adj[u].size(); j++){
        int v = adj[u][j].v;

        if (adj[u][j].cost > maxArray[depth-1]){
            maxArray.push_back(adj[u][j].cost);
        } else {
            maxArray.push_back(maxArray[depth-1]);
        }

        if (v == n){
            MINMAX = MINMAX<MAX ? MINMAX : maxArray[depth];
            return;
        }
        dfs(v, depth + 1);
    }

}

void dfs2(int u, int depth){
    vis[u] = true;
    int i=0;


    for (int j = 0; j < adj[u].size(); j++){
        int v = adj[u][j].v;
        //vv[i]

        vv[i].push_back(adj[u][j].cost);


//        if (adj[u][j].cost > MAX){
//            MAX = adj[u][j].cost;
//        }

        if (v == n){
//            MINMAX = MINMAX<MAX ? MINMAX : MAX;
//            MAX = 0;
            i++;
            return;
        }
        if (!vis[v])
            dfs2(v, depth + 1);
    }

}

void bfs(int u){

    queue<int> queue1;
    queue1.push(u);
    inq[u]=true;

    while (!queue1.empty()) {
        int u=queue1.front();
        queue1.pop();

        for (int i = 0; i < adj[u].size(); ++i) {
            int v=adj[u][i].v;
            if(inq[v]== false){
                queue1.push(v);
                inq[v]=true;
            }
        }
    }
}

void bell_man(int s){
    fill(d, d + n + 1, INF);
    d[s]=0;
    for (int i = 0; i < n-1; ++i) {
        for (int u = 1; u <= n; ++u) {
            for (int j = 0; j < adj[u].size(); ++j) {
                int v=adj[u][j].v;
                if (d[v] > d[u] + adj[u][j].cost) {
                    d[v]= d[u] + adj[u][j].cost;
                }
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
    n = 6, m = 6;
    int MIN = INF;
    Node node;
    node.v = 2; node.cost = 4; adj[1].push_back(node);
    node.v = 3; node.cost = 4; adj[2].push_back(node);
    node.v = 6; node.cost = 7; adj[3].push_back(node);
    node.v = 4; node.cost = 2; adj[1].push_back(node);
    node.v = 5; node.cost = 5; adj[4].push_back(node);
    node.v = 6; node.cost = 6; adj[5].push_back(node);

    maxArray.push_back(0);

    /*for (int i = 1; i <= n; i++){
        if (!vis[i]){
            dfs(i, 1);
        }

    }*/

    dfs(1, 1);

    cout << MINMAX << endl;

    system("pause");

    return 0;
}

