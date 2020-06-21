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

Node *reverseList(Node *head) {
    if(head==NULL || head->next==NULL) 
        return head;

    Node *rest = reverseList(head->next);
    head->next->next = head;
    head->next = NULL;

    return rest;
}

//this method receives reversed list ie 7->6->5
int getNumber(Node *head) {
    int res = 0;
    while(head) {
        res = res*10 + head->data;
    }

    return res;
}

//5->6->7 is 765 ie order is units place first 
int addNumbers(Node *a, Node *b) {
    a = reverseList(a);
    //printList(a);
    b = reverseList(b);
    int n1 = getNumber(a);
    cout << "n1: " << n1 << endl;
    int n2 = getNumber(b);
    cout << "n2: " << n2 << endl;
    //cout << n1+n2 << endl;
    return n1+n2;
}

int main() {
    int n1, n2;
    Node *h1 = NULL;
    Node *h2 = NULL;

    cin >> n1;
    while(n1--){
        int num;
        cin >> num;
        push(&h1, num);
    }

    cin >> n2;
    while(n2--){
        int num;
        cin >> num;
        push(&h2, num);
    }

    printList(h1);
    printList(h2);

    cout << addNumbers(h1, h2) << endl;

    return (0);
}