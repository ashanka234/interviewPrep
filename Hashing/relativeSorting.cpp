#include<iostream>
#include<unordered_map>
#include<vector>
#include<algorithm>
using namespace std;

void sortRelative(int *arr1, int *arr2, int n1, int n2) {
    unordered_map<int, int> freq;
    vector<int> res;

    //store frequency of  each element
    for(int i=0; i<n1; i++) {
        freq[arr1[i]]++;
    }

    for(int i=0; i<n2; i++) {
        if(freq.find(arr2[i]) != freq.end()) {
            int count = freq[arr2[i]];
            for(int j=1; j<=count; j++)     //put the curr element of arr2 in res as many times as it appears in arr1
                res.push_back(arr2[i]);
            freq.erase(arr2[i]);        //then remove from map
        }
    }

    vector<int> remainingArray;
    unordered_map<int, int>::iterator it = freq.begin();
    while(it!=freq.end()) {                         //put the remaining elements i.e the ones not appearing in arr2, into a vector
                                                    //this is done only so we can sort them
        remainingArray.push_back(it->first);
        it++;
    }

    sort(remainingArray.begin(), remainingArray.end());
    for(int i=0; i<remainingArray.size(); i++) {        //put remianing elements into res
        res.push_back(remainingArray[i]);
    }

    //display answer
    for(int i=0; i<n1; i++)
        cout << res[i] << " ";
    cout << endl;
}

int main() {
    int arr1[] = { 2, 1, 2, 5, 7, 1, 9, 3, 6, 8, 8 }; 
    int arr2[] = { 2, 1, 8, 3 }; 
    int n1 = sizeof(arr1) / sizeof(arr1[0]); 
    int n2 = sizeof(arr2) / sizeof(arr2[0]); 

    sortRelative(arr1, arr2, n1, n2);
    
    return (0);
}