//Factorfactordecomposition.cpp

#include <cstdlib>
#include <cmath>
#include "iostream"

using namespace std;
const int maxn = 100010;

bool isPrime(int n) {
    if (n <= 1) return false;
    int sqr = (int) sqrt(n * 1.0);

    for (int i = 2; i <= sqr; ++i) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

int prime[maxn], pNum = 0;

void find_prime() {
    for (int i = 0; i < maxn; ++i) {
        if (isPrime(i) == true) {
            prime[pNum++] = i;
        }
    }
}

struct Factor {
    int x, cnt;
} factor[10];


int main(void) {

    find_prime();
    int n, num = 0;
    cin >> n;
    if (n == 1) cout << "1=1";
    else {
        cout << n << "=";
        int sqr = (int) sqrt(1.0 * n);
        for (int i = 0; i < pNum && prime[i] <= sqr; ++i) {
            if (n % prime[i] == 0) {
                factor[num].x = prime[i];
                factor[num].cnt = 0;

                while (n % prime[i] == 0) {
                    factor[num].cnt++;
                    n /= prime[i];
                }
                num++;
            }
            if (n == 1) {
                break;
            }
        }

        if (n != 1) {
            factor[num].x = n;
            factor[num].cnt = 1;
        }

        for (int i = 0; i < num; ++i) {
            if (i > 0) cout << "*";
            cout << factor[i].x;
            if (factor[i].cnt > 1) {
                cout << "^" << factor[i].cnt;
            }
        }
    }
    system("pause");
    return 0;
}



