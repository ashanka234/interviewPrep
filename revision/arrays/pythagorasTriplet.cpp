#include<iostream>
#include<algorithm>
using namespace std;

void pythagoras(int *arr, int n) {
    int l, r;
    sort(arr, arr+n);

    /* for(int i=0; i<n; i++)
        cout << arr[i] << " ";
    cout << endl; */

    for(int i=n-1; i>=2; i--) {
        l=0; r=i-1;

        while(l<r) {
            if(arr[l]*arr[l] + arr[r]*arr[r] == arr[i]*arr[i]) {        //found triplet
                cout << arr[l] << " " << arr[r] << " " << arr[i] << endl;   
                break;          //break the while, for loop will continue  
            }

            if(arr[l]*arr[l] + arr[r]*arr[r] < arr[i]*arr[i])
                l++;
            else
                r--; 
        }
    }
}

int main() {
    int arr[] = {9, 6, 3, 10, 4, 8, 5, 8};
    int n = sizeof(arr)/sizeof(arr[0]);

    pythagoras(arr, n);

    return (0);
}