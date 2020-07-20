/* Very commonly asked question */

#include<iostream>
#include<queue>
#include<vector>
using namespace std;

void kthInStream(int k) {
    int x, count=0;

    priority_queue<int, vector<int>, greater<int> > maxHeap;        //max heap -smallest element on top
    //the heap will store only k largest elements; out of that the smallest will be the kth largest overall

    while(1) {      //stream
        cout << "enter element: ";
        cin >> x;

        if(count<k-1) {
            maxHeap.push(x);
            count++;
        }
        else
        {
            if(count==k-1) {
                maxHeap.push(x);        //2,5,6     count=2
            }
            else {
                if(x>maxHeap.top()) {
                    maxHeap.pop();
                    maxHeap.push(x);
                }
            }
            cout <<"kth largest: " << maxHeap.top() << endl;
        }
        
    }
}

int main() {
    int k = 3;
    kthInStream(k);

    return (0);
}