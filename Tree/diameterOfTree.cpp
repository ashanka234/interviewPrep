#include<iostream>
#include<algorithm>
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

int height(Node *root) {
    if(root==NULL)
        return 0;

    return 1 + max(height(root->left), height(root->right));
}

int diameter(Node *root) {
    if(root==NULL)
        return 0;

    int lheight = height(root->left);
    int rheight = height(root->right);

    int ldiameter = diameter(root->left);
    int rdiameter = diameter(root->right);

    return max(lheight+rheight+1, max(ldiameter, rdiameter));
}

int main() {
    struct Node *root = newNode(1); 
    root->left        = newNode(2); 
    root->right       = newNode(3); 
    root->left->left  = newNode(4); 
    root->left->right = newNode(5); 

    cout << diameter(root) << endl;

    return (0);
}