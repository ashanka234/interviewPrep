#include<iostream>
#include<cstring>
using namespace std;

int lcs(string s1, string s2) {
    int m = s1.length();
    int n = s2.length();

    int dp[m+1][n+1];

    for(int i=0; i<=m; i++) {
        for(int j=0; j<=n; j++) {
            if(i==0 || j==0)
                dp[i][j] = 0;

            else if(s1[i-1] == s2[j-1])
                dp[i][j] = dp[i-1][j-1] + 1;
            else
                dp[i][j] = 0;
        }
    }

    int maxLen = 0;
    for(int i=0; i<=m; i++)
        for(int j=0; j<=n; j++)
            maxLen = max(maxLen, dp[i][j]);

    return maxLen;
}

int main() {
    string s1 = "geeksforgeeks";
    string s2 = "geeksquiz";

    cout << lcs(s1, s2) << endl;

    return (0);
}