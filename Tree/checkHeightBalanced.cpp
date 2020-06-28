#include<iostream>
#include<algorithm>
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

int height(Node *root) {
    if(root==NULL)
        return 0;

    return 1 + max(height(root->left), height(root->right));
}

bool isBalanced(Node *root) {
    //tree is balanced if height is same of left and right subtree
    //or height difference is 1
    
    if(root==NULL)
        return true;        //empty tree is balanced

    int lheight = height(root->left);
    int rheight = height(root->right);

    return (abs(lheight-rheight)<=1 && isBalanced(root->left) && isBalanced(root->right));
}

int main() {
    Node* root = newNode(1); 
    root->left = newNode(2); 
    root->right = newNode(3); 
    root->left->left = newNode(4); 
    root->left->right = newNode(5); 
    //root->left->left->left = newNode(8);

    cout << isBalanced(root) << "\n";

    return (0);
}