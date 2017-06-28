//p357.cpp
#include <cstdlib>
#include <map>
#include "iostream"

using namespace std;

const int MAXV = 2010;
const int INF = 1000000000;
struct Gang {
    string head;
    int numMember;
} arrayGang[MAXV];
int numGang = 0;

map<int, string> intToString;
map<string, int> stringToInt;
map<string, int> Gang;
int graph[MAXV][MAXV] = {0};
int weight[MAXV] = {0};
int n, k, numPerson = 0;
bool vis[MAXV] = {false};


bool cmp(Gang a, Gang b) {
    return a.head < b.head;
}

void dfs(int nowVisit, int &head, int &numNumber, int &totalValue) {
    numNumber++;
    vis[nowVisit] = true;
    if (weight[nowVisit] > weight[head]) {
        head = nowVisit;
    }

    for (int i = 0; i < numPerson; ++i) {
        if (graph[nowVisit][i] > 0) {
            totalValue += graph[nowVisit][i];
            graph[nowVisit][i] = graph[i][nowVisit] = 0;
            if (!vis[i]) {
                dfs(i, head, numNumber, totalValue);
            }
        }
    }
}

void dfsTraverse() {
    for (int i = 0; i < numPerson; ++i) {
        if (!vis[i]) {
            int head = i, numMember = 0, totalValue = 0;
            dfs(i, head, numMember, totalValue);

            if (numMember > 2 && totalValue > k) {
                Gang[intToString[head]] = numMember;
            }
        }
    }
}

int change(string string1) {
    if (stringToInt.find(string1) != stringToInt.end()) {
        return stringToInt[string1];
    } else {
        stringToInt[string1] = numPerson;
        intToString[numPerson] = string1;
        return numPerson++;
    }
}

int main(void) {

    int w;
    string string1, string2;
    cin >> n >> k;
    for (int i = 0; i < n; ++i) {
        cin >> string1 >> string2 >> w;
        int id1 = change(string1);
        int id2 = change(string2);

        weight[id1] += w;
        weight[id2] += w;
        graph[id1][id2] += w;
        graph[id2][id1] += w;

    }

    dfsTraverse();

    cout << Gang.size() << endl;
    map<string, int>::iterator iterator1;
    for (iterator1 = Gang.begin(); iterator1 != Gang.end(); iterator1++) {
        cout << iterator1->first << " " << iterator1->second << endl;
    }

    system("pause");
    return 0;
}



