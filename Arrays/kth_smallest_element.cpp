#include<iostream>
#include<queue>
using namespace std;

//we can simply sort and print kth element in O(nlogn) time

//O(k + (n-k)logk)
int getKthSmallest(int *arr, int n, int k) {
    priority_queue<int, vector<int>, greater<int> > pq;     //max heap - O(k)

    for(int i=0; i<n; i++)
        pq.push(arr[i]);

    for(int i=0; i<k-1; i++)
        pq.pop();

    return pq.top();
}

int main() {
    int n, k;
    cin >>n;

    int *arr = new int[n];

    for(int i=0; i<n; i++)  
        cin >> arr[i];
    cin >> k;
    
    cout << getKthSmallest(arr, n, k) << endl;

    return (0);
}