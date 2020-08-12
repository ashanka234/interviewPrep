#include<iostream>
using namespace std;

int maxPoints(int *arr, int n) {
    int dp[n][n];

    for(int gap=0; gap<n; gap++) {
        for(int i=0, j=gap; j<n; j++) {
            int x = i+2<=j? dp[i+2][j] : 0;
            int y = i+1<=j-1? dp[i+1][j-1] : 0;
            int z = j-2>=i? dp[i][j-2] : 0;

            dp[i][j] = max(arr[i] + min(x, y), arr[j]+min(y, z));
        }
    }

    return dp[0][n-1];
}

int main() {
    int coins[] = {8, 15, 3, 7};
    int n = sizeof(coins)/sizeof(coins[0]);

    cout << maxPoints(coins, n) << endl;

    return (0);
}