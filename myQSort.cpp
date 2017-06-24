//myQSort.cpp

#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cmath>

using namespace std;

const int n = 10;

int partition(int array[], int left, int right) {

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


int randPartition(int array[], int left, int right) {
    int p=(round(1.0*rand()/RAND_MAX*(right-left)+left));

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

void quickSort(int array[], int left, int right) {
    if (left < right) {
        int pos = partition(array, left, right);
        quickSort(array, left, pos - 1);
        quickSort(array, pos + 1, right);
    }
}

void quickSortRand(int array[], int left, int right) {
    if (left < right) {
        int pos = randPartition(array, left, right);
        quickSort(array, left, pos - 1);
        quickSort(array, pos + 1, right);
    }
}


int main() {
    int array[n] = {1, 3, 10, 12, 4, 6, 11, 7, 8, 15};
    //quickSort(array, 0, 9);
    quickSortRand(array, 0, 9);


    for (int i = 0; i < n; ++i) {
        cout << array[i] << " ";
    }
    cout << endl;

    system("pause");
    return 0;
}


