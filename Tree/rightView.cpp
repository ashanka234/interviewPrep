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

//this is the same as left view, except that the level change we are seeing for right subtree first
//so all the right most nodes will get printed
void printRightViewUtil(Node *root, int level, int *maxLevel) {
    if(root == NULL)
        return;

    if(level > *maxLevel)        //means its the last node of current level
    {
        cout << root->data << " ";
        *maxLevel = level;      //new level started
    }

    //V IMP first recur for right then for left
    printRightViewUtil(root->right, level+1, maxLevel);
    printRightViewUtil(root->left, level+1, maxLevel);
}

void printRightView(Node *root) {
    int maxLevel = 0;
    printRightViewUtil(root, 1, &maxLevel);
}

int main() {
    struct Node *root = newNode(1); 
    root->left = newNode(2); 
    root->right = newNode(3); 
    root->left->left = newNode(4); 
    root->left->right = newNode(5); 
    root->right->left = newNode(6); 
    root->right->right = newNode(7); 
    root->right->left->right = newNode(8);

    printRightView(root);
    cout << endl;

    return (0);
}