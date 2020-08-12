#include<iostream>
#include<climits>
using namespace std;

int maxPrice(int *prices, int n) {
    int dp[n+1];
    dp[0] = 0;

    for(int i=1; i<=n; i++) {
        dp[i] = INT_MIN;

        for(int j=0; j<i; j++) {
            dp[i] = max(dp[i], dp[j] + prices[i-j-1]);
        }
    }

    return dp[n];
}

int main() {
    int prices[] = {1, 5, 8, 9, 10, 17, 17, 20};
    int n = sizeof(prices)/sizeof(prices[0]);

    cout << maxPrice(prices, n) << endl;

    return (0);
}