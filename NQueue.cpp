//NQueue.cpp

//Allarranged.cpp
//StringHash.h
#include <cstdlib>
#include "iostream"

using namespace std;

const int maxn = 11;
int n, p[maxn], hashTable[maxn] = {0};
int mycount = 0;

void generateP(int index) {
    if (index == n + 1) {
        bool flag = true;
        for (int i = 1; i < n + 1; ++i) {
            for (int j = i + 1; j < n + 1; ++j) {
                if (abs(i - j) == abs(p[i] - p[j])) {
                    flag = false;
                    break;
                }
            }
        }
        if (flag) mycount++;
        return;
    }

    for (int j = 1; j <= n; ++j) {
        if (hashTable[j] == 0) {
            p[index] = j;
            hashTable[j] = true;
            generateP(index + 1);
            hashTable[j] = false;
        }
    }
}

int main(void) {

    n = 8;
    generateP(1);

    cout << mycount << endl;

    system("pause");
    return 0;
}








