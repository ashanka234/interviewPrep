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

int getHeight(Node *root) {
    if(root == NULL)
        return 0;       //height of empty tree is 0

    int leftHeight = getHeight(root->left);
    int rightHeight = getHeight(root->right);

    return (max(leftHeight, rightHeight) + 1);
}

int main() {
    Node *root = newNode(1);  
  
    root->left = newNode(2);  
    root->right = newNode(3);  
    root->left->left = newNode(4);  
    root->left->right = newNode(5); 

    cout << getHeight(root) << endl;

    return (0);
}