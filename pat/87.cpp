#include <cstdlib>
#include <vector>
#include <algorithm>
#include "iostream"

using namespace std;

struct Student {
    int id;
    int dScore;
    int cScore;
};
vector<Student> vector2;
vector<Student> vector3;
vector<Student> vector4;
vector<Student> vector5;
vector<Student>::iterator iterator1;

bool cmp(Student a, Student b) {
    int c = a.cScore + a.dScore;
    int d = b.cScore + b.dScore;

    if (c > d) {
        return true;
    } else if (c == d) {
        if (a.dScore != b.dScore)
            return a.dScore > b.dScore;
        else
            return a.id < b.id;
    } else {
        return false;
    }
}

int main() {
    int n, l, h;
    int a, b, c;
    int num = 0;
    cin >> n >> l >> h;
    Student student;

    for (int i = 0; i < n; ++i) {
        cin >> a >> b >> c;
        student.id = a;
        student.dScore = b;
        student.cScore = c;

        if(b < l || c < l) continue;

        if (b >= h && c >= h) {
            vector2.push_back(student);
        } else if (b >= h) {
            vector3.push_back(student);
        } else if (b < h && c < h && b >= c) {
            vector4.push_back(student);
        } else {
            vector5.push_back(student);
        }
        num++;
    }

    sort(vector2.begin(), vector2.end(), cmp);
    sort(vector3.begin(), vector3.end(), cmp);
    sort(vector4.begin(), vector4.end(), cmp);
    sort(vector5.begin(), vector5.end(), cmp);
    cout<<num<<endl;

    for (iterator1 = vector2.begin(); iterator1 != vector2.end(); iterator1++) {
        cout<<(*iterator1).id<<" "<<(*iterator1).dScore<<" "<<(*iterator1).cScore<<endl;
    }

    for (iterator1 = vector3.begin(); iterator1 != vector3.end(); iterator1++) {
        cout<<(*iterator1).id<<" "<<(*iterator1).dScore<<" "<<(*iterator1).cScore<<endl;
    }

    for (iterator1 = vector4.begin(); iterator1 != vector4.end(); iterator1++) {
        cout<<(*iterator1).id<<" "<<(*iterator1).dScore<<" "<<(*iterator1).cScore<<endl;
    }

    for (iterator1 = vector5.begin(); iterator1 != vector5.end(); iterator1++) {
        cout<<(*iterator1).id<<" "<<(*iterator1).dScore<<" "<<(*iterator1).cScore<<endl;
    }


    system("pause");
    return 0;
}

