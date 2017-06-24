//ByMeter.cpp
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cmath>

using namespace std;
const int mod = 1000007;
const int maxn = 100010;
char str[maxn];
int leftNump[maxn] = {0};

int main() {

    gets(str);
    int len = strlen(str);

    for (int i = 0; i < len; ++i) {
        if (i > 0) {
            leftNump[i] = leftNump[i - 1];
        }

        if (str[i] == 'P') {
            leftNump[i]++;
        }
    }

    int ans = 0;
    int rightNumT = 0;

    for (int j = len - 1; j >= 0; j--) {
        if (str[j] == 'T') {
            rightNumT++;
        } else if (str[j] == 'A') {
            ans = (ans + leftNump[j] * rightNumT) % mod;
        }
    }

    cout << ans << endl;

    system("pause");
    return 0;
}


