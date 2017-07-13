#include <cstdlib>
#include "iostream"
using namespace std;
struct Node{
    int success;
    int fail;
    int balance;
    int sc[4];
}node[2];

int cmp(char a, char b){
    if(a==b){
        return 0;
    }
    if(a>b) {
        if (a == 'B' && b == 'J') {
            return -1;
        }
        return 1;
    }
    return -1;
}

int main(){
    int n;
    int maxn=0;
    char a,b;
    int c;
    cin>>n;

    for (int i = 0; i < 2; ++i) {
        node[i].success=0;
        node[i].balance=0;
        node[i].fail=0;
        for (int j = 0; j < 4; ++j) {
            node[i].sc[j]=0;
        }
    }

    for (int i = 0; i < n; ++i) {
        cin>>a>>b;
        c=cmp(a, b);
        if (c == 1) {
            node[0].success++;
            node[1].fail++;
            if (a == 'B') {
                node[0].sc[0]++;
            } else if (a == 'C') {
                node[0].sc[1]++;
            } else {
                node[0].sc[2]++;
            }
        } else if (c == 0) {
            node[0].balance++;
            node[1].balance++;
        } else {
            node[1].success++;
            node[0].fail++;
            if (a == 'B') {
                node[1].sc[0]++;
            } else if (a == 'C') {
                node[1].sc[1]++;
            } else {
                node[1].sc[2]++;
            }
        }
    }

    for (int i = 0; i < 3; ++i) {
        if (node[0].sc[i] > maxn) {
            maxn=i;
        }
    }


    cout<<node[0].success<<" "<<node[0].balance<<" "<<node[0].fail<<endl;
    cout<<node[1].success<<" "<<node[1].balance<<" "<<node[1].fail<<endl;
    cout<<node[0].sc[maxn]<<" ";
    for (int i = 0; i < 3; ++i) {
        if (node[1].sc[i] > maxn) {
            maxn=i;
        }
    }
    cout<<node[1].sc[maxn]<<" ";


    system("pause");
    return 0;
}

