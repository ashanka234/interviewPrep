#include<iostream>
#include<unordered_map>
using namespace std;

void printPairs(int *arr, int n, int sum) {
    unordered_map<int, int> mp;

    for(int i=0; i<n; i++) {
        int rem = sum - arr[i];

        if(mp.find(rem) != mp.end()) {
            int freq = mp[rem];     //jitni baar remainder aaya hai utne pairs banenge with arr[i]
            for(int j=0; j<freq; j++) {
                cout << rem << " " << arr[i] << endl;
            }
        }

        mp[arr[i]]++;
    }
}

int main() {
    int arr[] = { 1, 5, 7, -1, 5 }; 
    int n = sizeof(arr) / sizeof(arr[0]); 
    int sum = 6; 

    printPairs(arr, n, sum);

    return (0);
}