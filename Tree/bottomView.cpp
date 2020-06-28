#include<iostream>
#include<queue>
#include<climits>
#include<map>
using namespace std;

struct Node  {
    int data;
    int hd;     //horizontal distance
    Node *left;
    Node *right;
};

Node *newNode(int d) {
    Node *temp = new Node;
    temp->data = d;
    temp->hd = INT_MAX;
    temp->left = temp->right = NULL;

    return temp;
}

void bottomVieiw(Node *root) {
    if(root == NULL)
        return;

    int hd = 0;
    map<int, int> m;
    queue<Node *> q;

    root->hd = hd;
    q.push(root);

    while(!q.empty()) {
        Node *temp = q.front();
        q.pop();

        hd = temp->hd;

        //update the node for each horizontal distance. end mei sirf last wala reh jayega harr h.d. ke liye
        //bottom view is basically the last node in each horizontal distance
        m[hd] = temp->data;

        //now do level order traversal
        if(temp->left != NULL) {
            temp->left->hd = hd-1;      //left mei hd negative badhta hai
            q.push(temp->left);
        }

        if(temp->right != NULL) {
            temp->right->hd = hd+1;     //right mei  positive 
            q.push(temp->right);
        }
    }

    map<int, int>::iterator it;
    for(it=m.begin(); it!=m.end(); it++) {
        cout << it->second << " ";
    }
}

void inOrder(Node *root) {
    if(root == NULL)
        return;

    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
}

int main() {
    Node * root = newNode(20); 
    root -> left = newNode(8); 
    root -> right = newNode(22); 
    root -> left -> left = newNode(5); 
    root -> left -> right = newNode(3); 
    root -> right -> left = newNode(4); 
    root -> right -> right = newNode(25); 
    root -> left -> right -> left = newNode(10); 
    root -> left -> right -> right = newNode(14); 

    bottomVieiw(root);
    //inOrder(root);
    cout << endl;

    return (0);
}