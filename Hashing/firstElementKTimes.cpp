#include<iostream>
#include<unordered_map>
using namespace std;

int getElement(int *arr, int n, int k) {
    unordered_map<int, int> freq;

    for(int i=0; i<n; i++)  
        freq[arr[i]]++;
    
    for(int i=0; i<n; i++) {
        if(freq[arr[i]] == k)
            return arr[i];
    }

    return -1;
}

int main() {
    int arr[] = {1, 7, 4, 3, 4, 8, 7}; 
    int n = sizeof(arr) / sizeof(arr[0]); 
    int k = 2; 

    cout << getElement(arr, n, k) << endl;

    return (0);
}