#include<iostream>
#include<algorithm>
using namespace std;

struct Pair {
    int a;
    int b;
};

bool myCompare(Pair p1, Pair p2) {
    return p1.a < p2.a;
}

int maxLengthChain(Pair *arr, int n) {
    int dp[n];
    for(int i=0; i<n; i++)
        dp[i] = 1;

    int maxLen = 1;

    sort(arr, arr+n, myCompare);

    for(int i=1; i<n; i++) {
        for(int j=0; j<i; j++) {
            if(arr[i].a > arr[j].b) {
                dp[i] = max(dp[i], dp[j]+1);
                maxLen = max(maxLen, dp[i]);
            }
        }
    }
    return maxLen;
}

int main() {
    Pair arr[] = { {5, 24}, {15, 25},  {27, 40}, {50, 60} };  
    int n = sizeof(arr)/sizeof(arr[0]);

    cout << maxLengthChain(arr, n) << endl;

    return (0);
}