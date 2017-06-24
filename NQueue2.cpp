//NQueue2.cpp

//NQueue.cpp

//Allarranged.cpp
//StringHash.h
#include <cstdlib>
#include "iostream"

using namespace std;

const int maxn = 11;
int n, p[maxn], hashTable[maxn] = {0};
int mycount = 0;

void generateP(int index) {
    if (index == n + 1) {
        mycount++;
        return;
    }

    for (int x = 1; x < n + 1; ++x) {
        if (hashTable[x] == false) {
            bool flag = true;
            for (int pre = 1; pre < index; ++pre) {
                if (abs(index - pre) == abs(x - p[pre])) {
                    flag = false;
                    break;
                }
            }

            if (flag) {
                p[index] = x;
                hashTable[x] = true;
                generateP(index + 1);
                hashTable[x] = false;
            }
        }
    }
}

int main(void) {

    n = 8;
    generateP(1);

    cout << mycount << endl;

    system("pause");
    return 0;
}









