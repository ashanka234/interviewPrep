#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void reverseInK(int *arr, int n, int k) {

    for(int i=0; i+k-1<n; i++) {
        reverse(arr+i, arr+i+k);
        i += k-1;
    }

    //print result
    for(int i=0; i<n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

void reverseInK_1(int *arr, int n, int k) {
    for(int i=0; i<n; i+=k) {
        int left = i;
        int right = min(i+k-1, n-1);

        while(left<right) {
            swap(arr[left], arr[right]);
            left++;
            right--;
        }
    }

    //print result
    for(int i=0; i<n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8};
    int n = sizeof(arr)/sizeof(arr[0]);
    int k=4;

    reverseInK_1(arr, n, k);

    return (0);
}