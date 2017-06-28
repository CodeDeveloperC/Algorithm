//Link.cpp
#include <cstdlib>
#include "iostream"

using namespace std;

struct Node {
    int data;
    Node *next;
};

Node *create(int *array) {
    Node *p, *pre, *head;
    head = new Node;
    head->next = nullptr;
    pre = head;
    for (int i = 0; i < 5; ++i) {
        p = new Node;
        p->data = array[i];
        p->next = nullptr;
        pre->next = p;
        pre = p;
    }

    return head;
}

void insert(Node *head, int pos, int x) {
    Node *p = head;
    for (int i = 0; i < pos - 1; ++i) {
        p = p->next;
    }

    Node *q = new Node;
    q->data = x;
    q->next = p->next;
    p->next = q;
}

void deleteNode(Node *head, int x) {
    Node *p = head->next;
    Node *pre = head;
    while (p != nullptr) {
        if (p->data == x) {
            pre->next = p->next;
            delete (p);
            p = pre->next;
        } else {
            pre = p;
            p = p->next;
        }
    }
}

int main(void) {
    int array[5] = {5, 3, 6, 1, 2};
    Node *L = create(array);
    L = L->next;
    while (L != nullptr) {
        cout << L->data << " ";
        L = L->next;
    }
    system("pause");
    return 0;
}



