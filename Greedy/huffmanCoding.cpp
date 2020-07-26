/* Name question - commonly asked as is so memorize this code */

#include<iostream>
#include<queue>
using namespace std;

class HuffmanTreeNode {
public:
    char data;
    int freq;
    HuffmanTreeNode *left;
    HuffmanTreeNode *right;

    //constructor
    HuffmanTreeNode(char data, int freq) {
        this->data = data;
        this->freq = freq;
        left = right = NULL;
    }
};

//custom comparator for priority queue - IMPORTANT synatx
class Compare {
public:
    bool operator()(HuffmanTreeNode *a, HuffmanTreeNode *b) {
        return a->freq > b->freq;
    }
};

HuffmanTreeNode *generateTree(priority_queue<HuffmanTreeNode*, vector<HuffmanTreeNode*>, Compare> pq) {
    while(pq.size() != 1) {
        HuffmanTreeNode *left = pq.top();
        pq.pop();
        HuffmanTreeNode *right = pq.top();
        pq.pop();

        //new node is formed with freq = left->freq + right->freq, and then inserted into pq
        HuffmanTreeNode *newNode = new HuffmanTreeNode('$', left->freq+right->freq);
        newNode->left = left;
        newNode->right = right;

        pq.push(newNode);
    }

    return pq.top();
}

void printCodes(HuffmanTreeNode *root, int *arr, int top) {
    if(root->left) {
        arr[top] = 0;       //assign 0 to left child
        printCodes(root->left, arr, top+1);
    }
    if(root->right) {
        arr[top] = 1;       //assign 1 to right child
        printCodes(root->right, arr, top+1);
    }

    //if leaf node reached, then print the code for this character
    if(!root->left && !root->right) {
        cout << root->data << " ";
        for(int i=0; i<top; i++) 
            cout << arr[i];
        cout << endl;
    }
}

void HuffmanCodes(char *data, int *freq, int size) {
    priority_queue<HuffmanTreeNode*, vector<HuffmanTreeNode*>, Compare> pq;

    for(int i=0; i<size; i++) {
        HuffmanTreeNode *newNode = new HuffmanTreeNode(data[i], freq[i]);
        pq.push(newNode);
    }

    HuffmanTreeNode *root  = generateTree(pq);

    int arr[100], top=0;
    printCodes(root, arr, top);
}

int main() {

    char data[] = { 'a', 'b', 'c', 'd', 'e', 'f' }; 
    int freq[] = { 5, 9, 12, 13, 16, 45 }; 
    int size = sizeof(data) / sizeof(data[0]); 
  
    HuffmanCodes(data, freq, size); 
    
    return (0); 
}