#include<iostream>
using namespace std;

void sortedMerge(int *arr1, int n1, int *arr2, int n2) {
    for(int i=n2-1; i>=0; i--) {
        int last = arr1[n1-1];
        int j = n1-2;

        while(j>=0 && arr1[j]>arr2[i]) {
            arr1[j+1] = arr1[j];
            j--;
        }

        if(j != n1-2 || last>arr2[i]) {
            arr1[j+1] = arr2[i];
            arr2[i] = last;
        }
    }

    for(int i=0; i<n1; i++)
        cout << arr1[i] << " ";
    for(int i=0; i<n2; i++)
        cout << arr2[i] << " ";
    cout << endl;
}

int main() {
    int arr1[] = {1, 3, 5, 7};
    int n1 = sizeof(arr1)/sizeof(arr1[0]);
    int arr2[] = {2, 4,  6, 8};
    int n2 = sizeof(arr2)/sizeof(arr2[0]);

    sortedMerge(arr1, n1, arr2, n2);

    return (0);
}