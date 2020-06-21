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

void pairwiseSwap(Node *head) {
    if(head != NULL && head->next!=NULL) {      //there should be atleast 2 nodes in list
        swap(head->data, head->next->data);
        pairwiseSwap(head->next->next);
    }
}

int main() {
    Node *head = NULL;
    int n;
    cin >> n;

    while(n--)
    {
        int num;
        cin >> num;
        push(&head, num);
    }

    printList(head);

    pairwiseSwap(head);
    printList(head);

    return (0);
}