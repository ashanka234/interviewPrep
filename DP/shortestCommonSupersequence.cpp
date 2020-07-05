/* supersequence means a string which contains both s1 and s2 */

#include<iostream>
#include<cstring>
using namespace std;

int SCS(string s1, string s2, int m, int n) {
    int dp[m+1][n+1];       //dp[i][j] represents length of SCS for s1 of length i, s2 of length j

    for(int i=0; i<=m; i++) {
        for(int j=0; j<=n; j++) {
            if(i==0)
                dp[i][j] = j;
            else if(j==0)
                dp[i][j] = i;

            else if(s1[i-1] == s2[j-1])     //both chars same, so it will be part of supersequence
                dp[i][j] = 1 + dp[i-1][j-1];
            else 
                dp[i][j] = 1 + min(dp[i-1][j], dp[i][j-1]);
        }
    }

    return dp[m][n];
}

int main() {
    string s1, s2;
    cin >> s1 >> s2;

    cout << SCS(s1, s2, s1.length(), s2.length()) << endl;

    return (0);
}