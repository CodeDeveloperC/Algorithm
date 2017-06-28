//heap.cpp
#include <cstdlib>
#include <malloc.h>
#include "iostream"

using namespace std;

const int maxNumber = 100;
int heap[maxNumber]={0,4,8,2,6,9,8,3,7};
int n = 10;

void downAdjust(int low, int high) {
    int i = low, j = i * 2;
    while (j <= high) {
        if (j + 1 <= high && heap[j + 1] > heap[j]) {
            j = j + 1;
        }

        if (heap[j] > heap[i]) {
            swap(heap[j], heap[i]);
            i = j;
            j = i * 2;
        } else {
            break;
        }
    }
}

//注意结点都是从1开始的
void createHeap() {
    for (int i = n / 2; i >= 1; --i) {
        downAdjust(i, n);
    }
}

void deleteTop() {
    for (int i = n / 2; i >= 1; --i) {
        heap[1] = heap[n--];
        downAdjust(1, n);
    }
}



void upAdjust(int low, int high) {
    int i = high, j = i / 2;
    while (j >= low) {
        if (j + 1 <= high && heap[j + 1] < heap[j]) {
            j = j + 1;
        }

        if (heap[j] < heap[i]) {
            swap(heap[j], heap[i]);
            i = j;
            j = i / 2;
        } else {
            break;
        }
    }
}

void insert(int x){
    heap[++n] = x;
    upAdjust(1, n);
}

void heapSort(){
    createHeap();
    for (int i = n; i >1 ; --i) {
        swap(heap[i], heap[1]);
        downAdjust(1, i - 1);
    }
}

int main(void) {

    for (int i = 1; i < 9; ++i) {
        cout << heap[i]<<" ";
    }
    cout<<endl;

    //heapSort();
    createHeap();

    for (int i = 1; i < 9; ++i) {
        cout << heap[i]<<" ";
    }
    cout<<endl;

    system("pause");
    return 0;
}



