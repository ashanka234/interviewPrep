#include<iostream>
#include<queue>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;
};

Node *newNode(int d) {
    Node *temp = new Node;
    temp->left = temp->right = NULL;
    temp->data = d;

    return temp;
}

Node *insertValue(Node *root, int value, queue<Node *> &q) {
    Node *node = newNode(value);

    if(root==NULL)
        root = node;

    else if(q.front()->left == NULL)
        q.front()->left = node;
    else {
        q.front()->right = node;
        q.pop();        //pop root after inserting right child
    }

    q.push(node);
    return root;
}

Node *buildTree(int *arr, int n) {
    Node *root = NULL;
    queue<Node *> q;

    for(int i=0; i<n; i++) {
        root = insertValue(root, arr[i], q);
    }

    return root;
}

void inOrder(Node *root) {
    if(root == NULL)
        return;

    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
}

int main() {
    int n;
    cin >> n;
    int *arr = new int[n];
    for(int i=0; i<n; i++)
        cin >> arr[i];

    Node *root = buildTree(arr, n);

    inOrder(root); cout << endl;

    return (0);
}