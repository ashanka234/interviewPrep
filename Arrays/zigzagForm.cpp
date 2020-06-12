#include<iostream>
using namespace std;

void makeZigzag(int *arr, int n) {
    int flag=1;     //1-> next element should be greater; 0->next element smaller

    for(int i=0; i<n-1; i++) {
        if(flag) {
            if(arr[i] > arr[i+1]) {     //expected next element smaller
                swap(arr[i], arr[i+1]);
            }
        }

        else {      //expected next element greater
            if(arr[i] < arr[i+1]) {
                swap(arr[i], arr[i+1]);
            }
        }

        flag = !flag;
    }
}

int main() {
    int n;
    cin >> n;
    int *arr = new int[n];

    for(int i=0; i<n; i++)
        cin >> arr[i];

    makeZigzag(arr, n);

    for(int i=0; i<n; i++)
        cout << arr[i] <<  " ";
    cout << endl;

    return (0);
}