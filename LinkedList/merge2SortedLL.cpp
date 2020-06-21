#include<iostream>
using namespace std;

struct Node {
    int data;
    Node *next;
};

void push(Node **head, int d) {
    Node *newNode = new Node;
    newNode->data = d;
    newNode->next = *head;
    *head = newNode;
}

void  printList(Node *head) {
    if(head != NULL) {
        while(head != NULL) {
            cout << head->data << " ";
            head = head->next;
        }
    }  
    cout << endl;
}

Node *sortedMerge(Node *a, Node *b) {
    if(a==NULL)
        return b;
    if(b==NULL)
        return a;

    Node *res = NULL;

    if(a->data < b->data) {
        res = a;
        res->next = sortedMerge(a->next, b);
    }
    else {
        res = b;
        b->next = sortedMerge(a, b->next);
    }

    return res;
}

int main() {

    int n1, n2;
    Node *h1 = NULL;
    Node *h2 = NULL;
    
    cin >> n1;
    while(n1--) {
        int num;
        cin >> num;
        push(&h1, num);
    }

    cin >> n2;
    while(n2--) {
        int num;
        cin >> num;
        push(&h2, num);
    }

    printList(h1);
    printList(h2);

    Node *mergedList = sortedMerge(h1, h2);

    printList(mergedList);

    return (0);
}