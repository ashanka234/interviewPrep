#include<iostream>
using namespace std;

int merge(int *arr, int *temp, int left, int mid, int right) {
    int i,j,k;
    int inv_count=0;

    i = left;
    j = mid;
    k = left;

    while(i<mid && j<=right) {
        if(arr[i] < arr[j])
            temp[k++] = arr[i++];
        else {
            temp[k++] = arr[j++];
            inv_count += (mid-i);
        }
    }

    while(i<mid) 
        temp[k++] = arr[i++];
    while(j<=right)
        temp[k++] = arr[j++];

    for(int i=left; i<=right; i++)
        arr[i] = temp[i];

    return inv_count;
}

int mergeSortUtil(int *arr, int *temp, int left, int right) {
    int mid, inv_count=0;
    if(left < right) {
        mid = (left + right) / 2;

        inv_count += mergeSortUtil(arr, temp, left, mid);
        inv_count += mergeSortUtil(arr, temp, mid+1, right);

        inv_count += merge(arr, temp, left, mid+1, right);
    }

    return inv_count;
}

int mergeSort(int *arr, int n) {
    int *temp = new int[n];

    return mergeSortUtil(arr, temp, 0, n-1);
}

int main() {
    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> n;

        int *arr = new int[n];
        for(int i=0; i<n; i++)
            cin >> arr[i];

        cout << mergeSort(arr, n)  << endl;
    }

    return (0);
}