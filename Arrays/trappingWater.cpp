#include<iostream>
#include<algorithm>
using namespace std;

int getMaxWater(int *arr, int n) {
    int *left = new int[n];
    int *right = new int[n];
    int ans = 0;

    left[0] = arr[0];
    for(int i=1; i<n; i++) {
        left[i] = max(left[i-1], arr[i]);
    }

    right[n-1] = arr[n-1];
    for(int i=n-2; i>=0; i--) {
        right[i] = max(right[i+1], arr[i]);
    }

    //we have calculate max height on left and right for each element
    //now see for each element how much water it can store
    for(int i=0; i<n; i++) {
        ans += min(left[i], right[i]) - arr[i];
    }

    return ans;
}

int main() {
    int n;
    cin >> n;
    int *arr =new int[n];

    for(int i=0; i<n; i++) 
        cin >> arr[i];

    cout << getMaxWater(arr, n) << endl;

    return (0);
}