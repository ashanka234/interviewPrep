#include<iostream>
using namespace std;

int merge(int *arr, int *temp, int left, int mid, int right) {
    int invCount=0;
    int i, j, k;

    i=left;
    j=mid;
    k=left;

    while(i<mid && j<=right) {
        if(arr[i] < arr[j])
            temp[k++] = arr[i++];
        else {
            temp[k++] = arr[j++];
            invCount += (mid-i);
        }
    }

    while(i<mid) {
        temp[k++] = arr[i++];
    }
    while(j<=right) {
        temp[k++] = arr[j++];
    }

    for(int i=left; i<=right; i++)
        arr[i] = temp[i];

    return invCount;
}

int mergeSortUtil(int *arr, int *temp, int left, int right) {
    int mid, invCount=0;

    if(left<right) {
        mid = left + (right-left)/2;

        invCount += mergeSortUtil(arr, temp, left, mid);
        invCount += mergeSortUtil(arr, temp, mid+1, right);

        invCount += merge(arr, temp, left, mid+1, right);
    }

    return invCount;
}

int inversionCount(int *arr, int n) {
    int *temp = new int[n];

    return mergeSortUtil(arr, temp, 0, n-1);
}

int main() {
    int arr[] = {8, 4, 2, 1};
    int n = sizeof(arr)/sizeof(arr[0]);

    cout << inversionCount(arr, n) << endl;

    return (0);
}