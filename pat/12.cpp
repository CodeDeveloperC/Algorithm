#include <cstdlib>
#include "iostream"
using namespace std;
int a[110];

int main(){
    int n,m;
    cin>>n>>m;
    for (int i = m; i < n; ++i) {
        cin>>a[i];
    }
    for (int i = 0; i < m; ++i) {
        cin>>a[i];
    }

    for (int i = 0; i < n; ++i) {
        if (i != n - 1) {
            cout<<a[i]<<" ";
        } else {
            cout<<a[i];
        }

    }


    system("pause");
    return 0;
}

