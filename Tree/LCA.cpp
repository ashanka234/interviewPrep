#include<iostream>
using namespace std;

struct Node{
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

Node *findLCA(Node *root, int n1, int n2) {
    //this method will check  if current node is LCA of n1 and n2
    if(root == NULL)
        return NULL;

    if(root->data==n1 || root->data==n2)
        return root;

    Node *leftLCA = findLCA(root->left, n1, n2);
    Node *rightLCA = findLCA(root->right, n1, n2);

    if(leftLCA && rightLCA)     //this is the LCA
        return root;

    return (leftLCA != NULL)? leftLCA : rightLCA;
}

int main() {
    Node * root = newNode(1); 
    root->left = newNode(2); 
    root->right = newNode(3); 
    root->left->left = newNode(4); 
    root->left->right = newNode(5); 
    root->right->left = newNode(6); 
    root->right->right = newNode(7);

    cout << findLCA(root, 4, 5)->data << endl;
    cout << findLCA(root, 4, 3)->data << endl;

    return (0);
}