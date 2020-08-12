#include<iostream>
using namespace std;

void sort012(int *arr, int n) {
    int low=0;
    int mid=0;
    int high=n-1;

    while(low<=mid && mid<=high) {
        if(arr[mid]==0) {
            swap(arr[low], arr[mid]);
            low++;
            mid++;
        }
        else if(arr[mid]==1) {
            mid++;
        }
        else
        {
            swap(arr[mid], arr[high]);
            mid++;
            high--;
        }   
    }

    for(int i=0; i<n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main() {
    int arr[] = {2, 1, 0, 0, 2, 1, 2, 1, 1, 0};
    int n = sizeof(arr)/sizeof(arr[0]);

    sort012(arr, n);

    return (0);
}