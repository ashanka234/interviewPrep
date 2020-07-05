/* very famous question - often asked with many types of variations */

#include<iostream>
#include<climits>
using namespace std;

int eggDrop(int n, int k) {
    int dp[n+1][k+1];
    int res;

    for(int i=1; i<=n; i++) {
        dp[i][1] = 1;       //for 1 floor we need only 1 trial, either  break or not break
        dp[i][0] = 0;       //for 0 floors we need zero trials
    }

    //for 1 egg, we will need j trials with j eggs
    for(int j=1; j<=k; j++) 
        dp[1][j] = j;       //only 1 egg, so we need to drop it from all floors

    for(int i=2; i<=n; i++) {
        for(int j=2; j<=k; j++) {
            dp[i][j] = INT_MAX;

            for(int x=1;  x<=j; x++) {      //drop from each floor
                res = 1 + max(dp[i-1][x-1],         //egg break, so one egg less, one floor less
                              dp[i][j-x]);          //egg not break, so same no. of eggs, j-x floors left cuz iske neeche wale kisi 
                                                    //floor se nhi tutega
                dp[i][j] = min(res, dp[i][j]);
            }
        }
    }

    return dp[n][k];
}

int main() {
    int n, k;       //n eggs, k floors
    cin >> n >> k;

    cout << eggDrop(n, k) << endl;

    return (0);
}