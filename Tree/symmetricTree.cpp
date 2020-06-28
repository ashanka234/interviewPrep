/* check if tree is mirror of itself 
OR check if 2 trees are symmetric */
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

bool isMirror(Node *a, Node *b) {
    if(a==NULL && b==NULL)  //empty trees are symmetric
        return true;

    if(a->data == b->data && a!=NULL && b!=NULL) {
        return (isMirror(a->left, b->right) && isMirror(a->right, b->left));
    }

    return false;
}

int main() {
    Node *root        = newNode(1); 
    root->left        = newNode(2); 
    root->right       = newNode(2); 
    root->left->left  = newNode(3); 
    root->left->right = newNode(4); 
    root->right->left  = newNode(4); 
    root->right->right = newNode(3);

    cout << isMirror(root, root) << endl;

    return (0);
}