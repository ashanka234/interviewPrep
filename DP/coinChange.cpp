/* this is different from min coin change - here we have to tell total no. of ways to 
    make the sum, not min no. of coins required
*/

#include<iostream>
using namespace std;

int coinChange(int coins[], int m, int sum) {
    int dp[sum+1][m];       //dp[i][j] represents min no. of coins required to make i amount, using first j number of coins
    int x,y,i, j;

    for(int i=0; i<sum+1; i++) {
        for(int j=0; j<m; j++) {
            dp[i][j] = 0;
        }
    }
    
    for(int j=0; j<m; j++) 
        dp[0][j] = 1;       //for 0 sum, only 1 way, no matter how many coins we have

    for(i=1; i<sum+1; i++) {
        for(j=0; j<m; j++) {

            x = (i-coins[j]>=0)? dp[i-coins[j]][j] : 0;     //including current coind

            y = (j>=1)? dp[i][j-1] : 0;     //excluding current coin

            dp[i][j] = x+y;
           // cout << dp[i][j] << " ";
        }
        //cout << endl;
    }

    /*for(int i=0; i<sum+1; i++) {
        for(int j=0; j<m; j++) {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    } */
    
    return dp[sum][m-1];      //coins are 0 to m-1 indexed 
}

//alternate method
int coinChange_1(int *coins, int m, int sum) {
    int dp[sum+1];
    memset(dp, 0, sizeof(dp));

    dp[0] = 1;

    for(int i=0; i<m; i++) {
        for(int j=coins[i]; j<=sum; j++) {
            dp[j] += dp[j-coins[i]];
        }
    }

    return dp[sum];
}

int main() {
    int m;      //no. of coins
    cin >> m;
    int *coins = new int[m];

    for(int i=0; i<m; i++)
        cin >> coins[i];
    int sum;
    cin >> sum;

    cout << coinChange(coins, m, sum) << endl;
    cout << coinChange_1(coins, m, sum) << endl;

    return (0);
}