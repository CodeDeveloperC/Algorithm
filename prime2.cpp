//prime2.cpp

#include <cstdlib>
#include <cmath>
#include "iostream"

using namespace std;
const int maxn = 101;
int prime[maxn], pNum = 0;
bool p[maxn] = {0};


void find_prime() {
    for (int i = 2; i < maxn; ++i) {
        if (p[i] == false) {
            prime[pNum++] = i;
            for (int j = i + i; j < maxn; j += i) {
                p[j] = true;
            }
        }
    }
}

int main(void) {

    find_prime();
    for (int i = 0; i < pNum; ++i) {
        cout << prime[i] << " ";
    }

    cout << endl;

    system("pause");
    return 0;
}

