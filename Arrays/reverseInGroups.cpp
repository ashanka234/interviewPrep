#include<iostream>
#include<algorithm>
using namespace std;

void reverseK(int *arr, int n, int k) {
    int left=0, right=k-1;

    for(int i=0; i<n; i+=k) {
        left = i;
        right = min(i+k-1, n-1);        //n-1 because if last mei k elements nhi bache hue
        while(left<right)
            swap(arr[left++], arr[right--]);
    }
}

int main() {
    int t;
    cin >> t;

    while(t--) {
        int n, k;

        cin >> n;
        int *arr = new int[n];
        for(int i=0; i<n; i++) {
            cin >> arr[i];
        }
        cin >> k;

        reverseK(arr, n, k);

        for(int i=0; i<n; i++) {
            cout << arr[i] << " ";
        }

        cout << endl;
    }

    return (0);
}