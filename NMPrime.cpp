//NMPrime.cpp

#include <cstdlib>
#include <cmath>
#include "iostream"

using namespace std;
const int maxn = 10001;
int prime[maxn], pNum = 0;
bool p[maxn] = {0};


void find_prime(int n) {
    for (int i = 2; i < maxn; ++i) {
        if (p[i] == false) {
            prime[pNum++] = i;
            if (pNum >= n) break;
            for (int j = i + i; j < maxn; j += i) {
                p[j] = true;
            }
        }
    }
}

int main(void) {

    int m, n, count = 0;
    cin >> m >> n;
    find_prime(n);
    for (int i = m; i <= n; ++i) {
        cout << prime[i - 1];
        count++;
        if (count % 10 != 0 && i < n) cout << " ";
        else cout << endl;
    }

    cout << endl;

    system("pause");
    return 0;
}



