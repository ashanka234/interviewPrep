#include<iostream>
#include<vector>
using namespace std;

void printLeaders(int *arr, int n) {
    vector<int> res;

    int max = arr[n-1];
    res.push_back(arr[n-1]);

    for(int i=n-2; i>=0; i--) {
        if(arr[i] > max) {
            res.push_back(arr[i]);
            max = arr[i];
        }
    }

    for(auto it = res.begin(); it!=res.end(); ++it)
        cout << *it << " ";
    cout << endl;
}

int main() {
    int arr[] = {16, 17, 4, 3, 5, 2};
    int  n = sizeof(arr)/sizeof(arr[0]);

    printLeaders(arr, n);

    return (0);
}