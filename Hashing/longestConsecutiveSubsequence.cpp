#include<iostream>
#include<unordered_set>
using namespace std;

int longestConsecutiveSubsequence(int *arr, int n) {
    int ans=0;
    unordered_set<int> s;

    for(int i=0; i<n; i++) {
        s.insert(arr[i]);       
    }

    for(int i=0; i<n; i++) {
        //if sequence is starting from here
        if(s.find(arr[i] - 1) == s.end()) {
            int j=arr[i];
            
            while(s.find(j) != s.end())
                j++;

            ans = max(ans, j-arr[i]);       //j is the element so difference will give subarray length
        }
    }

    return ans;
}

int main() {
    int arr[] = { 1, 9, 3, 10, 4, 20, 2 }; 
    int n = sizeof arr / sizeof arr[0];

    cout << longestConsecutiveSubsequence(arr, n) << endl;

    return (0);
}