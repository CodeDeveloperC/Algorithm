//note.cpp
#include <cstdlib>
#include <queue>
#include "iostream"
using namespace std;

struct Node {
    int data;
} node[10];


int main(void){

    queue<int > queue1;
    for (int i = 0; i <=3; ++i) {
        node[i].data=i;
        queue1.push(i);
    }

    node[queue1.front()].data=100;
    cout<<node[1].data;

    system("pause");
    return 0;
}

