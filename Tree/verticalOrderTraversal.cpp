#include<iostream>
using  namespace std;

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

void printVerticaLine(Node *root, int lineNumber, int hd) {
    //this method will print all the nodes lying on this particular vertical line
    if(root==NULL)
        return;

    if(hd == lineNumber)        //print this node
        cout << root->data << " ";

    printVerticaLine(root->left, lineNumber, hd-1);
    printVerticaLine(root->right, lineNumber, hd+1);
}

void getMinMax(Node *root, int *min, int *max, int hd) {
    if(root==NULL)
        return;

    if(hd>*max)
        *max = hd;

    if(hd<*min)
        *min = hd;

    getMinMax(root->left, min, max, hd-1);
    getMinMax(root->right, min, max, hd+1);
}

void verticalOrder(Node *root) {
    int min=0, max=0;
    getMinMax(root, &min, &max, 0);

    for(int i=min; i<=max; i++) {
        printVerticaLine(root, i, 0);
        cout << endl;
    }
}

int main() {
    Node *root = newNode(1); 
    root->left = newNode(2); 
    root->right = newNode(3); 
    root->left->left = newNode(4); 
    root->left->right = newNode(5); 
    root->right->left = newNode(6); 
    root->right->right = newNode(7); 
    root->right->left->right = newNode(8); 
    root->right->right->right = newNode(9); 

    verticalOrder(root);

    return (0);
}