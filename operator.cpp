//operator.cpp
#include "cstdio"
#include <cstdlib>
#include <stack>
#include <queue>
#include <map>
#include<string>
#include "iostream"


using namespace std;

struct Node {
    double num;
    char op;
    bool flag;
};

string str;
stack<Node> stack1;
queue<Node> queue1;
map<char, int> op;

void change() {
    double num;
    Node temp;
    for (int i = 0; i < str.length();) {
        if (str[i] >= '0' && str[i] <= '9') {
            temp.flag = true;
            temp.num = str[i++] - '0';
            while (i < str.length() && str[i] >= '0' && str[i] <= '9') {
                temp.num = temp.num * 10 + (str[i] - '0');
                i++;
            }

            queue1.push(temp);
        } else {
            temp.flag = false;
            while (!stack1.empty() && op[str[i]] <= op[stack1.top().op]) {
                queue1.push((Node &&) stack1.top());
                stack1.pop();
            }

            temp.op = str[i];
            stack1.push(temp);
            i++;
        }

        while (!stack1.empty()) {
            queue1.push((Node &&) stack1.top());
            stack1.pop();
        }
    }

    queue<Node> queueTemp = queue1;
    stack<Node> stackTemp = stack1;

    while (!queueTemp.empty()) {
        if (queueTemp.front().flag) {
            cout << queueTemp.front().num << " ";
        } else {
            cout << queueTemp.front().op << " ";
        }

        queueTemp.pop();
    }

    cout << endl;
}

double cal() {
    double temp1, temp2;
    Node cur, temp;
    while (!queue1.empty()) {
        cur = queue1.front();
        queue1.pop();
        if (cur.flag == true) {
            stack1.push(cur);
        } else {
            temp2 = stack1.top().num;
            stack1.pop();
            temp1 = stack1.top().num;
            stack1.pop();
            temp.flag = true;
            if (cur.op == '+') {
                temp.num = temp1 + temp2;
            } else if (cur.op == '-') {
                temp.num = temp1 - temp2;
            } else if (cur.op == '*') {
                temp.num = temp1 * temp2;
            } else {
                temp.num = temp1 / temp2;
            }
            stack1.push(temp);
        }
    }

    return stack1.top().num;
}

int main(void) {

    op['+'] = op['-'] = 1;
    op['*'] = op['/'] = 2;

    //    while (getline(cin, str), str != "0") {
    //        for (string::iterator it = str.end(); it != str.begin(); it--) {
    //            if (*it == ' ') str.erase();
    //        }
    //
    //        while (!stack1.empty()) {
    //            stack1.pop();
    //            change();
    //            cout << cal() << endl;
    //        }
    //    }


    str = "1+3*5/4*8/9*6*2/3/7+3*8/2";

    for (string::iterator it = str.end() - 1; it != str.begin(); it--) {
        if (*it == ' ') str.erase();
    }

    while (!stack1.empty()) {
        stack1.pop();
    }

    change();

    queue<Node> queueTemp = queue1;
    stack<Node> stackTemp = stack1;

    while (!queueTemp.empty()) {
        if (queueTemp.front().flag) {
            cout << queueTemp.front().num << " ";
        } else {
            cout << queueTemp.front().op << " ";
        }

        queueTemp.pop();
    }

    cout << endl;

    while (!stackTemp.empty()) {
        if (stackTemp.top().flag) {
            cout << stackTemp.top().num << " ";
        } else {
            cout << stackTemp.top().op << " ";
        }

    }

    cout << endl;

    cout << cal() << endl;

    system("pause");
    return 0;
}



