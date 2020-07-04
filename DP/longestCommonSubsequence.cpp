#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

int lcs(string s1, string s2, int m, int n) {
    int dp[m+1][n+1];   //dp[i][j] represents length of lcs for s1 is of length i, and s2 is of length j

    for(int i=0; i<=m; i++) {
        for(int j=0; j<=n; j++) {
            if(i==0 || j==0)        //koi bhi ek agar 0 length ka hai toh lcs bhi 0 length ka hi hoga
                dp[i][j] = 0;
            else if(s1[i-1]==s2[j-1]) 
                dp[i][j] = dp[i-1][j-1] + 1;
            else
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }

    return dp[m][n];
}

int main() {
    string s1, s2;
    cin >> s1 >> s2;

    cout << lcs(s1, s2, s1.length(), s2.length()) << endl;

    return (0);
}