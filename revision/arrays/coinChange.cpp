#include<iostream>
using namespace std;

int ways(int  *coins, int n, int  sum) {
    int dp[sum+1][n];

    for(int i=0; i<=sum; i++)
        for(int j=0; j<n; j++)
            dp[i][j] = 0;

    for(int j=0; j<n; j++)
        dp[0][j] = 1;

    for(int i=1; i<=sum; i++) {
        for(int j=0; j<n; j++) {
            int including = (i-coins[j] >= 0) ? dp[i-coins[j]][j] : 0;
            int excluding = (j>=1)? dp[i][j-1] : 0;

            dp[i][j] = including + excluding;
        }
    }

    return dp[sum][n-1];
}

int main() {
    int coins[] = {1, 2, 3};
    int n = sizeof(coins)/sizeof(coins[0]);
    int sum = 4;

    cout << ways(coins, n, sum) << endl;

    return (0);
}