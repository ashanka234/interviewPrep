#include<iostream>
#include<climits>
using namespace std;

int maxSumContiguousSubarray(int *arr, int n) {
    int maxSoFar = INT_MIN;
    int maxEndingHere = 0;

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
    int arr[] = {-2, -3, 4, -1, -2, 1, 5, -3};
    int n = sizeof(arr)/sizeof(arr[0]);

    cout << maxSumContiguousSubarray(arr, n) << endl;

    return (0);
}