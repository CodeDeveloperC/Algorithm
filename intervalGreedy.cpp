//intervalGreedy.cpp


#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <iomanip>

using namespace std;

const int maxn = 110;

struct Interval {
    int x, y;
} interval[maxn];

bool cmp(Interval a, Interval b) {
    if (a.x != b.x) return a.x > b.x;
    else return a.y > b.y;
}

int main() {

    int n;
    while (scanf("%d", &n) != EOF, n != 0) {
        for (int i = 0; i < n; ++i) {
            cin >> interval[i].x >> interval[i].y;
        }

        sort(interval, interval + n, cmp);

        int ans = 1, lastX = interval[0].x;

        for (int j = 1; j < n; ++j) {
            if (interval[j].y <= lastX) {
                lastX = interval[j].x;
                cout << interval[j].x << " : " << interval[j].y << endl;
                ans++;
            }
        }

        cout << ans << endl;
    }

    system("pause");
    return 0;
}
