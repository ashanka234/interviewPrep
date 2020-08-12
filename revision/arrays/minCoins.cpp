#include<iostream>
#include<climits>
using namespace std;

int minCoins(int *coins, int n, int sum) {
    int dp[sum+1];
    dp[0] = 0;

    for(int i=1; i<=sum; i++)
        dp[i] = INT_MAX;

    for(int i=1; i<=sum; i++) {
        for(int j=0; j<n; j++) {
            if(coins[j] <= i) {
                dp[i] = min(dp[i], dp[i-coins[j]]+1);
            }
        }
    }

    return dp[sum];
}

int main() {
    int coins[] = {9, 6, 5, 1};
    int n = sizeof(coins)/sizeof(coins[0]);
    int V = 11;

    cout << minCoins(coins, n, V) << endl;

    return (0);
}