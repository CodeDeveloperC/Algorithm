#include <cstdlib>
#include <cstdio>
#include "iostream"

using namespace std;

const int maxn = 100010;
bool hashTable[maxn] = {false};
int hashTable2[maxn] = {0};

void hash01();

void hash02();

int main(void) {


    hash02();
    system("pause");
    return 0;
}

void hash01() {
    int m, n, x;
    cin >> n >> m;

    for (int i = 0; i < n; ++i) {
        cin >> x;
        hashTable[x] = true;

    }

    for (int i = 0; i < m; ++i) {
        cin >> x;
        if (hashTable[x]) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }

    }
}

void hash02() {
    int m, n, x;
    cin >> n >> m;

    for (int i = 0; i < n; ++i) {
        cin >> x;
        hashTable2[x]++;

    }

    for (int i = 0; i < m; ++i) {
        cin >> x;
        cout << hashTable2[x] << endl;

    }
}



