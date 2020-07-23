#include<iostream>
using namespace std;

int kthInSorted(int *arr1, int *arr2, int *end1, int *end2, int k) {
    if(arr1 == end1)
        return arr2[k];

    if(arr2 == end2)
        return arr1[k];

    int mid1 = (end1-arr1)/2;
    int mid2 = (end2-arr2)/2;

    if(mid1+mid2<k) {
        if(arr1[mid1] > arr2[mid2]) {
            return kthInSorted(arr1, arr2+mid2+1, end1, end2, k-mid2-1);
        }
        else
        {
            return kthInSorted(arr1+mid1+1, arr2, end1, end2, k-mid1-1);
        }      
    }
    else
    {
        if(arr1[mid1]>arr2[mid2]){
            return kthInSorted(arr1, arr2, arr1+mid1, end2, k);
        }
        else
        {
            return kthInSorted(arr1, arr2, end1, arr2+mid2, k);
        }
        
    }  
}

int main() {
    int arr1[5] = {2, 3, 6, 7, 9}; 
    int arr2[4] = {1, 4, 8, 10};
    int n1 = sizeof(arr1)/sizeof(arr1[0]);
    int n2 = sizeof(arr2)/sizeof(arr2[0]);

    int k = 5;

    cout << kthInSorted(arr1, arr2, arr1+n1, arr2+n2, k-1) << endl;

    return (0);
}