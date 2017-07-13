#include <cstdlib>
#include <time.h>
#include <cstdio>
#include <cmath>
#include "iostream"

using namespace std;
long long c1, c2, c3;

int main() {
    cin >> c1 >> c2;
    double h, m, s;
    c3 = c2 - c1;
    c3 /= CLK_TCK;
    h = round(c3 / 3600);
    m = (c3 % 3600) / 60;
    s = c3 % 60;
    printf("%02d:%02d:%02d", h, m, s);

    system("pause");
    return 0;
}




