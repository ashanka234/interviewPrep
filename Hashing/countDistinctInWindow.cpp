#include<iostream>
#include<unordered_map>
using namespace std;

void countDistinct(int *arr, int n, int k) {
    unordered_map<int, int> mp;
    int count = 0;      //this is the count of distinct in each window

    for(int i=0; i<k; i++) {
        if(mp[arr[i]] == 0)     //if appearing first time in the window
            count++;
        mp[arr[i]] += 1;
    }

    cout << count << endl;      //answer of first window

    for(int i=k; i<n; i++) {
        if(mp[arr[i-k]] == 1)       //i-k is the element which is first of previous window. Now window has shifted 
                                    //by 1 step so the first element will not be part of the window now
            count--;                //this element is removed so we cant count it as distinct element

        mp[arr[i-k]]--;     //reduce count of this element by 1 as it is not part of window. but same element can be present in window also

        if(mp[arr[i]] == 0)
            count++;        //distinct element found
        mp[arr[i]]++;
        
        cout << count << endl;      //result of current window
    }
}

int main() {
    int arr[] = { 1, 2, 1, 3, 4, 2, 3 }; 
    int n = sizeof(arr)/sizeof(int);
    int k = 4;

    countDistinct(arr, n, k);

    return (0);
}