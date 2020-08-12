#include<iostream>
using namespace std;

int missingNumber(int *arr, int n) {
    int xorSum = arr[0];
    for(int i=1; i<n-1; i++)
        xorSum = xorSum ^ arr[i];

    int actualXorSum = 0;
    for(int i=1; i<=7; i++)
        actualXorSum = actualXorSum ^ i;

    return xorSum ^ actualXorSum;
}

int main() {
    int arr[] = {1, 2, 3, 4, 5, 7};
    int n = 7;

    cout << missingNumber(arr, n) << endl;

    return (0);
}