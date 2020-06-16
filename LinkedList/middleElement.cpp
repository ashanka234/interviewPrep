#include<iostream>
using namespace std;

struct Node {
    int data;
    Node *next;
};

void push(Node **head, int data) {
    Node *new_node = new Node;
    new_node->data = data;

    new_node->next = *head;
    *head = new_node;
}

void printList(Node *head) {
    while(head) {
        cout << head->data << " ";
        head = head->next;
    }

    cout << endl;
}

int getMiddleElement(Node *head) {
    Node *slow, *fast;
    slow = head; fast = head;

    if(!head)
        return -1;

    while(slow && fast->next) {
        fast = fast->next->next;
        slow = slow->next;
    }

    return slow->data;
}

int main() {

    int n;
    cin >> n;
    Node *head = NULL;

    for(int i=0; i<n; i++) {
        int num;
        cin >> num;
        push(&head, num);
    }

    printList(head);

    cout << getMiddleElement(head) << endl;

    return (0);

}