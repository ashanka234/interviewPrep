#include<iostream>
#include<unordered_map>
using namespace std;

bool isSubset(int *arr1, int *arr2, int n, int m) {
    unordered_map<int, int> freq1, freq2;

    for(int i=0; i<n; i++) {
        freq1[arr1[i]]++;
    }

    for(int i=0; i<m; i++)  {
        freq2[arr2[i]]++;
    }

    for(auto it=freq2.begin(); it!=freq2.end(); it++) {
        if(freq1[it->first] < it->second)
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

    cout << isSubset(arr1, arr2, n, m) << endl;

    return (0);
}