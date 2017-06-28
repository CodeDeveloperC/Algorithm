//vector.cpp

#include <cstdlib>
#include <vector>
#include<string>
#include "iostream"

using namespace std;

int n;

string deal(string string1, int &e) {
    int k = 0;

    while (string1.length() > 0 && string1[0] == '0') {
        string1.erase(string1.begin());
    }

    if (string1[0] == '.') {
        string1.erase(string1.begin());
        while (string1.length() > 0 && string1[0] == '0') {
            string1.erase(string1.begin());
            e--;
        }
    }
    else {
        while (k < string1.length() && string1[k] != '.') {
            k++;
            e++;
        }

        if (k < string1.length()) {
            string1.erase(string1.begin() + k);
        }
    }

    if (string1.length() == 0) {
        e = 0;
    }

    int num = 0;
    k = 0;
    string res;

    while (num < n) {
        if (k < string1.length()) res += string1[k++];
        else res += '0';
        num++;
    }

    return res;
}

int main(void) {

    //vector<vector<int> > name;
    string string1, string2, string3, string4;
    cin >> n;
    cin >> string1;
    cin >> string2;
    int e1 = 0, e2 = 0;
    string3 = deal(string1, e1);
    string4 = deal(string2, e2);

    if (string3 == string4 && e1 == e2) {
        cout << "YES" << endl;
    }
    else {
        cout << "NO" << endl;
    }

    system("pause");
    return 0;
}



