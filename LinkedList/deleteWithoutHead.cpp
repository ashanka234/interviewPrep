#include<iostream>
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

//pointer to the node to be deleted is given
void deleteWithoutHead(Node *pos) {
    if(pos == NULL)
        return;

    if(pos->next == NULL) {     //it is last node, then not possible
        return;
    }

    Node *temp = pos->next;
    pos->data = pos->next->data;
    pos->next = pos->next->next;
    delete temp;
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
    deleteWithoutHead(head->next);
    printList(head);


    return (0);
}