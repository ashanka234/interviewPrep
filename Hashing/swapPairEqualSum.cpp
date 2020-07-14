#include<iostream>
#include<unordered_map>
using namespace std;

void findSwapPair(int *arr1, int *arr2, int m, int n) {
    //here we are assuming arr1 length is smaller than arr2 length. We can add a check in main() to ensure this condition

    unordered_map<int, int> mp;

    int sum1=0, sum2=0;

    for(int i=0; i<m; i++) {
        sum1 += arr1[i];
        mp[arr1[i]] = sum1;     //the sum till ith element of smaller array
    }

    /* for(auto it=mp.begin(); it!=mp.end(); ++it) {
        cout << it->first << " " << it->second << endl;
    }
    cout << "\n"; */

    for(int i=0; i<n; i++)
        sum2 += arr2[i];

    //cout << "sum1=" << sum1 << " sum2=" << sum2 << endl;
    int diff = (sum1 - sum2)/2;
    //cout << "diff=" << diff << endl;
    for(int  i=0; i<n; i++) {
        if(mp.find(arr2[i]+diff) != mp.end()) {
            //cout << arr2[i] << endl;
            cout << arr2[i]+diff << " " << arr2[i] << endl;
            break;
        }
    }
}

int main() {
    int arr2[] = { 4, 1, 2, 1, 1, 2 };      
    int n = sizeof(arr2)/sizeof(int);

    int arr1[] = { 1, 6, 3, 3 };        
    int m = sizeof(arr1)/sizeof(int);

    findSwapPair(arr1, arr2, m, n);

    return (0);
}