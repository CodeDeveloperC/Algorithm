//randSelect.cpp


//ByMeter.cpp
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <time.h>

using namespace std;
const int maxn = 100010;
const int n = 10;

int randPartition(int array[], int left, int right) {
    int p = (round(1.0 * rand() / RAND_MAX * (right - left) + left));

    swap(array[p], array[left]);

    int temp = array[left];
    while (left < right) {
        while (left < right && array[right] > temp) right--;
        array[left] = array[right];

        while (left < right && array[left] <= temp) left++;
        array[right] = array[left];
    }

    array[left] = temp;
    return left;
}

int randSelect(int array[], int left, int right, int K) {
    if (left == right) return array[left];

    int p = randPartition(array, left, right);
    int m = p - left + 1;
    if (K == m) {
        return array[p];
    }

    if (K < m) {
        return randSelect(array, left, p - 1, K);
    } else {
        return randSelect(array, p + 1, right, K - m);
    }
}

int main() {

    int array[n] = {1, 3, 10, 12, 4, 6, 11, 7, 8, 15};

    cout << randSelect(array, 0, 9, 3);

    system("pause");
    return 0;
}



