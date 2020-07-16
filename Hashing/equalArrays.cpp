#include<iostream>
#include<unordered_map>
using namespace std;

bool isEqual(int *arr1, int *arr2, int n, int m) {
    unordered_map<int, int> freq;

    if(n != m)
        return false;

    for(int i=0; i<n; i++) {
        freq[arr1[i]]++;
    }

    for(int i=0; i<m; i++) {
        freq[arr2[i]]--;
    }

    for(auto it=freq.begin(); it!=freq.end(); it++) {
        if(it->second != 0)
            return false;
    }

    return true;
}

int main() {
    int n, m;
    cin >> n >> m;

    int *arr1 = new int[n];
    int *arr2 = new int[m];

    for(int i=0; i<n; i++)
        cin >> arr1[i];
    for(int i=0; i<m; i++)
        cin >> arr2[i];

    cout << isEqual(arr1, arr2, n, m) << endl;

    return (0);
}