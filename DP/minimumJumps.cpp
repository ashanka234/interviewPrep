#include<iostream>
#include<climits>
using namespace std;


//we need to find min steps to reach arr end
int minSteps(int *arr, int n) {
    if(n==0 || arr[0]==0)       //no solution possible
        return -1;

    int dp[n];      //dp[i] represents min jumps to reacch arr[i]
    dp[0] = 0;

    for(int i=1; i<n; i++) {
        dp[i] = INT_MAX;

        for(int j=0; j<i; j++) {        //we've to reach position i
            if(dp[j]!=INT_MAX && j+arr[j] >= i) {       //we've made jump from pos j, of arr[j] size, and either reach or surpass pos i
                dp[i] = min(dp[i], dp[j]+1);
                break;      //break because we've reached i position
            }
        }
    }

    return dp[n-1];     //we had to reach end of arr i.e index n-1
}

int main() {
    int n;
    cin >> n;
    int *arr = new int[n];

    for(int i=0; i<n; i++)
        cin >> arr[i];

    cout << minSteps(arr, n) << endl;

    return (0);
}