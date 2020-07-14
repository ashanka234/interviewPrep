#include<iostream>
#include<unordered_map>
using namespace std;


//split the arr into pairs so that sum of each pair is divisible by k
bool isPairSum(int *arr, int n, int k) {
    if(n&1)
        return false;       //odd length array cannot be divided into pairs

    unordered_map<int, int> mp;     //this will store remainders when divided by k

    for(int i=0; i<n; i++)
        mp[arr[i]%k]++;

    for(int i=0; i<n; i++) {
        int rem = arr[i] % k;

        if(2*rem == k) {        //if current remainder divides k into 2, since we need to split into pairs
            if(mp[rem]%2 != 0)        //there should be even no. of occurences
                return false;
        }

        else if (rem == 0) {
            if(mp[rem]&1 == 0)
                return false;       //there must be even no. of times the element occurs in order to form pairs
        }

        else if(mp[rem] != mp[k-rem]) {    
            return false;       //freq of rem shoudl be same as freq of k-rem cuz we need both elements of pair same no. of times
        }
    }

    return true;
}

int main() {
    int arr[] =  {92, 75, 65, 48, 45, 35}; 
    int n = sizeof(arr) / sizeof(int);
    int k = 10; 

    cout << isPairSum(arr, n, k) << endl;

    return (0);
}