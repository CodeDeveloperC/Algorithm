//StringHash.h
#include <cstdlib>
#include "iostream"

using namespace std;

const int maxn = 100010;
char str[maxn][5], temp[5];
bool hashTable[26 * 26 * 26 + 10] = {false};

int hashFunc(char str[], int len) {
    int id = 0;
    for (int i = 0; i < len; ++i) {
        id = id * 26 + (str[i] - 'A');
    }
    return id;
}

int main(void) {
    int m, n;
    cin >> n >> m;

    for (int i = 0; i < n; ++i) {
        cin >> str[i];
        int id = hashFunc(str[i], 3);
        hashTable[id] = true;

    }

    for (int i = 0; i < m; ++i) {
        cin >> temp;
        int id = hashFunc(temp, 3);
        cout << hashTable[id]<<endl;

    }

    system("pause");
    return 0;
}


