#include<iostream>
using namespace std;

bool isSubsetPossible(int *arr, int n, int sum) {
    int dp[n+1][sum+1];     //dp[i][j] is 1 if in the array  from 0 to i-1, there is a subset with sum j

    for(int i=0; i<=n; i++)
        dp[i][0] = true;        //for sum 0, subset is always present ie subset of zero size

    for(int j=1; j<=sum; j++)
        dp[0][j] = false;       //for subset size 0, for any given sum thre can never be a subset

    for(int i=1; i<=n; i++) {       //i is size of subset, not index, thats why in dp size its taken n+1
        for(int j=1; j<=sum; j++) {
            if(j<arr[i-1]) 
                dp[i][j] = dp[i-1][j];      //if sum gets exceeded from reqd sum, then we cant take curr element into subset
            else
            {
                dp[i][j] = dp[i-1][j] || dp[i-1][j-arr[i-1]];
            }
            
        }
    }

    return dp[n][sum];
}

int main() {
    int n, sum;
    cin >> n;
    int *arr = new int[n];

    for(int i=0; i<n; i++)
        cin >> arr[i];
    cin >> sum;

    cout << isSubsetPossible(arr, n, sum) << endl;

    return (0);
}