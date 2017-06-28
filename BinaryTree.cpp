//BinaryTree.cpp
#include <cstdlib>
#include <queue>
#include "iostream"

using namespace std;

struct Node {
    int data;
    Node *lchild;
    Node *rchild;
};


Node *newNode(int v) {
    Node *node = new Node;
    node->data = v;
    node->lchild = node->rchild = nullptr;

    return node;
}

void search(Node *root, int x, int newData) {
    if (root == nullptr) {
        return;
    }

    if (root->data == x) {
        root->data = newData;
    }

    search(root->lchild, x, newData);
    search(root->rchild, x, newData);
}

void insert(Node *&root, int x) {
    if (root == nullptr) {
        root = newNode(x);
        return;
    }

    if (root->lchild== nullptr || x < root->lchild->data) {
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

void preOrder(Node *root) {
    if (root == nullptr) {
        return;
    }

    cout << root->data << endl;
    preOrder(root->lchild);
    preOrder(root->rchild);
}

void inOrder(Node *root) {
    if (root == nullptr) {
        return;
    }

    inOrder(root->lchild);
    cout << root->data << endl;
    inOrder(root->rchild);
}

void posOrder(Node *root) {
    if (root == nullptr) {
        return;
    }

    posOrder(root->lchild);
    posOrder(root->rchild);
    cout << root->data << endl;
}

//层序遍历
void layerOrder(Node *root) {
    queue<Node *> queue1;
    queue1.push(root);
    while (!queue1.empty()) {
        Node *now = queue1.front();
        queue1.pop();

        cout << now->data << endl;
        if (now->lchild != nullptr) queue1.push(now->lchild);
        if (now->rchild != nullptr) queue1.push(now->rchild);
    }
}

int main(void) {

    Node *root = nullptr;
    int a[10] = {2, 6, 9, 8, 3, 4, 5, 7, 1};
    root = create(a, 9);

    cout << "preOrder" << endl;
    preOrder(root);
    cout << "inOrder" << endl;
    inOrder(root);
    cout << "posOrder" << endl;
    posOrder(root);
    cout << "layerOrder" << endl;
    layerOrder(root);
    cout << "search" << endl;
    search(root, 1, 100);
    layerOrder(root);

    system("pause");
    return 0;
}



