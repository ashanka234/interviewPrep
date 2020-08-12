#include<iostream>
using namespace std;

int equilibrium(int *arr, int n) {
    //inluding the eq index element
    int leftSum=0, arraySum=0;

    for(int i=0; i<n; i++)
        arraySum += arr[i];

    for(int i=0; i<n; i++) {
        leftSum += arr[i];
        arraySum -= arr[i];

        if(leftSum == arraySum)     //eq found
            return i;
    }

    return -1;
}

int equilibrium_1(int *arr, int n) {
    //excluding the eq index element

    for(int i=0; i<n-1; i++) {
        int leftSum=0, rightSum=0;

        for(int j=0; j<i; j++) {
            leftSum += arr[j];
        }

        for(int j=i+1; j<n; j++) {
            rightSum += arr[j];
        }

        if(leftSum == rightSum)
            return i;
    }

    return -1;
}

int main() {
    int arr[] = {-7, 1, 5, 2, -4, 3, 0};
    int n = sizeof(arr)/sizeof(arr[0]);

    cout << equilibrium(arr, n) << endl;
    cout << equilibrium_1(arr, n) << endl;

    return (0);
}