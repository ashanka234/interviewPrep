#include<iostream>
using namespace std;

int lis(int *arr, int n) {
    int dp[n];

    int res = 1;
    dp[0] = 1;

    for(int i=1; i<n; i++) {
        dp[i] = 1;

        for(int j=0; j<i; j++) {
            if(arr[i] > arr[j]) {
                dp[i] = max(dp[i], dp[j]+1);
                res = max(res, dp[i]);
            }
        }
    }

    return res;
}

int main() {
    int arr[] = {3, 10, 2, 1, 20};
    int n = sizeof(arr)/sizeof(arr[0]);

    cout << lis(arr, n) << endl;

    return (0);
}