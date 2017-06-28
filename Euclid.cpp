//Euclid.cpp
#include <cstdlib>
#include "iostream"

using namespace std;

int exGcd(int a, int b, int &x, int &y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }

    int g = exGcd(b, a % b, x, y);
    int temp = x;
    x = y;
    y = temp - a / b * y;
    return g;
}

int main(void) {
    int x, y;
    int a = 2, b = 5;
    cout << exGcd(b, a % b, x, y) << endl;

    system("pause");
    return 0;
}



