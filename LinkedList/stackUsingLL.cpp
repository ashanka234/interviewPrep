#include<iostream>
using namespace std;

struct Node {
    int data;
    Node *next;
};

Node *top = NULL;

void push(int x) {
    Node *newNode = new Node;
    newNode->data = x;

    if(top==NULL) {
        newNode->next = NULL;
        top = newNode;
    }
    else {
        newNode->next = top;
        top = newNode;
    }
}

bool isEmpty() {
    return (top==NULL);
}

int peek() {
    return top->data;
}

void pop() {
    Node *temp = top;

    if(top==NULL)
        return;

    top = top->next;
    temp->next = NULL;
    delete temp;
}

void display() {
    if(top) {
        Node *temp = top;
        while(temp) {
            cout << temp->data << " ";
            temp = temp->next;
        }
    }

    cout << endl;
}

int main() {

    push(1);
    push(2);
    push(3);
    display();
    cout << peek() << endl;
    cout << isEmpty() << endl;
    pop();
    display();

    return (0);
}