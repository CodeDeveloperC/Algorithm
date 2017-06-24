//prime.cpp

#include <cstdlib>
#include <cmath>
#include "iostream"

using namespace std;

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

int prime[101], pNum = 0;
bool p[101] = {0};

void find_prime() {
    for (int i = 0; i < 101; ++i) {
        if (isPrime(i) == true) {
            prime[pNum++] = i;
            p[i] = true;
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

