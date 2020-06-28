#include<iostream>
using namespace std;

struct Node{
    int data;
    Node *left;     //will act as prev ptr
    Node *right;    //will act as next ptr
};

Node *newNode(int d) {
    Node *temp = new Node;
    temp->data = d;
    temp->left = temp->right = NULL;

    return temp;
}

void printList(Node *head) {
    while(head) {
        cout << head->data << " ";
        head = head->right;
    }
    cout << endl;
}

void treeToDLL(Node *root, Node **head) {
    if(!root)
        return;

    //V IMP to make this static cuz we need the same value in all recursive calls
    static Node *prev = NULL;

    //now we will use inorder traversal
    treeToDLL(root->left, head);

    if(prev==NULL)  //this is the topmost root
        *head = root;
    else
    {
        prev->right = root;
        root->left = prev;
    }

    prev = root;    //now root will be prev for the right subtree

    treeToDLL(root->right, head);
    
}

int main() {
    Node *head = NULL;

    Node *root        = newNode(10); 
    root->left        = newNode(12); 
    root->right       = newNode(15); 
    root->left->left  = newNode(25); 
    root->left->right = newNode(30); 
    root->right->left = newNode(36); 

    treeToDLL(root, &head);
    printList(head);

    return (0);
}