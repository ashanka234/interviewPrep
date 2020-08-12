#include<iostream>
#include<cstring>
using namespace std;

string longestPalindromicSubstring(string str) {
    int n = str.length();

    bool dp[n][n];
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            dp[i][j] = 0;

    int maxLen=1;
    int start = 0;

    for(int i=0; i<n; i++)
        dp[i][i] = true;

    for(int i=0; i<n-1; i++) {
        dp[i][i+1] = true;
        maxLen = 2;
        start = i;
    }

    for(int k=3; k<=n; k++) {
        for(int i=0; i+k-1<n; i++) {
            int j = i+k-1;

            if(str[i]==str[j] && dp[i+1][j-1]==true) {
                dp[i][j] = true;

                if(k > maxLen) {
                    maxLen = k;
                    start = i;
                }
            }
        }
    }

    return str.substr(start, maxLen);
}

int main() {
    string str = "forgeeksskeegfor";

    cout << longestPalindromicSubstring(str) << endl;

    return (0);
}