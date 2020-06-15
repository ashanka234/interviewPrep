#include<iostream>
#include<cstring>
#include<climits>
#include<algorithm>
using namespace std;

//recursive solution
int findMinInsertions(string s, int l, int h) {
    if(l>h)     //base case
        return INT_MAX;
    if(l==h)
        return 0;

    if(l==h-1) {        //length is 2
        if(s[l]==s[h])
            return 0;
        else
            return 1;
    }

    if(s[l]==s[h]) 
        return findMinInsertions(s, l+1, h-1);
    else 
        return (min(findMinInsertions(s, l+1, h), findMinInsertions(s, l, h-1)) + 1);
    
}

//DP solution
int findMinInsertions_1(string s, int n) {
    int dp[n][n];
    memset(dp, 0, sizeof(dp));

    int l, h, gap;

    for(gap=1; gap<n; gap++) {
        for(l=0, h=gap; h<n; l++, h++) {
            if(s[l]==s[h]) {
                dp[l][h] = dp[l+1][h-1];
            }
            else
            {
                dp[l][h] = min(dp[l][h-1], dp[l+1][h]) + 1;
            }
            
        }
    }

    return dp[0][n-1];
}

int main() {
    string s;
    cin >> s;

    int n = s.length();

    cout << findMinInsertions(s, 0, n-1) << endl;
    cout << findMinInsertions_1(s, n) << endl;

    return (0);
}