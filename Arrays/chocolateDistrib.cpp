#include<iostream>
#include<algorithm>
#include<climits>
using namespace std;

int minDiff(int *arr, int n, int m) {
    int minDiff = INT_MAX;

    if(n<m)     //no. of kids cannot be more than no. of chocolates
        return -1;

    if(m==0 || n==0)
        return 0;       //0 chocolates or 0 kids to give to

    sort(arr, arr+n);

    for(int i=0; i+m-1 < n; i++) {
        minDiff = min(minDiff, arr[i+m-1] - arr[i]);
    }

    return minDiff;
}

int main() {
    int n, m;
    cin >> n;
    int *arr = new int[n];

    for(int i=0; i<n; i++)
        cin >> arr[i];      //no. of chocolates in each packet
    cin >> m;

    cout << minDiff(arr, n, m) << endl;

    return (0);
}