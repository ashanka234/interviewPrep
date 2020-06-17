//FLOYD'S CYCLE DETECTION ALGO
//Proof is important 

#include<iostream>
using namespace std;

struct Node{
    int data;
    Node *next;
};

void push(Node **head, int d) {
    Node *newNode = new Node;
    newNode->data = d;
    newNode->next = *head;
    *head = newNode;
}

void removeLoop(Node *loopNode, Node *head) {
    Node *ptr1 = loopNode;
    Node *ptr2 = loopNode;

    int k=1;
    while(ptr1->next != ptr2) {     //count the length of loop
        k++;
        ptr1 = ptr1->next;
    }

    ptr1 = head;
    ptr2 = head;

    while(k--) {
        ptr2 = ptr2->next;      //move one ptr k nodes ahead of head
    }

    //now move both at same speed, they will meet at loop node
    while(ptr1 != ptr2) {
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }

    //now reach last node before loop node
    while(ptr2->next != ptr1) {
        ptr2 = ptr2->next;
    }

    //break the link to loop
    ptr2->next = NULL;
}

bool detectLoop(Node *head) {
    Node *slowPtr = head;
    Node *fastPtr = head;

    while(slowPtr && fastPtr && fastPtr->next) {
        slowPtr = slowPtr->next;
        fastPtr = fastPtr->next->next;

        if(slowPtr == fastPtr)
        {
            removeLoop(slowPtr, head);
            return true;        //loop found
        }
    }

    return false;
}

int main() {

    Node *head = NULL;
    push(&head, 20);
    push(&head, 4);
    push(&head, 15);
    push(&head, 10);

    head->next->next->next->next = head;        //loop 

    cout << detectLoop(head) << endl;

    while(head) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;

    return (0);
}