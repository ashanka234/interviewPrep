#include<iostream>
using namespace std;

//O(logn) solution
void getElement(int *arr, int low, int high) {
    //we will use binary search 

    if(low>high)        //base case
        return;

    if(low==high) {         //ans found
        cout << arr[low] << endl;
        return;
    }

    int mid = (high+low) / 2;

    //if mid is even, then the element next to it will be same
    if(mid%2 == 0) {
        if(arr[mid]==arr[mid+1])
            getElement(arr, mid+2, high);
        else
            getElement(arr, low, mid);
    }

    else        //if mid is off, then preivious element will be same
    {
        if(arr[mid] == arr[mid-1])
            getElement(arr, mid+1, high);
        else
            getElement(arr, low, mid-1);
    }
    
}

int main() {
    //given array is sorted
    int arr[] = { 1, 1, 2, 4, 4, 5, 5, 6, 6 };
    int n = sizeof(arr)/sizeof(arr[0]);

    getElement(arr, 0, n -1);
    
    return (0);
}