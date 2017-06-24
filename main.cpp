#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cmath>

using namespace std;

void test1();

void memsetFunction();


void getchar_putchar();

void gets_puts();

void pointArray();

//挖掘机
void excavator();

void findElement();

void findElementExample();

void printSquare();

void differenceDate();

bool isLeapYear(int year);

void swap(int &a, int &b);

//回文串
void palindromeString();

void reverseString();

int main() {
    //memsetFunction();
    //getchar_putchar();
    // gets_puts();
    //pointArray();
    //excavator();

    //findElement();
    // findElementExample();
    //    while (1) {
    //        printSquare();
    //    }

    //differenceDate();

    // palindromeString();
    reverseString();

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

void findElement() {
    int n;
    int n1;
    const int x = 200;
    int myArray[x] = {0};

    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> myArray[i];
    }

    cin >> n1;
    for (int j = 0; j < n; ++j) {

        if (n1 == myArray[j]) {
            cout << j << endl;
            break;
        }
    }
}

void findElementExample() {
    const int maxn = 210;
    int a[maxn];
    int n, x;
    while (scanf("%d", &n) != EOF) {
        for (int i = 0; i < n; ++i) {
            cin >> a[i];//输入n个数
        }

        //输入查询的数
        cin >> x;
        //下标
        int j;
        for (j = 0; j < n; ++j) {
            if (a[j] == x) {
                cout << j << endl;
                break;

            }
        }

        if (j == n) {
            cout << -1 << endl;
        }
    }
}

void printSquare() {
    int n;
    char b;
    cin >> n >> b;
    n = (n % 2 == 0) ? n : n + 1;

    for (int i = 0; i < n - 2; ++i) {
        if (i == 0) {
            for (int j = 0; j < n; ++j) {
                cout << b;
            }
            cout << endl;
        }

        if (i % 2 == 0 && i != 0) {
            cout << b;
            for (int j = 1; j < n - 1; ++j) {
                cout << " ";
            }
            cout << b;
            cout << endl;
        }

        if (i % 2 == 1) {
            cout << endl;
        }

        //最后一行打印了两次
        if (i == n - 3) {
            for (int j = 0; j < n; ++j) {
                cout << b;
            }
            cout << endl;
        }

        cout << "i:---------------------------------------: " << i << endl;
    }
}

void differenceDate() {
    int day[13][2] = {
            {0,  0},
            {31, 31},
            {28, 29},
            {31, 31},
            {30, 30},
            {31, 31},
            {30, 30},
            {31, 31},
            {31, 31},
            {30, 30},
            {31, 31},
            {30, 30},
            {31, 31}
    };
    int ans = 1, time1, time2;
    int myYear, myMonth, myDay;
    int myYear2, myMonth2, myDay2;

    while (scanf("%d %d", &time1, &time2) != EOF) {
        if (time1 > time2) {
            swap(time1, time2);
        }
        myYear = time1 / 10000;
        myMonth = time1 % 10000 / 100;
        myDay = time1 % 100;

        myYear2 = time2 / 10000;
        myMonth2 = time2 % 10000 / 100;
        myDay2 = time2 % 100;

        while (myYear2 > myYear || myMonth2 > myMonth || myDay2 > myDay) {
            myDay++;

            if (myDay == day[myMonth][isLeapYear(myYear)] + 1) {
                myDay = 1;
                myMonth++;
            }

            if (myMonth == 13) {
                myMonth = 1;
                myYear++;
            }

            ans++;
        }

        cout << ans << endl;

    }


}

bool isLeapYear(int year) {
    return (year % 4 == 0 && year % 100 != 0 || year % 400 == 0) ? true : false;
}

void swap(int &a, int &b) {
    int temp;
    temp = a;
    a = b;
    b = temp;
}

//回文串
void palindromeString() {
    char str[256];
    while (gets(str) != NULL) {
        int n = strlen(str);
        bool flag = false;
        for (int i = 0; i < n / 2; ++i) {
            if (str[i] != str[n - i - 1]) {
                flag = true;
                break;

            }
        }

        if (flag) {
            cout << "NO!" << endl;
        } else {
            cout << "YES!" << endl;
        }
    }


}

void reverseString() {
    char str[90];
    gets(str);

    int len = strlen(str);
    int r = 0, h = 0;
    char ans[90][90];

    for (int i = 0; i < len; ++i) {
        if (str[i] != ' ')
            ans[r][h++] = str[i];
        else {
            ans[r][h] = '\0';
            r++;
            h = 0;
        }
    }
    ans[r][h] = '\0';//由于末尾没有空格，所以需要加上这句

    for (int j = r; j >= 0; --j) {
        cout << ans[j] << " ";
    }
}