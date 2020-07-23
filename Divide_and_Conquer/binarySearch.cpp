#include<iostream>
using namespace std;

int binarySearch(int *arr, int low, int high, int k) {
    if(low > high)
        return -1;      //not found

    int mid = low + (high-low)/2;

    if(k == arr[mid])
        return mid;

    if(k<arr[mid])
        return binarySearch(arr, low, mid-1, k);
    else
        return binarySearch(arr, mid+1, high, k);
}

int main() {
    int n;
    cin >> n;
    int arr[n];

    for(int i=0; i<n; i++)
        cin >> arr[i];
    int k;
    cin >> k;

    cout << binarySearch(arr, 0, n-1, k) << endl;

    return (0);
}