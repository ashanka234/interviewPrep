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

    void leftViewUtil(Node *root, int level, int *maxLevel) {
        //we have to print the first node of each level

        if(root == NULL)
            return;

        if(level > *maxLevel) {     //means started new level and this is the first of that level
            cout << root->data << " ";
            *maxLevel = level;
        }

        leftViewUtil(root->left, level+1, maxLevel);
        leftViewUtil(root->right, level+1, maxLevel);
    }

    void leftView(Node *root) {
        int maxLevel = 0;
        leftViewUtil(root, 1, &maxLevel);
    }


int main() {
    Node *root = newNode(12);
    root->left = newNode(10); 
    root->right = newNode(30); 
    root->right->left = newNode(25); 
    root->right->right = newNode(40);

    leftView(root);
    cout <<endl;

    return (0);
}   