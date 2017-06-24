//Fraction.cpp

#include <cstdlib>
#include <cstdio>
#include "iostream"

using namespace std;

struct Fraction {
    int up, down;//分子，分母
};

int gcd(int a, int b) {
    if (b == 0) return a;
    else return gcd(b, a % b);
}

//分数化简
Fraction reduction(Fraction result) {
    if (result.down < 0) {
        result.up = -result.up;
        result.down = -result.down;
    }

    if (result.up == 0) {
        result.down = 1;
    } else {
        int d = gcd(abs(result.up), abs(result.down));
        result.up /= d;
        result.down /= d;
    }

    return result;
}

//分数相加
Fraction add(Fraction fraction1, Fraction fraction2) {
    Fraction result;
    result.up = fraction1.up * fraction2.down + fraction2.up * fraction1.down;
    result.down = fraction1.down * fraction2.down;

    return reduction(result);
}

//分数相减
Fraction minu(Fraction fraction1, Fraction fraction2) {
    Fraction result;
    result.up = fraction1.up * fraction2.down - fraction2.up * fraction1.down;
    result.down = fraction1.down * fraction2.down;

    return reduction(result);
}

//分数相乘
Fraction multi(Fraction fraction1, Fraction fraction2) {
    Fraction result;
    result.up = fraction1.up * fraction2.up;
    result.down = fraction1.down * fraction2.down;

    return reduction(result);
}

//分数相除
Fraction divide(Fraction fraction1, Fraction fraction2) {
    Fraction result;
    result.up = fraction1.up * fraction2.down;
    result.down = fraction1.down * fraction2.up;

    return reduction(result);
}

//分数输出
void showResult(Fraction fraction) {
    fraction = reduction(fraction);
    if (fraction.down == 1) {
        printf("%lld", fraction.up);
    } else if (abs(fraction.up) > fraction.down) {
        printf("%d %d/%d", fraction.up / fraction.down, abs(fraction.up) % fraction.down, fraction.down);
    } else {
        printf("%d/%d", fraction.up, fraction.down);
    }
}

int main(void) {

    Fraction fraction1;
    Fraction fraction2;
    fraction1.up = 10;
    fraction1.down = 3;

    fraction2.up = 18;
    fraction2.down = 4;

    cout << "fraction2: ";
    showResult(fraction2);
    cout << endl;

    cout << "add(fraction1, fraction2): ";
    showResult(add(fraction1, fraction2));
    cout << endl;

    cout << "minu(fraction1, fraction2): ";
    showResult(minu(fraction1, fraction2));
    cout << endl;

    cout << "multi(fraction1, fraction2): ";
    showResult(multi(fraction1, fraction2));
    cout << endl;

    cout << "divide(fraction1, fraction2): ";
    showResult(divide(fraction1, fraction2));
    cout << endl;

    system("pause");
    return 0;
}

