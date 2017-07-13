#include <cstdlib>
#include <cstdio>
#include <vector>

#include "iostream"

using namespace std;
vector<int> vector1;

int main() {
    int a;
    int num=0;
    bool flag = false;
    bool flag2 = false;
    while ((a = getchar()) != 10) {
        if (a == 45) {
            flag = true;
        }
        if (a >= 48 && a <= 57) {
            if (flag2) {
                vector1[vector1.size() - 1] = vector1[vector1.size() - 1] * 10 + (a - 48);
            } else if (flag) {
                vector1.push_back((a - 48) * (-1));
                flag = false;
            } else {
                vector1.push_back((a - 48));
            }
            flag2 = true;
        } else {
            flag2 = false;
        }
    }

    for (int i = 0; i < vector1.size(); ++i) {
        if (i % 2 == 0) {
            vector1[i] *= vector1[i + 1];
            vector1[i + 1]--;
        }
    }

    for (int i = 0; i < vector1.size(); ++i) {
        if (i % 2 == 0) {
            if (vector1[i] == 0) {
                i++;
                continue;
            }
        }
        if (i == 0) {
            cout << vector1[i];
        } else {
            cout << " " << vector1[i];
        }
        num++;
    }

    if(num==0)
        cout<<"0 0";


    system("pause");
    return 0;
}

