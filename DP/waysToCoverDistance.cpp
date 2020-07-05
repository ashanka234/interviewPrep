/* this question is exactly same as counting number of ways
    to climb  nth stairs using 1,2 or 3 stteps at a time
*/

#include<iostream>
using  namespace std;

int getWays(int d) {
    int dp[d+1];

    dp[0]=1; dp[1]=1; dp[2]=2;      //only 1 way to cover dist of 0 or 1, 2 ways to cover 2 dist ie 1+1 or direct 2

    for(int i=3; i<=d; i++) {
        dp[i] = dp[i-1] + dp[i-2] + dp[i-3];        //if its asked to find min steps required, then use (min of the 3)+1 im this step 
    }

    return dp[d];
}

int main() {
    int d;
    cin >> d;       //need to cover d distance using 1,2 or 3 steps

    cout << getWays(d) << endl;

    return (0);
}