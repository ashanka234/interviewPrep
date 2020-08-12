#include<iostream>
using namespace std;

int maxSum(int *arr, int n) {
    int dp[n];
    for(int i=0; i<n; i++)
        dp[i] = arr[i];

    int res = 0;

    for(int i=1; i<n; i++) {
        for(int j=0; j<i; j++) {
            if(arr[j]<arr[i]) {
                dp[i] = max(dp[i], dp[j]+arr[i]);
                res = max(res, dp[i]);
            }
        }
    }
    cout << dp[n] << endl;
    return res;
}

int main() {
    int arr[] = {1, 101, 2, 3, 100, 4, 5};
    int n = sizeof(arr)/sizeof(arr[0]);

    cout << maxSum(arr, n) << endl;

    return (0);
}