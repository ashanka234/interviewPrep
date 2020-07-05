/* here we need to maximimse no. of segments but segments  can only be of length p,q,r*/

#include<iostream>
using namespace std;

int getMax(int l, int p, int q, int r) {
    int dp[l+1];        //dp[i] represents max no. of segments for rod of length i
    for(int i=0; i<=l; i++)
        dp[i] = -1;

    dp[0] = 0;

    for(int i=0; i<=l; i++) {
        if(i+p <= l)
            dp[i+p] = max(dp[i+p], dp[i]  + 1);
        if(i+q <= l)
            dp[i+q] = max(dp[i+q], dp[i]+1);
        if(i+r <= l)
            dp[i+r] = max(dp[i+r], dp[i] + 1);
    }

    return dp[l];
}

int main() {
    int l, p,q,r;       //l is length of rod
    cin >> l >> p >> q >> r;

    cout << getMax(l,p,q,r) << endl;

    return (0);
}