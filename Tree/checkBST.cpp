#include<iostream>
#include<climits>
using namespace std;

struct Node  {
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

bool isBSTUtil(Node *root, int min, int max) {
    if(root == NULL)
        return true;        //empty tree is considered  a bst

    //node should not be greater than max for left subtree
    //or less than min for right subtree
    if(root->data>max || root->data<min) 
        return false;

    return isBSTUtil(root->left, min, root->data-1) 
        && isBSTUtil(root->right, root->data+1, max);       //basically min and max are fixing the range for the next nodes
}

bool isBST(Node *root) {
    return isBSTUtil(root, INT_MIN, INT_MAX);
}

int main() {
    Node *root = newNode(4);
    root->left = newNode(2);
    root->right = newNode(5);
    root->left->right = newNode(3);
    root->right->right = newNode(7);

    cout << isBST(root) << endl;

    return (0);
}