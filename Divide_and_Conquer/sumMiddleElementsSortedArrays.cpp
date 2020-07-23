#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int getMiddle(int arr[], int n) {
    if(n%2 == 0)
        return (arr[n/2]+arr[n/2+1])/2;
    else
        return arr[n/2];
}

int getSum(int *arr1,  int *arr2, int n) {
    if(n<=0)
        return -1;

    if(n==1)
        return arr1[0] + arr2[0];

    if(n==2)
        return max(arr1[0], arr2[0]) + min(arr1[1], arr2[1]);

    int m1 = getMiddle(arr1, n);
    int m2 = getMiddle(arr2, n);

    if(m1 < m2) {
        if(n%2 == 0)
            return getSum(arr1+n/2-1, arr2, n-n/2+1);
        else
            return getSum(arr1+n/2, arr2, n-n/2);
    }
    else
    {
        if(n%2==0)
            return getSum(arr2+n/2-1, arr1, n-n/2+1);
        else
            return getSum(arr2+n/2, arr1, n-n/2);
    }
    
}

//easy method STL based
int getSum_1(int *arr1, int *arr2, int n) {
    vector<int> res(2*n);

    merge(arr1, arr1+n, arr2, arr2+n, res.begin());

    /* for(int i=0; i<2*n; i++)
        cout << res[i] << " ";
    cout << endl; */

    return res[n] + res[n-1];
}

int main() {
    int ar1[] = {1, 2, 3, 6}; 
    int ar2[] = {4, 6, 8, 10}; 
    int n1 = sizeof(ar1) /  
             sizeof(ar1[0]); 
    int n2 = sizeof(ar2) /  
             sizeof(ar2[0]); 

    if(n1==n2)
        cout << getSum_1(ar1, ar2, n1) << endl;

    return (0);
}