#include<iostream>
#include<cstring>
using namespace std;

struct Node{
    int data;
    Node *next;
};

void push(Node **head, int d) {
    Node *newNode = new Node;
    newNode->data  = d;
    newNode->next = *head;
    *head = newNode;
}

void printList(Node *head) {
    Node *temp = head;
    while(temp) {
        cout << temp->data << " ";
        temp = temp->next;
    }

    cout << endl;
}

void sort012(Node *head) {
    int count[3];
    memset(count, 0, sizeof(count));
    //cout << "reaching here" << endl;
    Node *temp = head;
    while(temp != NULL) {
        count[temp->data]++;
        temp = temp->next;
    }
    //cout << count[0] << count[1] << count[2] << endl;

    temp = head;
    for(int i=0; i<count[0]; i++) {
        temp->data = 0;
        temp = temp->next;
    }
    for(int i=0; i<count[1]; i++) {
        temp->data = 1;
        temp = temp->next;
    }
    for(int i=0; i<count[2]; i++) {
        temp->data = 2;
        temp = temp->next;
    }
}

int main() {

    Node *head = NULL;
    int n;
    cin >> n;

    while(n--) {
        int num;
        cin >> num;
        push(&head, num);
    }

    printList(head);
    sort012(head);
    printList(head);

    return (0);
}