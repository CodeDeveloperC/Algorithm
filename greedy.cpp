//greedy.cpp


#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <iomanip>

using namespace std;

struct moonCake {
    double store;//库存量
    double sell;//总售价
    double price;//单价
} cake[1010];

bool cmp(moonCake a, moonCake b) {
    return a.price > b.price;
}

int main() {

    int n;
    double D;
    cin >> n >> D;
    for (int i = 0; i < n; ++i) {
        cin >> cake[i].store;
    }

    for (int i = 0; i < n; ++i) {
        cin >> cake[i].sell;
        cake[i].price = cake[i].sell / cake[i].store;
    }

    sort(cake, cake + n, cmp);

    double ans = 0;

    for (int j = 0; j < n; ++j) {
        if (cake[j].store <= D) {
            D -= cake[j].store;
            ans += cake[j].sell;
        }
        else {
            ans += D * cake[j].price;
            break;
        }
    }

    //setiosflags(ios::fixed)控制小数位数
    cout << setiosflags(ios::fixed)<< setprecision(2);
    cout << ans << endl;
    printf("%.2f\n", ans);

    system("pause");
    return 0;
}