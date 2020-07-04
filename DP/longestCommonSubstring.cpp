/* name question - memorise this */
#include<iostream>
#include<climits>
using namespace std;

int lcs(string s1, string s2, int  m, int n) {
    int dp[m+1][n+1];       //dp[i][j] represents length of lcs for s1 of length i, s2 of length j
    int res = 0;

    for(int i=0; i<=m; i++) 
    {
        for(int j=0; j<=n; j++) {
            if(i==0 || j==0)
                dp[i][j] = 0;

            else if(s1[i-1] == s2[j-1]) {
                dp[i][j] = dp[i-1][j-1] + 1;
                res = max(res, dp[i][j]);
            }

            else
                dp[i][j] = 0;       //if at any point chars not matching, then substring over cuz it must be continuous
        }
    }

    return res;
}

int main() {
    string s1, s2;
    cin >> s1 >> s2;

    cout << lcs(s1, s2, s1.length(), s2.length()) << endl;

    return (0);
}