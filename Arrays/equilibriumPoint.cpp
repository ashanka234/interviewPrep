#include<iostream>
using namespace std;

//including the eq element
int getEqIdx(int *arr, int n) {
    int arrSum=0, leftSum=0;

    for(int i=0; i<n; i++)
        arrSum += arr[i];

    for(int i=0; i<n; i++) {
        leftSum += arr[i];
        arrSum -= arr[i];

        if(arrSum == leftSum)
            return i;
    }

    return -1;
}

//excluding the eq element
int getEqIdx_2(int *arr, int n) {
    int rightSum=0, leftSum=0;

    for(int i=0; i<n; i++) {
        rightSum=0; leftSum=0;

        for(int j=0; j<i; j++)
            leftSum += arr[j];

        for(int j=i+1; j<n; j++)
            rightSum += arr[j];

        if(leftSum == rightSum)
            return i;
    }

    return -1;
}

int main() {
    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> n;
        int *arr = new int[n];

        for(int i=0; i<n; i++) {
            cin >> arr[i];
        }

        cout << getEqIdx_2(arr, n) << endl;
    }

    return (0);
}