/* this is simple version of rod cutting 
    we only need to maximise  sell price by cutting the pieces 
*/

#include<iostream>
#include<climits>
using namespace std;

int maxPrice(int *arr, int n) {
    int dp[n+1];        //dp[i] represents the max price we can get for cutting rod of length i
    dp[0] = 0;      //max price for cutting rod of length zero is zero only

    for(int i=1; i<=n; i++) {
        dp[i] = INT_MIN;

        for(int j=0; j<i; j++) {
            dp[i] = max(dp[i], dp[j] + arr[i-j-1]);     //if we cur j length, then (i-j) length left, -1 because of indexing
        }
    }

    return dp[n];
}

int main() {
    //rod is  of length n
    //arr contains prices of cutting into each piece length

    int n;
    cin >> n;
    int *arr = new int[n];

    for(int i=0; i<n; i++)
        cin >> arr[i];

    cout << maxPrice(arr, n)  << endl;

    return (0);
}