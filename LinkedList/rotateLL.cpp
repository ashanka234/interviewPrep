#include<iostream>
using namespace std;

struct Node {
    int data;
    Node *next;
};

void push(Node **head, int d) {
    Node *newNode = new Node;
    newNode->data = d;
    newNode->next = *head;
    *head = newNode;
}

void printList(Node *head) {
    if(head != NULL) {
        while(head)
        {
            cout << head-> data << " ";
            head = head->next;
        }
    }
    cout << endl;
}

void rotateList(Node **head, int k) {
    if(k==0)
        return;     //no rotation needed

    Node *curr = *head;     //iterator 
    int count=1;

    //reach till kth node
    while(count<k && curr!=NULL){
        curr = curr->next;
        count++;
    }

    if(curr==NULL)      //k is greater than length of node
        return;

    Node *kthNode = curr;       //kth node has been stored

    //now reach till end
    while(curr->next != NULL) {
        curr = curr->next;
    }

    //now we are at last node; join last node to first node till kth node
    curr->next = *head;

    //now list will start from (k+1)th node so that will be head
    *head = kthNode->next;

    //break link of kth node with rest. Now kth node will be last node
    kthNode->next = NULL;
}

int main() {
    Node *head = NULL;
    int n, k;
    cin >> n;

    while(n--) {
        int num;
        cin >> num ;
        push(&head, num);
    }
    cin >> k;       //rotate left by k places

    printList(head);
    rotateList(&head, k);
    printList(head);

    return (0);
}