#include<iostream>
#include<cstring>
using namespace std;

void printSubstr(string s, int i, int j) {
    for(int k=i; k<=j; k++) {
        cout << s[k];
    }
}

//DP solution - O(n^2)
int longestPalindromicSubstr(string str) {
    int n = str.length();

    bool dp[n][n];      //dp[i][j] means substr from index i to j
    memset(dp, 0, sizeof(dp));

    int maxLen = 1;

    for(int i=0; i<n; i++) {
        dp[i][i] = true;        //all substr of length 1 are palindrome ie from i to i 
    }

    //length 2 substrs 
    int start=0;
    for(int i=0; i<n-1; i++) {
        if(str[i] == str[i+1]) {
            dp[i][i+1] = true;      //both chars should be same only then it can be pali
            start = i;
            maxLen = 2;
        }
    }

    //let k is length of substring
    for(int k=3; k<=n; k++) {
        for(int i=0; i<n-k+1; i++) {        //i is starting index
            int j = i+k-1;      //j is ending index 

            if(str[i]==str[j] && dp[i+1][j-1]==true)        //bahar wale char equal hain and andar wale dp check krega
            {
                dp[i][j] = true;

                if(k > maxLen) {
                    start = i;
                    maxLen = k;
                }
            }
        }
    }

    //print the longest pali substr
    printSubstr(str, start, start+maxLen-1);
    cout << endl;

    return maxLen;
}

//This can also be done in O(n) by Manacher's algorithm but its advanced
int main() {
    string str;
    cin >> str;

    cout << longestPalindromicSubstr(str) << endl;

    return (0);
}