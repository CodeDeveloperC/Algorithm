//maze.cpp
#include <cstdlib>
#include <queue>
#include <cstdio>
#include "iostream"

using namespace std;

struct Node {
    int x, y;
    int step;
} S, T, node;
const int maxNumber = 100;
int n, m;
char maze[maxNumber][maxNumber]={
        {'.','.','.','.','.'},
        {'.','*','.','*','.'},
        {'.','*','S','*','.'},
        {'.','*','*','*','.'},
        {'.','.','.','T','*'}
};
bool inq[maxNumber][maxNumber] = {false};
int X[4] = {0, 0, 1, -1};
int Y[4] = {1, -1, 0, 0};

bool test(int x, int y) {
    if (x >= n || x < 0 || y >= m || y < 0) {
        return false;
    }

    if (maze[x][y] == '*') {
        return false;
    }

    if (inq[x][y] == true) {
        return false;
    }

    return true;
}

int bfs() {
    queue<Node> queue1;
    queue1.push(S);
    while (!queue1.empty()) {
        Node top = queue1.front();
        queue1.pop();
        if (top.x == T.x && top.y == T.y) {
            return top.step;
        }

        for (int i = 0; i < 4; ++i) {
            int newX = top.x + X[i];
            int newY = top.y + Y[i];

            if (test(newX, newY)) {
                node.x = newX;
                node.y = newY;
                node.step = top.step + 1;
                queue1.push(node);
                inq[newX][newY] = true;
            }
        }
    }

    return -1;
}

int main(void) {

//    cin >> n >> m;
//    for (int i = 0; i < n; ++i) {
//        getchar();
//        for (int j = 0; j < m; ++j) {
//            maze[i][j] = getchar();
//        }
//        maze[i][m + 1] = '\0';
//    }
    n = 5, m = 6;

    cin >> S.x >> S.y >> T.x >> T.y;
    S.step = 0;
    cout << bfs() << endl;

    system("pause");
    return 0;
}



