#include<iostream>
#include<climits>
using namespace std;

int minJumps(int *arr, int n) {
    if(arr[0]==0 || n==0)
        return -1;

    int dp[n];
    dp[0] = 0;

    for(int i=1; i<n; i++) {
        dp[i] = INT_MAX;
        
        for(int j=0; j<i; j++) {
            if(dp[j] != INT_MAX && j+arr[j] >= i) {
                dp[i] = min(dp[i], dp[j]+1);
                break;
            }
        }
    }

    return dp[n-1];
}

int main() {
    int arr[] =  {1, 3, 5, 8, 9, 2, 6, 7, 6, 8, 9};
    int n = sizeof(arr)/sizeof(arr[0]);

    cout << minJumps(arr, n) << endl;

    return (0);
}