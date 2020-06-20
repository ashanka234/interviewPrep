/* Its a linked list of linked lists
    each node has a head to a full  list. the head  is called 'down'
    We have to sort all the elements of all lists 
*/

#include<iostream>
using namespace std;

struct Node {
    int data;
    Node *right;
    Node *down;
};

void push(Node **head, int d) {     //this method is for building the down direction list
    Node *newNode = new Node;
    newNode->right = NULL;

    newNode->data = d;
    newNode->down = *head;
    *head = newNode;
}

void printVerticalList(Node *node) {
    while(node) {
        cout << node->data << " ";
        node = node->down;
    }
}

 Node *merge(Node *a, Node *b) {        //this function is like merging 2 lists/arrays
    if(a == NULL)
        return b;
    if(b == NULL)
        return a;

    Node *res = NULL;
    if(a->data < b->data) {
        res = a;
        res->down = merge(a->down, b);
    }
    else {
        res = b;
        res->down = merge(a, b->down);
    }

    res->right = NULL;
    return res;
 }

 Node *flatten(Node *root) {
     if(root==NULL || root->right==NULL) {
         return root;
     }

     return merge(root, flatten(root->right));
 }

 int main() {
      Node* root = NULL; 
  
    /* Let us create the following linked list 
       5 -> 10 -> 19 -> 28 
       |    |     |     | 
       V    V     V     V 
       7    20    22    35 
       |          |     | 
       V          V     V 
       8          50    40 
       |                | 
       V                V 
       30               45 
    */
    push( &root, 30 ); 
    push( &root, 8 ); 
    push( &root, 7 ); 
    push( &root, 5 ); 
  
    push( &( root->right ), 20 ); 
    push( &( root->right ), 10 ); 
  
    push( &( root->right->right ), 50 ); 
    push( &( root->right->right ), 22 ); 
    push( &( root->right->right ), 19 ); 
  
    push( &( root->right->right->right ), 45 ); 
    push( &( root->right->right->right ), 40 ); 
    push( &( root->right->right->right ), 35 ); 
    push( &( root->right->right->right ), 20 );

    root = flatten(root);

    printVerticalList(root);
    cout << endl;

    return (0);
 }