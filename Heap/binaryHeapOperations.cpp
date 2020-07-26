/* often asked in interviews to implement or explain heap operations */

#include<iostream>
#include<climits>
using namespace std;

void swap(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

class MinHeap {
    int *harr;
    int capacity;
    int heap_size;

public:
    MinHeap(int capacity) {
        this->capacity = capacity;
        heap_size = 0;
        harr = new int[capacity];
    }

    int parent(int i) {
        return (i-1)/2;
    }

    void minHeapify(int i);
    int left(int i) { return 2*i+1; }

    int right(int i) { return 2*i + 2; }

    int extractMin();
    void decreaseKey(int i, int val);

    int getMin() { return harr[0]; }        //this method will just display the min element

    void deleteKey(int i);
    void insertKey(int k);
};

void MinHeap::insertKey(int k) {
    if(heap_size == capacity)       //overflow
        return;

    heap_size++;
    int i = heap_size - 1;
    harr[i] = k;

    while(i!=0 && harr[parent(i)] > harr[i]) {
        swap(&harr[i], &harr[parent(i)]);
        i = parent(i);
    }
}

void MinHeap::decreaseKey(int i, int new_val) {
    harr[i] = new_val;
    while(i!=0 && harr[parent(i)] > harr[i]) {
        swap(&harr[i], &harr[parent(i)]);
        i = parent(i);
    }
}


//this method will remove the min element from heap
int MinHeap::extractMin() {
    if(heap_size<=0)
        return INT_MAX;

    if(heap_size == 1) {
        heap_size--;
        return harr[0];
    }

    int root = harr[0];
    harr[0] = harr[heap_size-1];
    heap_size--;
    minHeapify(0);

    return root;
}

void MinHeap::deleteKey(int i) {
    decreaseKey(i, INT_MIN);
    extractMin();
}


//most imp ques - explain heapfiy operation of min heap
void MinHeap::minHeapify(int i) {
    int l = left(i);
    int r = right(i);
    int smallest = i;

    if(l<heap_size && harr[l]<harr[i]) 
        smallest = l;
    if(r<heap_size && harr[r]<harr[smallest]) 
        smallest = r;

    if(smallest != i) {
        swap(&harr[i], &harr[smallest]);
        minHeapify(smallest);
    }
}

int main() {
    MinHeap h(11);
    h.insertKey(3); 
    h.insertKey(2); 
    h.deleteKey(1); 
    h.insertKey(15); 
    h.insertKey(5); 
    h.insertKey(4); 
    h.insertKey(45); 

    cout << h.extractMin() << endl;
    cout << h.getMin() << endl;
    h.decreaseKey(2, 1);
    cout << h.getMin() << endl;

    return (0);
}