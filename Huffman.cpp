//Huffman.cpp

#include <cstdlib>
#include <queue>
#include "iostream"

using namespace std;

priority_queue<long long, vector<long long>, greater<long long> > priorityQueue;

int main(void) {

    int n;
    long long temp, x, y, ans = 0;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> temp;
        priorityQueue.push(temp);
    }

    while (priorityQueue.size() > 1) {
        x = priorityQueue.top();
        priorityQueue.pop();
        y = priorityQueue.top();
        priorityQueue.pop();
        priorityQueue.push(x + y);
        ans += x + y;
    }

    cout << ans << endl;

    system("pause");
    return 0;
}

