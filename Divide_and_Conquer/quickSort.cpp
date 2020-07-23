#include<iostream>
using namespace std;

int partition(int *arr, int low, int high) {
    //this method will put the pivot element at correct place
    //all smaller elements will be on left side and larger ones on right side
    //we will use last element as pivot element

    int pivot = arr[high];
    int i = low-1;

    for(int j=low; j<=high-1; j++) {        //high-1 because arr[high] is the pivot only
        if(arr[j]<pivot) {
            i++;
            swap(arr[j], arr[i]);
        }
    }

    swap(arr[i+1], arr[high]);      //swap pivot(index high) to its required location

    return i+1;     //location of pivot
}


//Average O(nlogn)
//worst case O(n^2)
void quickSort(int *arr, int low, int high) {
    if(low<high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi-1);
        quickSort(arr, pi+1, high);
    }
}

int main() {
    int n;
    cin >> n;
    int *arr = new int[n];

    for(int i=0; i<n; i++)
        cin >> arr[i];

    quickSort(arr, 0, n-1);

    for(int i=0; i<n; i++)
        cout << arr[i] << " ";
    cout << endl;

    return (0);
}