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
    while(head) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int getLength(Node *head) {
    int len = 1;

    while(head) {
        len++;
        head = head->next;
    }

    return len;
}

int getIntersectionUtil(int d, Node *head1, Node *head2) {
    Node *curr1 = head1;
    Node *curr2 = head2;

    //first make both equal length so move longer one ahead d places
    int i=0;
    while(i<d && curr1!=NULL) {
        if(curr1==NULL)
            return -1;

        i++;
        curr1 = curr1->next;
    }

    while(curr1 && curr2) {
        if(curr1 == curr2)
            return curr1->data;     //or curr2->data can also be returned

        curr1 = curr1->next;
        curr2 = curr2->next;
    }

    return -1;
}

int getIntersection(Node *head1, Node *head2) {
    int l1 = getLength(head1);
    int l2 = getLength(head2);

    if(l1>l2)
        return getIntersectionUtil(l1-l2, head1, head2);
    else
        return getIntersectionUtil(l2-l1, head2, head1);
}

int main() {

    Node *head1 = NULL;
    Node *head2 = NULL;

    //here linked list is Y shaped, means 2 heads and eventually merge into one list
    // 3->6->9->15->30
    push(&head1, 30);
    push(&head1, 15);
    push(&head1, 9);
    push(&head1, 6);
    push(&head1, 3);

    //10->15->30
    push(&head2, 10);
    head2->next = head1->next->next->next;

    cout << getIntersection(head1, head2) << endl;

    return (0);

}