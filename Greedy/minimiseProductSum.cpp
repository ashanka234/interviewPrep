#include<iostream>
#include<algorithm>
using namespace std;

int minProductSum(int *A, int *B, int n) {
    sort(A, A+n);
    sort(B, B+n);

    int res = 0;

    //we will multiply smallest with largest
    for(int i=0; i<n; i++) {
        int prod = A[i] * B[n-1-i];

        res += prod;
    }

    return res;
}

int main() {
    int A[] = { 3, 1, 1 }; 
    int B[] = { 6, 5, 4 }; 
    int n = sizeof(A) / sizeof(A[0]); 

    cout << minProductSum(A, B, n) << endl;

    return (0);
}