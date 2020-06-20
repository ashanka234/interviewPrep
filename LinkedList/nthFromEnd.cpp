#include<iostream>
using namespace std;

struct Node{
    int data;
    Node *next;
};

void push(Node **head, int d) {
    Node *newNode = new  Node;
    newNode->data = d;
    newNode->next = *head;
    *head = newNode;
}

int getNthFromLast(Node *head, int n) {
    if(head == NULL)
        return -1;

    int len=1;
    Node *curr = head;
    while(curr)
    {
        len++;
        curr = curr->next;
    }
    if(n > len)
        return -1;

    Node *ptr1 = head;
    Node *ptr2 = head;

    while(n--) {
        ptr1 = ptr1->next;
    }

    while(ptr1 && ptr2) {
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }

    return ptr2->data;
}

int main() {
    int k, n;       //k is size
    Node *head = NULL;

    cin >> k;
   
    while(k--) {
        int num;
        cin >> num;
        push(&head, num);
    }

    cin >> n;       //nth from end wala n hai yeh

    cout << getNthFromLast(head, n) << endl;

    return (0);
}