//bfs.cpp

#include <cstdlib>
#include <queue>
#include "iostream"

using namespace std;

const int maxNumber = 100;
struct Node {
    int x, y;
} node;

int n, m;
int matrix[maxNumber][maxNumber] = {
        {0, 1, 1, 1, 0, 0, 1},
        {0, 0, 1, 0, 0, 0, 0},
        {0, 0, 0, 0, 1, 0, 0},
        {0, 0, 0, 1, 1, 1, 0},
        {1, 1, 1, 0, 1, 0, 0},
        {1, 1, 1, 1, 0, 0, 0},
};
bool inq[maxNumber][maxNumber] = {false};
int X[4] = {0, 0, 1, -1};
int Y[4] = {1, -1, 0, 0};

bool judge(int x, int y) {
    if (x >= n || x < 0 || y >= m || y < 0) {
        return false;
    }

    if (matrix[x][y] == 0 || inq[x][y] == true) {
        return false;
    }

    return true;
}

void bfs(int x, int y) {
    queue<Node> queue1;
    node.x = x;
    node.y = y;
    queue1.push(node);
    inq[x][y] = true;
    while (!queue1.empty()) {
        Node top = queue1.front();
        queue1.pop();
        for (int i = 0; i < 4; ++i) {
            int newX = top.x + X[i];
            int newY = top.y + Y[i];

            if (judge(newX, newY)) {
                node.x = newX;
                node.y = newY;
                queue1.push(node);
                inq[newX][newY] = true;
            }
        }
    }
}

int main(void) {

//    cin >> n >> m;
//    for (int x = 0; x < n; ++x) {
//        for (int y = 0; y < m; ++y) {
//            cin >> matrix[x][y];
//        }
//    }
    n = 6, m = 7;
    int ans = 0;
    for (int x = 0; x < n; ++x) {
        for (int y = 0; y < m; ++y) {
            if (matrix[x][y] == 1 && inq[x][y] == false) {
                ans++;
                bfs(x, y);
            }
        }
    }

    cout << ans << endl;

    system("pause");
    return 0;
}
