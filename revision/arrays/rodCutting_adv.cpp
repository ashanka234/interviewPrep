#include<iostream>
#include<climits>
using namespace std;

int maxSegments(int l, int p, int q, int r) {
    int dp[l+1];
    dp[0] = 0;

    for(int i=1; i<=l; i++)
        dp[i] = -1;

    for(int i=0; i<=l; i++) {
        if(i+p <= l)
            dp[i+p] = max(dp[i+p], dp[i]+1);
        if(i+q <= l)
            dp[i+q] = max(dp[i+q], dp[i]+1);
        if(i+r <= l)
            dp[i+r] = max(dp[i+r], dp[i] + 1);
    }

    return dp[l];
}

int main() {
    int l = 11;
    int p=2, q=3, r=5;

    cout << maxSegments(l, p, q, r) << endl;

    return (0);
}