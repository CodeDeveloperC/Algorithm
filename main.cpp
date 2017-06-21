#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>

using namespace std;

void test1();

void memsetFunction();


void getchar_putchar();

void gets_puts();

void pointArray();

//挖掘机
void excavator();

int main() {
    //memsetFunction();
    //getchar_putchar();
    // gets_puts();
    //pointArray();
    excavator();
    system("pause");
    return 0;
}


void test1() {
    int n, count = 0;
    cin >> n;
    while (1) {
        if (n == 1) {
            break;
        }
        count++;
        if (n % 2 == 0) {
            n /= 2;
        } else {
            n = (3 * n + 1) / 2;
        }

    }
    cout << count << endl;
}

void memsetFunction() {
    int a[5] = {1, 2, 3, 4, 5};
    //赋值
    memset(a, 0, sizeof(a));
    for (int i = 0; i < 5; ++i) {
        cout << a[i] << " ";
    }
    cout << endl;

    memset(a, -1, sizeof(a));
    for (int i = 0; i < 5; ++i) {
        cout << a[i] << " ";
    }
    cout << endl;

    memset(a, 1, sizeof(a));
    for (int i = 0; i < 5; ++i) {
        cout << a[i] << " ";
    }
    cout << endl;
}

void getchar_putchar() {
    char str[5][5];
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            str[i][j] = getchar();
        }
        getchar();//这句是为了把输入中每行末尾的换行符吸收掉
    }

    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            putchar(str[i][j]);
        }
        putchar('\n');
    }
}

void gets_puts() {
    char str1[20];
    char str2[5][10];
    gets(str1);
    for (int i = 0; i < 3; ++i) {
        gets(str2[i]);
    }
    puts(str1);
    for (int i = 0; i < 3; ++i) {
        puts(str2[i]);
    }
}

void pointArray() {
    int a[10];
    for (int i = 0; i < 3; ++i) {
        scanf("%d", a + i);//必须用scanf
    }

    for (int i = 0; i < 3; ++i) {
        cout << *(a + i) << " ";
    }
}

//挖掘机
void excavator() {
    const int maxn = 100010;
    int n;//人数
    int number, score;
    int max = 0;
    int school[maxn] = {0};
    cin >> n;

    for (int i = 0; i < n; ++i) {
        cin >> number;
        cin >> score;
        school[number] += score;
    }

    for (int i = 0; i < n; ++i) {
        if (school[i] > max) {
            max = school[i];
            number = i;
        }
    }

    cout << number << ": " << max;


}