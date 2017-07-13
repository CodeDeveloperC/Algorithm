#include <cstdlib>
#include "iostream"
using namespace std;

int main(){
    long long a, b, da, db;
    long long pa = 0,pb = 0;
    cin >> a >> da >> b >> db;
    while (a!=0)
    {
        if (a % 10 == da) pa = pa * 10 + da;
        a = a / 10;
    }

    while (b != 0)
    {
        if (b % 10 == db) pb = pb * 10 + db;
        b = b / 10;
    }

    cout << pa + pb;

    system("pause");
    return 0;
}

