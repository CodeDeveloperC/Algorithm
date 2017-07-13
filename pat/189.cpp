#include <cstdlib>
#include <vector>
#include "iostream"
#include<string>

using namespace std;
vector<bool> vector2;
int myArray[1000] = {0};
string string1;
string stringTemp1, stringTemp2;

bool check() {
    int a = 0, b = 0, c = 0;
    for (int j = 0; j < string1.length(); ++j) {
        if (string1[j] == 'P') a++;
        else if (string1[j] == 'A') b++;
        else if (string1[j] == 'T') c++;
        else
            return false;
    }
    if (a == 0 || b == 0 || c == 0 || a > 1 || c > 1) {
        return false;
    }
    return true;
}

bool first(string string2) {
    unsigned int pos = string2.find("PAT");
    if (pos != string::npos) {
        stringTemp1 = string2.substr(0, pos);
        stringTemp2 = string2.substr(pos + 3, pos);
        if (stringTemp1 == stringTemp2) {
            int j;
            for (j = 0; j < stringTemp1.length(); ++j) {
                if (string2[j] != 'A') {
                    return false;
                }
            }
            if (j == stringTemp1.length()) {
                return true;
            }
        }
    }
    return false;
}

bool third(string string2) {
    int pos1, pos2;
    pos1 = string1.find("P");
    pos2 = string1.find("T");
    if (pos1 == 0 && pos2 == string2.length() - 1) {
        for (int i = 1; i < string2.length() - 2; ++i) {
            if(string2[i]!='A')
                return false;
        }
    }
    return true;
}

bool second() {
    int pos1, pos2;
    pos1 = string1.find("P");
    pos2 = string1.find("T");
    stringTemp1 = string1.substr(0, pos1);
    stringTemp2 = string1.substr(pos2 + 1, string1.length() - pos1 - pos2 - 1);
    if (first(stringTemp2)) {
        return true;
    } else if (third(stringTemp2)) {
        return true;
    }else {
        return false;
    }
}

int main() {

    int n;


    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> string1;
        if (string1.length() < 3) continue;
        if (!check()) continue;
        if (first(string1)) {
            myArray[i] = 1;
            continue;
        }

        if (second()) {
            myArray[i] = 1;
        }

    }

    for (int i = 0; i < n; ++i) {
        if (myArray[i])
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }

    system("pause");
    return 0;
}

