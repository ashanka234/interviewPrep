#include<iostream>
#include<climits>
using namespace std;

int minSum(int *arr, int n) {
    int sum=0;      //sum of all
    for(int i=0; i<n; i++)
        sum += arr[i];

    bool dp[n+1][sum+1];        //dp[i][j] stores true if sum j can be made using i elements of array

    for(int i=0; i<=n; i++)
        dp[i][0] = true;        //0 sum can always be made

    for(int i=1; i<=sum; i++)
        dp[0][i] = false;       //no sum (except 0) can be formed using 0 no. of elements from the array

    for(int i=1; i<=n; i++) {
        for(int j=1; j<=sum; j++) {
            dp[i][j] = dp[i-1][j];      //exclude current element

            if(arr[i-1] <= j) {     //including current
                dp[i][j] |= dp[i-1][j-arr[i-1]];        //till previous element, sum was current sum minus current element
                                                        // |= is same as +=, used in binary (as dp is of bool type)
            }
        }
    }

    int diff = INT_MAX;

    for(int j=sum/2;j>=0; j--) {
        if(dp[n][j] == true) {      //we've to find for all n elements
            diff = sum - 2*j;       //memorise this
            break;      //agar kisi bhi j sum ke liye n elements se ho rha hai solution, then stop there only and ussi ka difference nikal lo
        }
    }

    return diff;        //the minimum difference between 2 subsets 
}

int main() {
    int n;
    cin >> n;
    int *arr = new int[n];

    for(int i=0; i<n; i++) 
        cin >> arr[i];
    
    cout << minSum(arr, n) << endl;

    return (0);
}