#include<iostream>
using namespace std;

int knapsack(int W, int *val, int *weight, int n) {
    int dp[n+1][W+1];

    for(int i=0; i<=n; i++) {
        for(int j=0; j<=W; j++) {
            if(i==0 || j==0)
                dp[i][j] = 0;

            else if(weight[i-1] < W) {
                dp[i][j] = max(val[i-1] + dp[i-1][j-weight[i-1]], dp[i-1][j]);
            }
            else
            {
                dp[i][j] = dp[i-1][j];
            }
        }
    }

    return dp[n][W];
}

int main() {
    int val[] = {60, 100, 120};
    int n = sizeof(val)/sizeof(val[0]);

    int weight[] = {10, 20, 30};
    int W = 50;

    cout << knapsack(W, val, weight, n) << endl;

    return (0);
}