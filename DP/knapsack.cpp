/* very famous name problem - memorise */

#include<iostream>
using namespace std;

int knapsack(int W, int *weight, int *val, int n) {
    int dp[n+1][W+1];       //dp[i][w] represents answer for values till i, and weight capacity w

    for(int i=0; i<=n; i++) {
        for(int w=0; w<=W; w++) {
            if(i==0 || w==0)
                dp[i][w] = 0;

            else if(weight[i-1] < W)  {     //capacity se zyada koi weght nhi use kr sakte
                dp[i][w] = max(val[i-1] + dp[i-1][w-weight[i-1]], dp[i-1][w]);      //basiaclly current wale ko leke maximimse ho rha hai ya nhi
            }
            else 
                dp[i][w] = dp[i-1][w];
        } 
    }

    return dp[n][W];
}

int main() {
    int val[] = { 60, 100, 120 };
    int n = sizeof(val)/sizeof(int); 
    int wt[] = { 10, 20, 30 }; 
    int W = 50;         //weight limit

    cout << knapsack(W, wt, val, n) << endl;

    return (0);
}