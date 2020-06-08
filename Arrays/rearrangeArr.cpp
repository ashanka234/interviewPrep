#include<iostream>
using namespace std;

void rearrange(int *arr, int n) {
    int *temp = new int[n];
    int big=n-1, small=0;
    int flag=1;     //1 for inserting max element, 0 for min element

    for(int i=0; i<n; i++) {
        if(flag)
        {
            temp[i] = arr[big];
            big--;
        }
        else
        {
            temp[i] = arr[small];
            small++;
        }

        flag = !flag;
    }

    for(int i=0; i<n; i++)  
        cout << temp[i] << " ";
    cout << endl;
}

int main() {
    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> n;
        int *arr = new int[n];      //input is sorted array

        for(int i=0; i<n; i++)
            cin >> arr[i];

        rearrange(arr, n);
        // for(int i=0; i<n; i++) 
        //     cout << arr[i] << " ";
        // cout << endl;
    }

    return (0);
}