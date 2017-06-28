//p333.cpp
#include <cstdlib>
#include "iostream"

using namespace std;
const int Number = 100;
int father[Number];
bool isRoot[Number];

int findFather(int x) {
    int a = x;
    while (x != father[x]) {
        x = father[x];
    }

    while (a != father[a]) {
        int z = a;
        a = father[a];
        father[z] = x;
    }

    return x;
}

void myUnion(int a, int b) {
    int faA = findFather(a);
    int faB = findFather(b);
    if (faA != faB) {
        father[faA] = faB;
    }
}

void init(int n) {
    for (int i = 1; i <= n; ++i) {
        father[i] = i;
        isRoot[i] = false;
    }
}

int main(void) {

    int n, m, a, b;
    /*cin >> n >> m;
    for (int i = 0; i < m; ++i) {
    cin >> a >> b;
    myUnion(a, b);
    }*/
    n = 7;
    m = 5;
    init(n);
    myUnion(1, 2);
    myUnion(2, 3);
    myUnion(3, 1);
    myUnion(1, 4);
    myUnion(5, 6);



    for (int i = 1; i <= n; ++i) {
        isRoot[findFather(i)] = true;
    }

    for (int i = 1; i <= n; ++i) {
        cout << "findFather(i): " << findFather(i) << " " << "isRoot[findFather(i)]: " << isRoot[findFather(i)] << endl;
        //isRoot[findFather(i)] = true;
    }

    int ans = 0;

    for (int i = 1; i <= n; ++i) {
        ans += isRoot[i];
    }

    cout << ans << endl;
    system("pause");
    return 0;
}



