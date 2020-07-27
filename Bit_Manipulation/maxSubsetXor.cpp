/* most difficult question in bit magic */
/* memorise this */

#include<iostream>
#include<climits>
using namespace std;

int maxSubsetXOR(int *arr, int n) {
    int index = 0;

    for(int i=32-1; i>=0; i--) {
        int maxInd = index;
        int maxEle = INT_MIN;

        for(int j=index; j<n; j++) {
            //if ith bit of arr[j] is fixed
            if((arr[j] & (1<<i)) != 0 && arr[j]>maxEle) {
                maxEle = arr[j];
                maxInd = j;
            }
        }

        if(maxEle == INT_MIN)       //no element with ith bit set
            continue;

        swap(arr[index], arr[maxInd]);
        maxInd = index;

        for(int j=0; j<n; j++) {
            if((arr[j] & (1<<i)) != 0 && j != maxInd) {
                arr[j] = arr[j] ^ arr[maxInd];
            }
        }

        index++;
    }

    int res = 0;
    for(int i=0; i<n; i++) {
        res ^= arr[i];
    }

    return res;
}

int main() {
    int n;
    cin >> n;
    int *arr = new int[n];

    for(int i=0; i<n; i++)
        cin >> arr[i];

    cout << maxSubsetXOR(arr, n) << endl;

    return (0);
}