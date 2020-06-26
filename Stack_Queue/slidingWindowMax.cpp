/* MOST IMPORT - very frequently asked ques */
/* Sliding window sum/ max element in sliding window */
#include<iostream>
#include<set>
#include<utility>
using namespace std;

int maxOfSubarray(int *arr, int n, int k) {
    int sum = 0;        //we will find sum also of all the max elements of each subarray of size k
    set<pair<int, int> > q;

    //set will store in increasing order in log(K) time
    //same as self balancing BST like AVL tree 
    set<pair<int, int> >::reverse_iterator it;      //reverse iterator because max is stored at end of set
                                                    //we can use max heap/priority queue also
    
    //insert first k elements
    for(int i=0; i<k; i++) {
        q.insert(make_pair(arr[i], i));
    }

    for(int j=0; j<n-k+1; j++) {
        it = q.rbegin();        //start at end as max is at last 
        cout << it->first << " ";
        sum += it->first;

        //delete leftmost element from current window
        q.erase(make_pair(arr[j], j));

        //insert next element that is (j+k)th one 
        q.insert(make_pair(arr[j+k], j+k));
    }
    cout << endl;
    return sum;
}

int main() {
    int n, k;
    cin >> n;

    int *arr = new int[n];
    for(int i=0; i<n; i++)
        cin >> arr[i];

    cin >>  k;
    
    cout << maxOfSubarray(arr, n, k) << endl;

    return (0);
}