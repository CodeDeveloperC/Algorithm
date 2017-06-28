//p317.cpp
#include <cstdlib>
#include <vector>
#include "iostream"

using namespace std;

struct Node {
    int data;
    Node *left, *right;
};

void insert(Node *&root, int data) {
    if (root == nullptr) {
        root = new Node;
        root->data = data;
        root->left = root->right = nullptr;
        return;
    }

    if (data < root->data) {
        insert(root->left, data);
    } else {
        insert(root->right, data);
    }
}

void preOrder(Node *root, vector<int> &vi) {
    if (root == nullptr) return;
    vi.push_back(root->data);
    preOrder(root->left, vi);
    preOrder(root->right, vi);
}

void preOrderMirror(Node *root, vector<int> &vi) {
    if (root == nullptr) return;
    vi.push_back(root->data);
    preOrderMirror(root->right, vi);
    preOrderMirror(root->left, vi);
}

void posOrder(Node *root, vector<int> &vi) {
    if (root == nullptr) return;
    posOrder(root->left, vi);
    posOrder(root->right, vi);
    vi.push_back(root->data);
}


void posOrderMirror(Node *root, vector<int> &vi) {
    if (root == nullptr) return;
    posOrderMirror(root->right, vi);
    posOrderMirror(root->left, vi);
    vi.push_back(root->data);
}

vector<int> origin, pre, preM, pos, posM;

int main(void) {

    int n, data;
    Node *root = nullptr;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> data;
        origin.push_back(data);
        insert(root, data);
    }

    preOrder(root, pre);
    preOrderMirror(root, preM);
    posOrder(root, pos);
    posOrderMirror(root, posM);

    if (origin == pre) {
        cout << "YES" << endl;
        for (int i = 0; i < pre.size(); ++i) {
            cout << pre[i];
            if (i < pre.size() - 1) {
                cout << " ";
            }
        }
    } else if (origin == preM) {
        cout << "YES" << endl;
        for (int i = 0; i < preM.size(); ++i) {
            cout << preM[i];
            if (i < preM.size() - 1) {
                cout << " ";
            }
        }
    } else {
        cout << "NO" << endl;
    }

    system("pause");

    return 0;
}



