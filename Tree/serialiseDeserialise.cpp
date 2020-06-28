#include<iostream>
#include<cstdio>
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

void serialize(Node *root, FILE *fp) {
    if(root==NULL) {
        fprintf(fp, "%d ", -1);      //-1 represent NULL
        return;
    }

    //we are storing pre order traversal
    fprintf(fp, "%d ", root->data);
    serialize(root->left, fp);
    serialize(root->right, fp);
}

void deserialize(Node *&root, FILE *fp) {
    int val;
    fscanf(fp, "%d ", &val);

    if(!val || val==-1)
        return;

    root = newNode(val);
    deserialize(root->left, fp);
    deserialize(root->right, fp);
}

void printInorder(Node *root) {
    if(!root)
        return;

    printInorder(root->left);
    cout << root->data << " ";
    printInorder(root->right);
}

int main() {
    //create tree
    struct Node *root        = newNode(20); 
    root->left               = newNode(8); 
    root->right              = newNode(22); 
    root->left->left         = newNode(4); 
    root->left->right        = newNode(12); 
    root->left->right->left  = newNode(10); 
    root->left->right->right = newNode(14); 
    cout << "original: "; printInorder(root); cout << endl;


    FILE *fp = fopen("tree_input.txt", "w");
    if(fp == NULL) {
        //error in opening 
        cout << "error opening file\n";
        return 0;
    }
    serialize(root, fp);
    fclose(fp);

    Node *res = NULL;
    fp = fopen("tree_input.txt", "r");
    deserialize(res, fp);

    cout <<"from file: "; 
    printInorder(res);
    cout  << endl;

    return (0);
}