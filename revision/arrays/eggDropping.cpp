#include<iostream>
#include<climits>
using namespace std;

int eggDrop(int n, int k) {
    int dp[n+1][k+1];

    for(int i=1; i<=n; i++) {
        dp[i][1] = 1;
        dp[i][0] = 0;
    }

    for(int j=1; j<=k; j++) {
        dp[1][j] = j;
    }

    for(int i=2; i<=n; i++) {
        for(int j=2; j<=k; j++) {
            dp[i][j] = INT_MAX;

            for(int x=1; x<=j; x++) {
                int res = 1 + max(dp[i-1][x-1], dp[i][j-x]);
                dp[i][j] = min(dp[i][j], res);
            }
        }
    }

    return dp[n][k];
}

int main() {
    int n=2;
    int k=10;

    cout << eggDrop(n, k) << endl;

    return (0);
}