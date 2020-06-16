#include<iostream>
using namespace std;

struct Node {
    int data;
    Node *next;
};

void push(Node **head, int d) {
    Node *new_node = new Node;
    new_node->data = d;

    new_node->next = *head;
    *head = new_node;
}

void printList(Node *head) {
    if(!head)
        return;

    while(head) {
        cout << head->data << " ";
        head = head->next;
    }

    cout << endl;
}


Node *reverseList(Node *head) {
    if(head==NULL || head->next==NULL)
        return head;

    Node *rest = reverseList(head->next);       //assume that rest of the list is automatically reversed. The 
                                                //the last node gets made head at base case
    
    head->next->next = head;    //head is last node now. Second node is now second last so connect second last to last ie head
    head->next = NULL;

    return rest;
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

    cout << "original list : ";
    printList(head);
    head = reverseList(head);
    cout << "reversed list : ";
    printList(head);

    return (0);
}