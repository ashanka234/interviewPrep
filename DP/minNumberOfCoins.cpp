#include<iostream>
#include<algorithm>
#include<climits>
using namespace std;

int minCoins(int *coins, int m, int sum) {
    int dp[sum+1];  //dp[i] represents min coins for sum i
    dp[0] = 0;      //base case

    for(int i=1; i<=sum; i++)
        dp[i] = INT_MAX;

    for(int i=1; i<=sum; i++) {
        for(int j=0; j<m; j++) {
            if(coins[j] <= i) {      //jo sum banana hai usse badi value ka coin nhi use kr sakte
                int remainingSumAns = dp[i - coins[j]];
                //if(remainingSumAns != -1)
                    dp[i] = min(dp[i], remainingSumAns+1);
            }
        }
    }

    return dp[sum];
}

int main() {
    int m, sum;
    cin >> m;
    int *coins = new int[m];
    for(int i=0; i<m; i++)
        cin >> coins[i];
    cin  >> sum;

    cout << minCoins(coins, m, sum) << endl;

    return (0);
}