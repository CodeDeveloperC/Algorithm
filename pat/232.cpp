#include <cstdlib>
#include <map>
#include <vector>
#include <string>
#include <algorithm>
#include "iostream"

using namespace std;

int main() {
    int n, k;
    map<string, vector<int> > map1;
    map<string, vector<int> >::iterator iterator1;
    vector<int> vector1;
    bool flag = 0;
    vector<string> vector2;
    string string1;
    cin >> n >> k;
    int a, b;
    for (int i = 0; i < k; ++i) {
        cin >> a >> b;
        for (int j = 0; j < b; ++j) {
            cin >> string1;
            map1[string1].push_back(a);
        }
    }

    for (int i = 0; i < n; ++i) {
        cin >> string1;
        vector2.push_back(string1);
    }
    for (int j = 0; j < vector2.size(); ++j) {
        for (iterator1 = map1.begin(); iterator1 != map1.end(); iterator1++) {
            if ((*iterator1).first == vector2[j]) {
                cout << (*iterator1).first << " " << (*iterator1).second.size();
                sort((*iterator1).second.begin(), (*iterator1).second.end());
                for (int i = 0; i < (*iterator1).second.size(); ++i) {
                    cout << " " << (*iterator1).second[i];
                }
                cout << endl;
                flag = 1;
                break;
            }
        }
        if (flag) {
            flag = 0;
        } else {
            cout << vector2[j] << " 0" << endl;
        }
    }

    system("pause");
    return 0;
}



