#include<iostream>
#include<cstring>
using namespace std;

int myMin(int a, int b, int c) {
    return min(a, min(b,c));
}

int editDistance(string s1, string s2) {
    int m = s1.length();
    int n = s2.length();

    int dp[m+1][n+1];

    for(int i=0; i<=m; i++) {
        for(int j=0; j<=n; j++) {
            if(i==0)
                dp[i][j] = j;
            else if(j==0)
                dp[i][j] = i;

            else if(s1[i-1] == s2[j-1])
                dp[i][j] = dp[i-1][j-1];

            else {
                dp[i][j] = 1 + myMin(dp[i-1][j], dp[i][j-1], dp[i-1][j-1]);
            }
        }
    }
    return dp[m][n];
}

int main() {
    string s1 = "sunday";       //insert a,t and replace n with r
    string s2 = "saturday";

    cout << editDistance(s1, s2) << endl;

    return (0);
}