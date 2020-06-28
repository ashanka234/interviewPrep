#include<iostream>
#include<algorithm>
#include<climits>
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

//using this &res we will modify the res variable even though we are not returning any value
//the returned value is used for recursion purposes  ----> MEMORISE THIS
int maxPathSumUtil(Node *root, int &res) {
    if(root==NULL)  
        return 0;

    int l = maxPathSumUtil(root->left, res);
    int r = maxPathSumUtil(root->right, res);

    int max_single = max(max(l,r) + root->data, root->data);        //root data alone is greater or root data added to 
                                                                    //left or right sums
    int max_top = max(max_single, l+r+root->data);      //teeno ko milake ya fir root ke saath kisi ek side ka milake ya akele root ka
                                                        //4 possibilities are there - root alone, root+left, root+right,
                                                        //root+left+right
    res = max(res, max_top);

    return max_single;                                                           
}

int maxPathSum(Node *root) {
    int res = INT_MIN;

    maxPathSumUtil(root, res);

    return  res;
}

int main() {
    struct Node *root = newNode(10); 
    root->left        = newNode(2); 
    root->right       = newNode(10); 
    root->left->left  = newNode(20); 
    root->left->right = newNode(1); 
    root->right->right = newNode(-25); 
    root->right->right->left   = newNode(3); 
    root->right->right->right  = newNode(4);

    cout << maxPathSum(root) << endl;

    return (0);
}
