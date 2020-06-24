#include<iostream>
#include<stack>
using namespace std;

void printNextGreater(int *arr, int n) {
    stack<int> st;

    int *res = new int[n];

    for(int i=n-1; i>=0; i--) {
        while(!st.empty() && arr[i]>=st.top()) {
            st.pop();
        }

        if(st.empty())
            res[i] = -1;
        else
            res[i] = st.top();
        st.push(arr[i]);
    }

    for(int i=0; i<n; i++) {
        cout << arr[i] <<"->" << res[i] << endl;
    }
}

int main() {
    int n;
    cin >> n;

    int *arr = new int[n];
    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }

    printNextGreater(arr, n);
    cout << endl;

    return (0);
}