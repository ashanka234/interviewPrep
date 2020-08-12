#include<iostream>
#include<queue>
#include<vector>
using namespace std;

int kthSmallest(int *arr, int n, int k) {
    priority_queue<int, vector<int>, greater<int> > maxHeap;            //sabse chota wala sabse upar hai

    for(int i=0; i<n; i++)
        maxHeap.push(arr[i]);

    for(auto it=maxHeap.begin(); it!=maxHeap.end(); ++it)
        cout << *it << " ";
    cout << endl;

    for(int i=0; i<k-1; i++) {
        maxHeap.pop();
    }

    return maxHeap.top();
}

int main() {
    int n;
    int arr[] = {5, 3, 2, 4, 1, 6, 8};
    n = sizeof(arr)/sizeof(arr[0]);
    int k = 3;

    cout << kthSmallest(arr, n, k) << endl;
    //cout << kthLargest(arr, n, k) << endl;

    return (0);
}