//BalanceTree.cpp
#include <cstdlib>
#include "iostream"
#include "algorithm"

using namespace std;

struct Node {
    int data;
    int vWeight, height;//vWeight权值
    Node *lchild, *rchild;
};

Node *newNode(int v) {
    Node *node = new Node;
    node->vWeight = v;
    node->height = 1;
    node->lchild = node->rchild = nullptr;
    return node;
}

int getHeight(Node *root) {
    if (root == nullptr) {
        return 0;
    }

    return root->height;
}

int getBalanceFactor(Node *root) {
    if (root == nullptr) {
        return 0;
    }
    return getHeight(root->lchild) - getHeight(root->rchild);
}

void updateHeight(Node *root) {
    root->height = max(getHeight(root->lchild), getHeight(root->rchild)) + 1;
}

void search(Node *root, int x) {
    if (root == nullptr) {
        cout << "search failed" << endl;
        return;
    }

    if (root->vWeight == x) {
        cout << root->vWeight << endl;
    } else if (x < root->vWeight) {
        search(root->lchild, x);
    } else {
        search(root->rchild, x);
    }
}

void leftRotation(Node *&root) {
    Node *temp = root->rchild;
    root->rchild = temp->lchild;
    temp->lchild = root;
    updateHeight(root);
    updateHeight(temp);
    root = temp;
}


void rightRotation(Node *&root) {
    Node *temp = root->lchild;
    root->lchild = temp->rchild;
    temp->rchild = root;
    updateHeight(root);
    updateHeight(temp);
    root = temp;
}

void insert(Node *&root, int v) {
    if (root == nullptr) {
        root = newNode(v);
        return;
    }

    if (v < root->vWeight) {
        insert(root->lchild, v);
        updateHeight(root);
        if (getBalanceFactor(root) == 2) {
            if (getBalanceFactor(root->lchild) == 1) {
                rightRotation(root);
            } else if (getBalanceFactor(root->lchild) == -1) {
                leftRotation(root->lchild);
                rightRotation(root);
            }
        }
    } else {
        insert(root->rchild, v);
        updateHeight(root);
        if (getBalanceFactor(root) == -2) {
            if (-1 == getBalanceFactor(root->rchild)) {
                leftRotation(root);
            } else if (1 == getBalanceFactor(root->rchild)) {
                rightRotation(root->rchild);
                leftRotation(root);
            }
        }
    }
}


Node *create(int *data, int n) {
    Node *root = nullptr;
    for (int i = 0; i < n; ++i) {
        insert(root, data[i]);
    }

    return root;
}

void preOrder(Node *root) {
    if (root == nullptr) {
        return;
    }

    cout << root->vWeight << endl;
    preOrder(root->lchild);
    preOrder(root->rchild);
}

int main(void) {

    Node *root = nullptr;
    int a[10] = {2, 6, 9, 8, 3, 4, 5, 7, 1};
    root = create(a, 9);
    preOrder(root);
    search(root, 9);

    system("pause");
    return 0;
}



