

#include <cstdlib>
#include "iostream"

using namespace std;
long long a, b, c;
bool flag[11] = {false};

int main(void) {
    int t;
    cin >> t;

    for (int i = 0; i < t; ++i) {
        cin >> a >> b >> c;
        if (a + b > c) {
            flag[i] = true;
        }
    }

    for (int i = 0; i < t; ++i) {
        cout << "Case#" << i << ":" << flag[i] << endl;
    }


    system("pause");
    return 0;
}


