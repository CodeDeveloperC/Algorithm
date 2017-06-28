//p273.cpp

#include <cstdlib>
#include <vector>
#include "iostream"

using namespace std;

const int maxn = 10;
int n = 9, k, x, maxSumSqu = 0, array[maxn] = {2, 6, 9, 8, 3, 4, 5, 7, 1};
vector<int> temp, ans;

void dfs(int index, int nowK, int sum, int sumSqu) {
    if (nowK == k && sum == x) {
        if (sumSqu > maxSumSqu) {
            maxSumSqu = sumSqu;
            ans = temp;
        }

        return;
    }
    if (index == n || nowK > k || sum > x) {
        return;
    }

    temp.push_back(array[index]);
    dfs(index + 1, nowK + 1, sum + array[index], sumSqu + array[index] * array[index]);
    temp.pop_back();
    dfs(index + 1, nowK, sum, sumSqu);
}


int main(void) {
    x = 15;
    k = 2;
    dfs(0, 0, 0, maxSumSqu);
    cout << maxSumSqu << endl;
    for (int i = 0; i < ans.size(); ++i) {
        cout << ans[i] << endl;
    }

    system("pause");
    return 0;
}



