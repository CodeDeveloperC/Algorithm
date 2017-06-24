//binarySearch.cpp

#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <iomanip>

using namespace std;

int binarySearch(int array[], int left, int right, int x) {
    int mid;
    while (left <= right) {
        mid = (left + right) / 2;
        if (array[mid] == x) {
            return mid;
        } else if (array[mid] > x) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    return -1;
}


int lower_bound(int array[], int left, int right, int x) {
    int mid;
    while (left < right) {
        mid = (left + right) / 2;
        if (array[mid] >= x) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }

    return left;
}

int upper_bound(int array[], int left, int right, int x) {
    int mid;
    while (left < right) {
        mid = (left + right) / 2;
        if (array[mid] > x) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }

    return left;
}


int main() {
    const int n = 10;
    int array[n] = {1, 3, 4, 6, 7, 8, 10, 11, 12, 15};
//    cout << binarySearch(array, 0, n - 1, 6) << " ";
//    cout << binarySearch(array, 0, n - 1, 9);
    //cout << array[lower_bound(array, 0, n - 1, 5)];
    cout << array[upper_bound(array, 0, n - 1, 5)];

    system("pause");
    return 0;
}


