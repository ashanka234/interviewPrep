#include<iostream>
using namespace std;

int trappingWater(int *arr, int n) {
    int left[n];
    int right[n];
    int maxWater = 0;

    left[0] = arr[0];
    for(int i=1; i<n; i++) {
        left[i] = max(left[i-1], arr[i]);
    }

    right[n-1] = arr[n-1];
    for(int i=n-2; i>=0; i--) {
        right[i] = max(right[i+1], arr[i]);
    }

    for(int i=0; i<n; i++) {
        maxWater += min(left[i], right[i]) - arr[i];
    }

    return maxWater;
}

int main() {
    int water[] = {3, 0, 2, 0, 4};
    int n = sizeof(water)/sizeof(water[0]);

    cout << trappingWater(water, n) << endl;

    return (0);
}