#include <cstdlib>
#include <time.h>
#include <cstring>
#include <algorithm>
#include "iostream"

using namespace std;

const int maxn = 10;
int n = 10;
int array[maxn] = {0};

struct Student {
    char id[15];//准考证号
    int score;//分数
    int local_number;//考场号
    int local_rank;//考场内排名
} student[100010];

//选择排序
void selectSort();

//插入排序
void insertSort();

//初始化
void initial();

//打印
void printArray();

//比较函数
bool cmp(Student a, Student b);

//考场
void testee();

int main(void) {

    initial();
    // selectSort();
    //insertSort();
    testee();
    printArray();

    system("pause");
    return 0;
}

//选择排序
void selectSort() {
    for (int i = 0; i < n; ++i) {
        int k = i;
        for (int j = i; j < n; ++j) {
            if (array[j] < array[k]) {
                k = j;
            }
        }

        //交换数据
        int temp = array[i];
        array[i] = array[k];
        array[k] = temp;
    }
}

void initial() {
    srand((unsigned) time(NULL));
    for (int i = 0; i < maxn; ++i) {
        array[i] = rand() % 20;
    }
}

//打印
void printArray() {
    for (int i = 0; i < maxn; ++i) {
        cout << array[i] << " ";
    }
    cout << endl;
}

//插入排序
void insertSort() {
    for (int i = 1; i < n; ++i) {
        int temp = array[i];
        int j = i;

        while (j > 0 && temp < array[j - 1]) {
            array[j] = array[j - 1];
            j--;
        }

        array[j] = temp;
    }
}

//比较函数
bool cmp(Student a, Student b) {
    if (a.score != b.score) return a.score > b.score;
    else
        return strcmp(a.id, b.id) < 0;
}

//考场
void testee() {
    int n, k, num = 0;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> k;
        for (int j = 0; j < k; ++j) {
            cin >> student[num].id >> student[num].score;
            student[num].local_number = i + 1;
            num++;
        }

        sort(student + num - k, student + num, cmp);
        student[num - k].local_rank = 1;

        for (int l = num - k + 1; l < num; ++l) {
            if (student[l].score == student[l - 1].score) {
                student[l].local_rank = student[l - 1].local_rank;
            } else {
                student[l].local_rank = l + 1 - (num - k);
            }
        }
    }

    cout << "总考生数: " << num << endl;
    sort(student, student + num, cmp);

    int r = 1;
    for (int m = 0; m < num; ++m) {
        if (m > 0 && student[m].score != student[m - 1].score) {
            r = m + 1;
        }

        cout << student[m].id;
        cout << "排名: " << r << " " << student[m].local_number << " " << student[m].local_rank << endl;
    }
}
