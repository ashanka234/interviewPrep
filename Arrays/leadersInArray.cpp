#include<iostream>
#include<vector>
using namespace std;

void printLeaders(int *arr, int n) {
    vector<int> ans;

    ans.push_back(arr[n-1]);        //last element is always leader
    int maxVal = arr[n-1];
    for(int i=n-2; i>=0; i--)
    {
        if(arr[i] > maxVal) {
            ans.push_back(arr[i]);
            maxVal = arr[i];
        }
    }

    // vector<int>::iterator itr = ans.end();
    // cout << *itr << endl;

    for(vector<int>::iterator it=ans.end()-1; it >= ans.begin(); --it)
        cout << *it << " ";
    cout << endl;
}

int main() {
    int n;
    cin >> n;
    int *arr = new int[n];
    for(int i=0; i<n; i++)
        cin >> arr[i];

    printLeaders(arr, n);

    return (0);
}