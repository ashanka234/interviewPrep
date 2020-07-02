/* name problem 
    subsequence doesnt have to be continuous
*/

#include<iostream>
#include<algorithm>
using namespace std;

int lis(int *arr, int n) {
    int dp[n];

    dp[0] = 1;      //least length  of subsequence can be 1 only
    //dp[i] represents length of max incr subsequence till index i in arr

    for(int i=1; i<n; i++) {
        dp[i] = 1;
        for(int j=0; j<i; j++) {
            if(arr[i] > arr[j]) {       //j peeche hai i aage hai
                dp[i] = max(dp[i], dp[j]+1);
            }
        }
    }

    //return max len among all
    int res = 0;
    for(int i=0; i<n; i++) 
        res = max(res, dp[i]);

    return res;
}

int main() {
    int n;
    cin >> n;

    int *arr = new int[n];
    for(int i=0; i<n; i++)
        cin >> arr[i];

    cout << lis(arr, n) << endl;

    return (0);
}