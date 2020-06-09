//Similar to Dutch national flag problem
#include<iostream>
#include<vector>
using namespace std;

void sort012(int *arr, int n) {
    int low=0, mid=0, high=n-1;

    while(low<=mid && mid<=high) {

        if(arr[mid]==0)
        {
            swap(arr[low++], arr[mid++]);
        }
        else if(arr[mid]==1) {
            mid++;
        }
        else
        {
            swap(arr[mid], arr[high--]);
        }
        
    }
}

void sort012_2(int *arr, int n) {
    vector<int> v0, v1, v2;
    for(int i=0; i<n; i++) {
        if(arr[i] == 0)
            v0.push_back(arr[i]);
        else if(arr[i]==1)
            v1.push_back(arr[i]);
        else
            v2.push_back(arr[i]);
    }

    for(vector<int>::iterator itr=v0.begin(); itr<v0.end(); ++itr)
        cout << *itr << " ";
    for(vector<int>::iterator itr=v1.begin(); itr<v1.end(); ++itr)
        cout << *itr << " ";
    for(vector<int>::iterator itr=v2.begin(); itr<v2.end(); ++itr)
        cout << *itr << " ";
    cout << endl;
}

int main() {
    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> n;
        int *arr = new int[n];

        for(int i=0; i<n; i++)
            cin >> arr[i];

        sort012(arr, n);
        for(int i=0; i<n; i++)
            cout  << arr[i] << " ";
        cout << endl;

        //sort012_2(arr, n);
        
    }

    return (0);
}