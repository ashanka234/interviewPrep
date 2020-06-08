// Merge 2 sorted array without using extra space 
#include<iostream>
using namespace std;

void sortedMerge(int *arr1, int *arr2, int m, int n) {
    for(int i=n-1; i>=0; i--) {
        int last = arr1[m-1];
        int j=m-2;

        while(j>=0 && arr1[j]>arr2[i]) {        //shift right jab tak arr2 ke current wale se bada hai element
            arr1[j+1] = arr1[j];        //keep shifting till smallest greater element is found
            j--;
        }

        //ek element nikal jayega end wala because ek insert hua hai bich mei
        //nikle wale ko arr2 mei daal do
        if(j != m-2 || last>arr2[i])
        {
            arr1[j+1] = arr2[i];        //inserting the element of arr2 into arr1
            arr2[i] = last;
        }
    }
}

int main() {
    int t;
    cin >> t;

    while(t--) {
        int n, m;
        int *arr1, *arr2;
        cin >> n >> m;
        arr1 = new int[n];
        arr2 = new int[m];

        for(int i=0; i<n; i++)
            cin >> arr1[i];

        for(int i=0; i<m; i++) 
            cin >> arr2[i];

        sortedMerge(arr1, arr2, n, m);

        for(int i=0; i<n; i++) 
            cout << arr1[i] << " ";
        for(int i=0; i<m; i++) 
            cout << arr2[i] << " ";
        cout << endl;
    }

    return (0);
}