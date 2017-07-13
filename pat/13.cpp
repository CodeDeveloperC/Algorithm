#include <cstdlib>
#include <cstdio>
#include "iostream"
using namespace std;
int a[1010];

int main(){
    int n;
    cin >> n;
    int a1 = 0, a2 = 0, a3 = 0, a5 = 0;
    int num = 0;
    double a4 = 0;
    int flag = -1;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        if (a[i] % 5 == 0 && a[i] % 2 == 0) {
            a1 += a[i];
        }
        if (a[i] % 5 == 1) {
            a2 += flag*a[i] * (-1);
        }
        if (a[i] % 5 == 2) {
            a3++;
        }
        if (a[i] % 5 == 3) {
            a4 += a[i];
            num++;
        }
        if (a[i] % 5 == 4) {
            a5 = a5 > a[i] ? a5 : a[i];
        }
    }
    if (num != 0) {
        a4 /= num;
    }


    if (a1 == 0)
        cout << "N ";
    else
        cout << a1 << " ";

    if (a2 == 0)
        cout << "N ";
    else
        cout << a2 << " ";

    if (a3 == 0)
        cout << "N ";
    else
        cout << a3 << " ";

    if (a4 == 0)
        cout << "N ";
    else
        printf("%.1f ", a4);

    if (a5 == 0)
        cout << "N";
    else
        cout << a5;






    system("pause");
    return 0;
}

