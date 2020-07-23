#include<iostream>
using namespace std;

int binarySearch(int arr[], int low, int high, int key) {
    if(low>high)
        return -1;      //not found

    int mid = (high+low)/2;

    if(key == arr[mid])
        return mid;         //found

    //low to mid is sorted i.e mid is the rotation point
    if(arr[low] <= arr[mid]) {
        if(key>=arr[low] && key<=arr[mid]) 
            return binarySearch(arr, low, mid-1, key);
        
        return binarySearch(arr, mid+1, high, key);
    }

    //if low to mid is not sorted, then mid to high must be sorted
    if(key>=arr[mid] && key<=arr[high])
        return binarySearch(arr, mid+1, high, key);

    return binarySearch(arr, low, mid-1, key);
}

int main() {
    int arr[] = {5, 6, 7, 8, 9, 10, 1, 2, 3};
    int n = sizeof(arr)/sizeof(arr[0]);
    int key = 3;

    cout << binarySearch(arr, 0, n-1, key) << endl;

    return (0);
}