//MA
#include<iostream>
#include<algorithm>
#include<map>
#include<vector>
#include<string>
#include <sstream>

using namespace std;

int a[1010] = {0};

string Int_to_String(int n) {
    ostringstream stream1;
    stream1 << n;  //n为int类型
    return stream1.str();
}

int main() {
    int i;
    string line;
    string line1;
    string num2;
    string link;
    string text;
    string underLine;
    bool flag = false;
    bool flag2 = false;

    vector<string> vector1;

    vector<string>::iterator it;
    string::size_type pos1;
    string::size_type pos2;

    while (getline(cin, line)) {
        flag = false;
        int num = 1;
        if (line.find("#") != string::npos) {
            flag = true;
            pos1 = line.find("#");
            pos2 = line.rfind("#");
            line1 = line.substr(pos2 + 1, line.size() - pos2 - 1);

            for (string::iterator iterator1 = line1.begin(); iterator1 != line1.end(); iterator1++) {
                if (*iterator1 == ' ') line1.erase(iterator1);
                else break;
            }

            if (line1[0] == ' ')
                line1.erase(line1.begin());

            num += pos2 - pos1;
            num2 = Int_to_String(num);
            line = "<h" + (num2);
            line += ">";
            line += line1;
            line += "</h";
            line += num2;
            line += ">";
            vector1.push_back(line);
            continue;
        }

        if (line.find("*") != string::npos) {
            int t = vector1.size() + 1;
            a[t] = a[t - 1] + 1;
            flag = true;
            line1 = line.substr(1, line.size() - 1);

            for (string::iterator iterator1 = line1.begin(); iterator1 != line1.end(); iterator1++) {
                if (*iterator1 == ' ') line1.erase(iterator1);
                else break;
            }

            if (line1[0] == ' ')
                line1.erase(line1.begin());

            line = "<li>";
            line += line1;
            line += "</li>";
            vector1.push_back(line);
        }

        if (line.find("[") != string::npos) {
            flag = true;
            pos1 = line.find("(");
            pos2 = line.rfind(")");
            link = line.substr(pos1 + 1, pos2 - pos1 - 1);

            pos1 = line.find("[");
            pos2 = line.rfind("]");
            text = line.substr(pos1 + 1, pos2 - pos1 - 1);


            line = "<a href=\"";
            line += link;
            line += "\">";
            line += text;
            line += "</a>";

            vector1.push_back(line);
        }

        if (line.find("_") != string::npos) {
            pos1 = line.find("_");
            pos2 = line.find("_", pos1);
            underLine = line.substr(pos1 + 1, pos2 - pos1 - 1 - 1);

            line = "<em>";
            line += underLine;
            line += "</em>";

            vector1.push_back(line);
        }

        if (!flag) {
            underLine = line;
            if (line != "") {
                line = "<p>";
                line += underLine;
                line += "</p>";
            }
            vector1.push_back(line);
        }

    }

    for (it = vector1.begin(), i = 1; it != vector1.end(); it++, i++) {
        if (a[i] == 1) {
            cout << "<ul>" << endl;
            flag2 = true;
        }
        if (a[i] == 0 && flag2) {
            cout << "</ul>" << endl;
            flag2 = false;
        }
        cout << *it << endl;

    }
    system("pause");

    return 0;
}

