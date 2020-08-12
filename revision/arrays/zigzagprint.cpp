#include<iostream>
using namespace std;

void printZigzag(int *arr, int n) {
    int flag = 1;       //next element greater

    for(int i=0; i<n; i++) {
        if(flag) {
            if(arr[i]>arr[i+1])
                swap(arr[i], arr[i+1]);
        }

        else
        {
            if(arr[i]<arr[i+1])
                swap(arr[i], arr[i+1]);
        }  
    }

    for(int i=0; i<n; i++) 
        cout << arr[i] << " ";
    cout << endl;
}

int main() {
    int arr[] = {4, 3, 7, 8, 6, 2, 1};
    int n = sizeof(arr)/sizeof(arr[0]);

    printZigzag(arr, n);

    return (0);
}