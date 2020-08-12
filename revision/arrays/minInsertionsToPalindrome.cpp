#include<iostream>
#include<cstring>
using namespace std;

int minInsertions(string s) {
    int n = s.length();

    int dp[n][n];
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            dp[i][j] = 0;

    int l, h;

    for(int len=1; len<n; len++) {
        for(l=0, h=len; h<n; l++, h++) {
            if(s[l] == s[h])
                dp[l][h] = dp[l+1][h-1];
            else 
                dp[l][h] = min(dp[l+1][h], dp[l][h-1]) + 1;
        }
    }

    return dp[0][n-1];
}

int main() {
    string s = "geeks";

    cout << minInsertions(s) << endl;

    return (0);
}