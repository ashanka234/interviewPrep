#include<iostream>
#include<unordered_map>
using namespace std;


//this method includes negative elements in array
void subarraySum(int *arr, int n, int sum) {
    unordered_map<int, int> myMap; 
    int currSum = 0;

    for(int i=0; i<n; i++) {
        currSum += arr[i];

        if(currSum == sum)    //required subarray found starting from 0 to curr pos
        {
            cout << 0+1 << " " << i+1 << endl;
            return;     //ans found
        }

        if(myMap.find(currSum - sum) != myMap.end()) {      //req sum se jitna excess hai, 0 se starting utne ka subarray already exists so exclude that and rest is the req subarray 
            cout << myMap[currSum - sum] + 1 + 1<< " " <<  i+1 << endl;     //we need answer in 1 based indexing
            return;
        }
        myMap[currSum] = i;
    }

    cout << -1 << endl;
}


int main() {
    int t;
    cin >> t;       //t test cases

    while(t--) {
        int n, s;
        int *arr;
        cin >> n >> s;
        arr = new int[n];

        //input the array
        for(int i=0; i<n; i++) {
            cin >> arr[i];
        }

        subarraySum(arr, n, s);
    
    }

    return (0);
}