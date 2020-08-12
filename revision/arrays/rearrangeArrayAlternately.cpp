#include<iostream>
using namespace std;

void rearrange(int *arr, int n) {
    int res[n];
    bool flag = 1;          //1 for big, 0 for small
    int high = n-1;
    int low = 0;

    for(int i=0; i<n; i++) {
        if(flag) {
            res[i] = arr[high];
            high--;
        }
        else
        {
            res[i] = arr[low];
            low++;
        }
        flag = !flag;
    }

    for(int i=0; i<n; i++)
        cout << res[i] <<" ";
    cout << endl;
}

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6, 7};
    int n = sizeof(arr)/sizeof(arr[0]);

    rearrange(arr, n);
    
    return (0);
}