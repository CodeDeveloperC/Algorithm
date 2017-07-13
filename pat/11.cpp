#include <cstdlib>
#include "iostream"

using namespace std;

int main() {

    int n;
    int num1 = 0, num2 = 0;
    int a, b, c, d, temp;
    for (int i = 0; i < n; ++i) {
        cin >> a >> b >> c >> d;
        temp = a + c;
        if (temp == b) {
            if (temp != d) {
                num2++;
            }
        } else {
            if (temp == d) {
                num1++;
            }
        }
    }

    cout << num1 << " " << num2;

    system("pause");
    return 0;
}

