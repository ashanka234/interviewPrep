#include<iostream>
#include<stack>
using namespace std;

struct Node {
    int data;
    Node *next;
};

void push(Node **head, int d) {
    Node *newNode = new Node;
    newNode->data =  d;
    newNode->next = *head;
    *head = newNode;
}

void printList(Node *head) {
    while(head) {
        cout << head->data << " ";
        head = head->next;
    }
}

bool isPalindrome(Node *head) {
    Node *curr = head;
    stack<int> s;

    //push all nodes to stack so the while popping it comes out in reverse order
    while(curr) {
        s.push(curr->data);
        curr = curr->next;
    }

    //now iterate list while popping from stack
    //if reverse order not equal to forward order then not palindrome
    curr = head;
    while(!s.empty()) {
        int d = s.top();
        s.pop();

        if(curr->data != d) {
            return false;
        }
        curr = curr->next;
    }
    return true;
}

int main() {
    int n;
    cin >> n;
    Node *head = NULL;

    while(n--) {
        int num;
        cin >> num;
        push(&head, num);
    }

    cout << isPalindrome(head) << endl;

    return (0);
}