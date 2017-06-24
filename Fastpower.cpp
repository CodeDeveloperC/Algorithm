//Fastpower.cpp
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cmath>

using namespace std;

typedef long long LL;

LL binaryPower(LL a, LL b, LL m){
    if (b == 0) {
        return 1;
    }

    if (b % 2 == 1) {
        return a * binaryPower(a, b - 1, m) % m;
    }
    else {
        LL mul = binaryPower(a, b / 2, m);
        return mul * mul % m;
    }
}

int main(){

    cout << binaryPower(10, 18, 3) << endl;

    system("pause");
    return 0;
}


