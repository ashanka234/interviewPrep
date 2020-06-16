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

void printList(Node *head) {
    if(head) {
        while(head != NULL) {
            cout << head->data << " ";
            head = head->next;
        }
    }
    cout << endl;
}

Node *reverseK(Node *head, int k) {
    Node *curr = head;
    Node *prev = NULL;
    Node *next = NULL;

    int count = 0;

    //reverse first k nodes
    while(count<k && curr!=NULL) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
        count++;
    }

    if(next != NULL)        //for last group
        head->next = reverseK(next, k);

    return prev;
}

int main() {
    int n,k;
    cin >> n;

    Node *head = NULL;

    while(n--) {
        int num;
        cin >> num;
        push(&head, num);
    }
    cin >> k;

    printList(head);
    head = reverseK(head, k);
    printList(head);

    return (0);
}