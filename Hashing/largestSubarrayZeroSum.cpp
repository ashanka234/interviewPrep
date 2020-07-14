#include<iostream>
#include<unordered_map>
using namespace std;

int maxLen(int *arr, int n) {
    int sum=0;
    int maxLen=0;
    unordered_map<int, int> hash;

    for(int i=0; i<n; i++) {
        sum += arr[i];

        if(arr[i]==0 && maxLen==0) { //if starting new subarray w element 0, then that will get included
            maxLen = 1;
        }
        if(sum==0)      //if sum is becoming 0 including this element, then till here the subarray is part of answer
            maxLen = i+1;

        if(hash.find(sum) != hash.end()) {
            maxLen = max(maxLen, i-hash[sum]);          //i-hash[sum] will give length of subarray
        }
        else
        {
            hash[sum] = i;      //yeh wala sum konse inded tak hai 
        } 
    }

    return maxLen;
}

int main() {
    int n;
    cin >> n;
    int *arr = new int[n];

    for(int i=0; i<n; i++)
        cin >> arr[i];

    cout << maxLen(arr, n) << endl;

    return (0);
}