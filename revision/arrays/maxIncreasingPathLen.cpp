#include<iostream>
using namespace std;

#define n 3

int myMax(int a, int b, int c, int d) {
    return max(a, max(b, max(c, max(d, 1))));
}

int maxFromCurrent(int mat[][n], int i, int j, int dp[][n]) {
    if(i<0 || i>=n || j<0 || j>=n)
        return 0;

    if(dp[i][j] != -1)
        return dp[i][j];

    int left=0, right=0, up=0, down=0;

    if(j<n-1 && mat[i][j]+1 == mat[i][j+1])     //move right
        right = 1 + maxFromCurrent(mat, i, j+1, dp);
    if(j>0 && mat[i][j]+1 == mat[i][j-1])       //move left
        left = 1 + maxFromCurrent(mat, i, j-1, dp);
    if(i<n-1 && mat[i][j]+1 == mat[i+1][j])     //move down
        down = 1 + maxFromCurrent(mat, i+1, j, dp);     
    if(i>0 && mat[i][j]+1 == mat[i-1][j])       //move up
        up = 1 + maxFromCurrent(mat, i-1, j,  dp);

    dp[i][j] = myMax(up, down, left, right);

    return dp[i][j];
}

int maxPathLen(int mat[][n]) {
    int dp[n][n];
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            dp[i][j] = -1;

    int maxLen = 0;

    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            if(dp[i][j] == -1) {
                dp[i][j] = maxFromCurrent(mat, i, j, dp);
                maxLen = max(maxLen, dp[i][j]);
            }
        }
    }

    return maxLen;
}

int main() {
    int mat[n][n] = { { 1, 2, 9 }, 
                      { 5, 3, 8 }, 
                      { 4, 6, 7 } }; 

    cout << maxPathLen(mat) << endl;

    return (0);    
}