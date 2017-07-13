#include <cstdlib>
#include <set>
#include "iostream"
#include<string>
#include <vector>

using namespace std;

int main() {
    string string1, string2;
    vector<char> vector1;
    char s;
    cin >> string1 >> string2;
    int j = 0;
    bool flag = 0;
    for (int i = 0; i < string1.size();) {
        if (string1[i] == string2[j]) {
            i++;
            j++;
        } else {
            if (string1[i] > 'a' && string1[i] < 'z') {
                s = string1[i] - 'a' + 'A';
            } else {
                s = string1[i];
            }
            for (int k = 0; k < vector1.size(); ++k) {
                if (vector1[k] == s) {
                    flag = 1;
                    break;
                }
            }
            if (!flag) {
                vector1.push_back(s);
            }

            i++;
        }
    }

    for (vector<char>::iterator iterator1 = vector1.begin(); iterator1 != vector1.end(); iterator1++) {

        cout << (*iterator1);
    }

    system("pause");
    return 0;
}

