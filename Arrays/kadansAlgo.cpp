// Largest continuous subarray sum - Kadan's algo O(n)
#include<iostream>
#include<climits>
using namespace std;

int getMaxSum(int *arr, int n) {
    int maxSoFar = INT_MIN;     //may or may not contain current element
    int maxEndingHere = 0;      //starting from beginning

    for(int i=0; i<n; i++) {
        maxEndingHere += arr[i];

        if(maxEndingHere > maxSoFar)
            maxSoFar = maxEndingHere;

        if(maxEndingHere < 0)
            maxEndingHere = 0;
    }

    return maxSoFar;
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        int *arr = new int[n];

        for(int i=0; i<n; i++) {
            cin >> arr[i];
        }

        cout << getMaxSum(arr, n) << endl;
    }


    return (0);
}