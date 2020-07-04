#include<iostream>
using namespace std;

int msis(int *arr, int n) {
    int maxSum = 0;

    int dp[n];      //IMP POINT - array operations wale ques mei humesha n size ka dp hota hai.
                    //whereas in ques involving real things like substr length, money, rope, chain etc, humesha n+1 ka dp hoga

    for(int i=0; i<n; i++)      
        dp[i] = arr[i];

    //dp[i] represents max sum in array till index i
    for(int i=1; i<n; i++) {        //i aage hai , j peeche hai
        for(int j=0; j<i; j++) {        //in 1dp involving array, mostly this same loop is used
            if(arr[i]>arr[j] && dp[i]<dp[j]+arr[i])
                dp[i] = dp[j] + arr[i];         //is previous + current becoming more than current
        }
    }

    //return max among all sums 
    for(int i=0; i<n; i++) {
        maxSum = max(maxSum, dp[i]);
    }

    return maxSum;
}

int main() {
    int n;
    cin >> n;

    int *arr = new int[n];
    for(int i=0; i<n; i++) 
        cin  >> arr[i];

    cout << msis(arr, n) << endl;

    return (0);
}