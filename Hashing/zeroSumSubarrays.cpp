#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;

vector<pair<int, int> > getSubarrays(int *arr, int n) {
    unordered_map<int, vector<int> > mp;

    vector<pair<int, int> > res;        //each pair will store starting and ending index of subarray

    int sum=0;      //subarray sum

    for(int i=0; i<n; i++) {
        sum += arr[i];

        if(sum==0) {        //zero sum subarray found from 0 to current index
            res.push_back(make_pair(0, i));
        }

        //if sum already exists in map, then there must've been one subarray from any index to any index (till i) 
        //which contributed zero sum
        if(mp.find(sum) != mp.end()) {
            vector<int> vc = mp[sum];

            for(auto it=vc.begin(); it!=vc.end(); it++) {
                res.push_back(make_pair(*it+1, i));
            }
        }

        mp[sum].push_back(i);      //store the index till which its making the current sum
    }

    return res;
}

int main() {
    int arr[] = {6, 3, -1, -3, 4, -2, 2, 4, 6, -12, -7}; 
    int n = sizeof(arr)/sizeof(arr[0]); 

    vector<pair<int,int> > res = getSubarrays(arr, n);

    for(auto it=res.begin(); it!=res.end(); it++) {
        cout << it->first << " to " << it->second << endl;
    }
    cout << endl;

    return (0);
}