#include<iostream>
#include<climits>
using namespace std;

int minDiff(int *arr, int n) {
    int sum=0;
    for(int i=0; i<n; i++)
        sum += arr[i];

    bool dp[n+1][sum+1];

    for(int i=0; i<=n; i++)
        dp[i][0] = 1;

    for(int j=1; j<=sum; j++)
        dp[0][j] = false;

    for(int i=1; i<=n; i++) {
        for(int j=1; j<=sum; j++) {
            dp[i][j] = dp[i-1][j];

            if(j >= arr[i-1]) {
                dp[i][j] |= dp[i-1][j-arr[i-1]];
            }
        }
    }

    int diff = INT_MAX;

    for(int j=sum/2; j>=0; j--) {
        if(dp[n][j] == 1) {
            diff = sum - 2*j;
            break;
        }
    }

    return diff;
}

int main() {
    int arr[] = {1, 6, 11, 5};
    int n = sizeof(arr)/sizeof(arr[0]);

    cout << minDiff(arr, n) << endl;

    return (0);
}