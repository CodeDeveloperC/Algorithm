//merge.cpp

#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cmath>

using namespace std;

const int maxn = 100;

void merge(int array[], int left1, int right1, int left2, int right2) {
    int i = left1, j = left2;
    int temp[maxn], index = 0;

    while (i <= right1 && j <= right2) {
        if (array[i] <= array[j]) {
            temp[index++] = array[i++];
        } else {
            temp[index++] = array[j++];
        }
    }

    while (i <= right1) temp[index++] = array[i++];
    while (j <= right2) temp[index++] = array[j++];

    for (int k = 0; k < index; ++k) {
        array[left1 + k] = temp[k];
    }
}

void mergeSort(int array[], int left, int right) {
    if (left < right) {
        int mid = (left + right) / 2;
        mergeSort(array, left, mid);
        mergeSort(array, mid + 1, right);
        merge(array, left, mid, mid + 1, right);
    }
}

int main() {

    const int n = 10;
    int array[n] = {1, 3, 10, 12, 4, 6, 11, 7, 8, 15};
    mergeSort(array, 0, 9);

    for (int i = 0; i < n; ++i) {
        cout << array[i] << " ";
    }
    cout << endl;

    system("pause");
    return 0;
}
