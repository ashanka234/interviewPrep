#include<iostream>
using namespace std;

struct QNode{
    int data;
    QNode *next;
    QNode(int d) {
        data = d;
        next = NULL;
    }
};

struct Queue {
    QNode *front, *rear;
    Queue() {
        front = rear = NULL;
    }

    void enqueue(int x) {
        QNode *temp = new QNode(x);

        if(rear == NULL) {
            front = rear = temp;
            return;
        }
        rear->next = temp;
        rear = temp;
    }

    void dequeue() {
        if(front == NULL)
            return;

        QNode *temp = front;
        front = front->next;

        if(front==NULL)
            rear = NULL;

        delete(temp);
    }
};

int main() {
    Queue q;

    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    cout << (q.front)->data << " " << (q.rear)->data << endl;

    return (0);
}