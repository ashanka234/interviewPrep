/* matrix contains only 1 to n*n numbers
    find max path len s.t numbers are in increasing continuous sequence */

#include<iostream>
#include<climits>
#define n 3
using namespace std;

int  myMax(int a, int b, int c, int d) {
    return max(a, max(b, max(c,max(d,1))));     //if all 4 dirs are same, then we will take 1
}

int findLongestFromCell(int mat[n][n], int i, int j, int dp[n][n]) {
    if(i<0 || i>=n || j<0 || j>=n)      //boundary contraints
        return 0;       

    if(dp[i][j] != -1)
        return dp[i][j];        //already solved
    
    int up=INT_MIN, down=INT_MIN, left=INT_MIN, right=INT_MIN;

    if(j<n-1 && mat[i][j]+1==mat[i][j+1])       //move right
        right = 1 + findLongestFromCell(mat, i, j+1, dp);

    if(j>0 && mat[i][j]+1==mat[i][j-1])     //move left
        left = 1 + findLongestFromCell(mat, i, j-1, dp);

    if(i<n-1 && mat[i][j]+1==mat[i+1][j])       //move down
        down = 1 + findLongestFromCell(mat, i+1, j, dp);

    if(i>0 && mat[i][j]+1==mat[i-1][j])     //move up
        up = 1 + findLongestFromCell(mat, i-1, j, dp);

    dp[i][j] = myMax(up, down, left, right);

    return dp[i][j];
}

int getMaxPathLen(int mat[n][n]) {
    int dp[n][n];
    memset(dp, -1, sizeof(dp));

    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            if(dp[i][j] == -1)
                findLongestFromCell(mat, i, j, dp);
        }
    }

    int res = INT_MIN;
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            res = max(res, dp[i][j]);

    return res;
}

int main() {
    int mat[n][n] = { { 1, 2, 9 }, 
                      { 5, 3, 8 }, 
                      { 4, 6, 7 } }; 
    
    cout << getMaxPathLen(mat) << endl;

    return (0);
}