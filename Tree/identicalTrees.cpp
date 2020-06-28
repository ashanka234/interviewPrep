#include<iostream>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;
};

Node *newNode(int d) {
    Node *temp = new Node;
    temp->data = d;
    temp->left = temp->right = NULL;

    return temp;
}

bool checkIdentical(Node *root1, Node *root2) {
    if(root1==NULL & root2==NULL)
        return true;

    if(root1==NULL || root2==NULL)
        return false;

    return (root1->data==root2->data && checkIdentical(root1->left, root2->left)
        && checkIdentical(root1->right, root2->right));
}

int main() {
    Node *root1 = newNode(1);  
    Node *root2 = newNode(1);  
    root1->left = newNode(2);  
    root1->right = newNode(3);  
    root1->left->left = newNode(4);  
    root1->left->right = newNode(5);  
  
    root2->left = newNode(2);  
    root2->right = newNode(3);  
    root2->left->left = newNode(4);  
    root2->left->right = newNode(5); 

    cout << checkIdentical(root1, root2) << endl;

    return (0);
}