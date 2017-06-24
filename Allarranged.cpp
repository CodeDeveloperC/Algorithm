//Allarranged.cpp
//StringHash.h
#include <cstdlib>
#include "iostream"

using namespace std;

const int maxn = 11;
int n, p[maxn], hashTable[maxn] = {false};

void generateP(int index) {
    if (index == n + 1) {
        for (int i = 1; i < n + 1; ++i) {
            cout << p[i];
        }
        cout << endl;
        return;
    }

    for (int j = 1; j <= n; ++j) {
        if (hashTable[j] == false) {
            p[index] = j;
            hashTable[j] = true;
            generateP(index + 1);
            hashTable[j] = false;
        }
    }
}

int main(void) {

    n = 3;
    generateP(1);


    system("pause");
    return 0;
}





