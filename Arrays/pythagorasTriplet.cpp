#include<iostream>
#include<algorithm>
using namespace std;

bool isPythagoras(int *arr, int n) {
    for(int i=0; i<n; i++)  {       //square all elements
        arr[i] = arr[i] * arr[i];
    }

    sort(arr, arr+n);

    for(int i=n-1; i>=2; i--) {
        int l = 0;
        int r = i-1;

        while(l<r) {
            if(arr[l] + arr[r] == arr[i])       //triplet found
                return true;

            if(arr[l] + arr[r] < arr[i]) 
                l++;
            else
                r--;
        }
    }

    return false;
}

int main() {
    int n;
    cin >> n;

    int *arr = new int[n];
    for(int i=0; i<n; i++)
        cin >> arr[i];

    if(isPythagoras(arr, n))
        cout << "Yes\n" ;
    else
        cout << "No\n";

    return (0);
}