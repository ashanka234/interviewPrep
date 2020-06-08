#include<iostream>
using namespace std;

//this method will overflow if n is large
int getMissingNum(int *arr, int n) {
    int sum, arrSum=0;
    sum = n*(n+1)/2;

    for(int i=0; i<n-1; i++) {
        arrSum += arr[i];
    }

    return (sum - arrSum);
}

//other method using XOR
//if a1^a2^....an = A
// b1^b2^...b(n-1) = B
// then A^B = an (actual xor sum and array ka xor sum mei jo xor hai that is missing element)
int getMissingNum1(int *arr, int n) {
    int sum=1, arrSum=arr[0];

    for(int i=2; i<=n; i++) {
        sum = sum^i;
    }

    for(int i=1; i<n-1; i++) {
        arrSum = arrSum^arr[i];
    }

    return sum^arrSum;
}

int main() {

    int t;
    cin >> t;

    while(t--)
    {
        int n;
        int *arr;
        cin >> n;
        arr = new int[n-1];
        for(int i=0; i<n-1; i++) {
            cin >> arr[i];
        }

        cout << getMissingNum1(arr, n) << endl;
    }

    return (0);
}