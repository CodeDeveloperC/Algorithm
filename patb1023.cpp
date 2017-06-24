//patb1023.cpp

#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <iomanip>

using namespace std;

int main() {

    int count[10];
    for (int i = 0; i < 10; ++i) {
        cin >> count[i];
    }

    for (int j = 1; j < 10; ++j) {
        if (count[j] != 0) {
            cout << j;
            count[j]--;
            break;
        }
    }

    for (int k = 0; k < 10; ++k) {
        for (int i = 0; i < count[k]; ++i) {
            cout << k;
        }
    }

    system("pause");
    return 0;
}


