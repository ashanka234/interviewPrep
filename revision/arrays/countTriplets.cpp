#include<iostream>
#include<algorithm>
using namespace std;

int countTriplets(int *arr, int n) {
    sort(arr, arr+n);
    int i, j, k;
    int res = 0;

    for(i=0; i<n-2; i++) {
        j=i+1;
        k=j+1;

        while(k<n) {
            if(arr[i] + arr[j] == arr[k]) {
                //triplet found
                res++;
                j++;
            }
            else if(arr[i] + arr[j] < arr[k]) {
                j++;
                k++;
            }
            k++;
        }
    }

    return res;
}

int main() {
    int arr[] = {1, 1, 1, 2, 2};
    int n = sizeof(arr)/sizeof(arr[0]);

    cout << countTriplets(arr, n) << endl;

    return (0);
}