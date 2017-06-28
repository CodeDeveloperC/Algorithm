//BST.cpp

#include <cstdlib>
#include <vector>
#include "iostream"

using namespace std;

const int maxn = 110;
struct Node {
    int data;
    int layer;
    Node *lchild;
    Node *rchild;
};

Node *newNode(int v) {
    Node *node = new Node;
    node->data = v;
    node->lchild = node->rchild = nullptr;

    return node;
}

void search(Node *root, int x) {
    if (root == nullptr) {
        cout << "search failed" << endl;
        return;
    }

    if (x == root->data) {
        cout << root->data << endl;
    } else if (x < root->data) {
        search(root->lchild, x);
    } else {
        search(root->rchild, x);
    }
}


void insert(Node *&root, int x) {
    if (root == nullptr) {
        root = newNode(x);
        return;
    }

    if (x == root->data) {
        return;
    } else if (x < root->data) {
        insert(root->lchild, x);
    } else {
        insert(root->rchild, x);
    }
}

Node *create(int *data, int n) {
    Node *root = nullptr;
    for (int i = 0; i < n; ++i) {
        insert(root, data[i]);
    }

    return root;
}

Node *findMax(Node *root) {
    while (root->rchild != nullptr) {
        root = root->rchild;
    }

    return root;
}

Node *findMin(Node *root) {
    while (root->lchild != nullptr) {
        root = root->lchild;
    }

    return root;
}

void deleteNode(Node *&root, int x) {
    if (root == nullptr) return;
    if (root->data == x) {
        if (root->lchild == nullptr && root->rchild == nullptr) {
            root = nullptr;
        } else if (root->lchild != nullptr) {
            Node *pre = findMax(root->lchild);
            root->data = pre->data;
            deleteNode(root->lchild, pre->data);
        } else {
            Node *next = findMin(root->rchild);
            root->data = next->data;
            deleteNode(root->rchild, next->data);
        }
    } else if (root->data > x) {
        deleteNode(root->lchild, x);
    } else {
        deleteNode(root->rchild, x);
    }
}


int main(void) {
    Node *root = nullptr;
    int a[10] = {2, 6, 9, 8, 3, 4, 5, 7, 1};
    root = create(a, 9);
    search(root, 9);
    deleteNode(root, 9);
    search(root, 9);

    system("pause");
    return 0;
}
