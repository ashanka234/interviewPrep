#include<iostream>
#include<stack>
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

void spiralLevelOrder(Node *root) {
    if(root == NULL)
        return;

    stack<Node *> s1;       //print right to left
    stack<Node *> s2;       //print left to right

    s1.push(root);

    while(!s1.empty() || !s2.empty()) {
        //print current level left to right
        //then push next level into s2 for right to left

        while(!s1.empty()) {
            Node *temp = s1.top();
            s1.pop();

            cout << temp->data << " ";

            //first push right, then left
            //because next level will be printed left to right 
            if(temp->right) 
                s2.push(temp->right);
            if(temp->left)
                s2.push(temp->left);
        }
        cout << endl;

        while(!s2.empty()) {
            Node *temp = s2.top();
            s2.pop();
            cout << temp->data << " ";

            //here push left first then right
            //because next level will be printed right to left
            if(temp->left)
                s1.push(temp->left);
            if(temp->right)
                s1.push(temp->right);
        }
        cout << endl;
    }
}

int main() {
    Node* root = newNode(1); 
    root->left = newNode(2); 
    root->right = newNode(3); 
    root->left->left = newNode(7); 
    root->left->right = newNode(6); 
    root->right->left = newNode(5); 
    root->right->right = newNode(4); 

    spiralLevelOrder(root);

    return (0);
}