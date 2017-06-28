//dfs.cpp


#include <cstdlib>
#include "iostream"

using namespace std;

const int maxn = 30;
int n, V, maxValue = 0;
int w[maxn], c[maxn];

void dfs(int index, int sumW, int sumC) {
    if (index == n) {
        if (sumW <= V && sumC > maxValue) {
            maxValue = sumC;
        }
        return;
    }

    dfs(index + 1, sumW, sumC);//不选
    dfs(index + 1, sumW + w[index], sumC + c[index]);//选
}


void dfs2(int index, int sumW, int sumC) {
    if (index == n) {
        return;
    }

    dfs(index + 1, sumW, sumC);//不选

    if (sumW + w[index] <= V) {
        if (sumC + c[index] > maxValue) {
            maxValue = sumC + c[index];
        }
        dfs(index + 1, sumW + w[index], sumC + c[index]);//选
    }

}

int main(void) {

    cin >> n >> V;
    for (int i = 0; i < n; ++i) {
        cin >> w[i];
    }

    for (int j = 0; j < n; ++j) {
        cin >> c[j];
    }

    //dfs(0, 0, 0);
    dfs2(0, 0, 0);
    cout << maxValue << endl;

    system("pause");
    return 0;
}
