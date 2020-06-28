#include<iostream>
#include<queue>
#include<map>
using namespace std;

struct Node {
    int data;
    int hd;
    Node *left;
    Node *right;
};

Node *newNode(int d) {
    Node *temp = new Node;
    temp->data = d;
    temp->left = temp->right = NULL;
    
    return temp;
}

void printTopView(Node *root) {
    if(root==NULL)
        return;
    queue<Node *> q;
    map<int, int> m;
    int hd = 0;
    root->hd = hd;

    q.push(root);

    while(!q.empty()) {
        Node *curr = q.front();
        q.pop();
        hd = curr->hd;

        if(m.find(hd) == m.end())       //this hd is coming first time so add this node to top view
            m[hd] = curr->data;

        if(curr->left) {
            curr->left->hd = hd-1;
            q.push(curr->left);
        }
        if(curr->right) {
            curr->right->hd = hd+1;
            q.push(curr->right);
        }
    }

    map<int, int>::iterator it;
    for(it=m.begin(); it!=m.end(); it++) {
        cout << it->second << " ";
    }
}

int main() {
    Node* root = newNode(1); 
    root->left = newNode(2); 
    root->right = newNode(3); 
    root->left->right = newNode(4); 
    root->left->right->right = newNode(5); 
    root->left->right->right->right = newNode(6); 

    printTopView(root);
    cout << endl;

    return (0);  
}