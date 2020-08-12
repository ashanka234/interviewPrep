#include<iostream>
#include<climits>
#include<algorithm>
using namespace std;

int getElement(int *arr, int n) {
    int rightMin = INT_MAX;

    int *leftMax = new int[n];
    leftMax[0] = INT_MIN;

    for(int i=1; i<n; i++) {
        leftMax[i] = max(leftMax[i-1], arr[i-1]);
    }

    for(int i=n-1; i>=0; i--) {
        if(leftMax[i] < arr[i] && rightMin > arr[i])
            return i;       //ans found
        
        rightMin = min(rightMin, arr[i]);
    }

    return -1;
}

int main() {
    int arr[] = {5, 1, 4, 3, 6, 8, 10, 7, 9};
    int n = sizeof(arr)/sizeof(arr[0]);

    cout << getElement(arr, n) << endl;

    return (0);
}