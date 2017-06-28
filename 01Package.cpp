//01Package.cpp


#include <cstdlib>
#include "iostream"

using namespace std;

const int maxNumber = 100;
const int maxv = 1000;
int weight[maxNumber]={
        3,5,1,2,2
};
int cost[maxNumber]={
        4,5,2,1,3
};
int dp[maxNumber]={0};


int main(void) {

    int n, V;
    n = 5;
    V=8;

//    cin >> n >> V;
//    for (int i = 0; i < n; ++i) {
//        cin >> weight[i];
//    }
//
//    for (int i = 0; i < n; ++i) {
//        cin >> cost[i];
//    }

    for (int v = 0; v <= V; ++v) {
        dp[v] = 0;
    }

    for (int i = 1; i <= n; ++i) {
        for (int v = V; v >= weight[i]; --v) {
            dp[v] = max(dp[v], dp[v - weight[i]] + cost[i]);
        }
    }

    int max = 0;
    for (int v = 0; v <= V; ++v) {
        if (dp[v] > max) {
            max = dp[v];
        }
    }

    cout << max << endl;

    system("pause");
    return 0;
}

