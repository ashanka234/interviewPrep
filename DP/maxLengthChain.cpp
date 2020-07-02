#include<iostream>
#include<vector>
#include<utility>
#include<algorithm>
using namespace std;

bool myCompare(pair<int, int> p1, pair<int, int> p2) {
    return p1.first < p2.first;
}

int maxChainLength(vector<pair<int, int> > arr, int n) {
    int i, j, maxLen=0;
    int *dp = new int[n];
    for(int i=0; i<n; i++)
        dp[i] = 1;      //min length is 1 for all

    sort(arr.begin(), arr.end(), myCompare);

    for(i=1; i<n; i++) {
        for(j=0; j<i; j++) {        //pair j is being connected to pair i; j wala peeche hai 
            if(arr[i].first > arr[j].second && dp[j]+1 > dp[i])
                dp[i] = dp[j] + 1;      //dp[i] represents max length till ith pair
        }
    }

    //find max of all dp
    for(int i=0; i<n; i++) {
        maxLen = max(maxLen, dp[i]);
    }

    return maxLen;
}

int main() {
    int n;
    cin >> n;
    vector<pair<int, int> > arr(n);

    for(int i=0; i<n; i++) {
        int first,  second;
        cin >> first >> second;
        arr[i] = make_pair(first,second);
    }

    /* sort(arr.begin(), arr.end(), myCompare);

    for(int i=0; i<n; i++) {
        cout << arr[i].first << " " << arr[i].second << endl;
    }  */

    cout << maxChainLength(arr, n) << endl;

    return (0);
}