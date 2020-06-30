/* Frequently asked question - high difficulty */
#include<iostream>
#include<vector>
using namespace std;

void findNumbers(vector<int> &arr, int sum, vector<vector<int> > &res, vector<int> &r, int i) {
    if(sum < 0)
        return;

    if(sum==0)  //means this array is one correct combination 
    {
        res.push_back(r);
        return;
    }

    //here we will form each combination
    while(i<arr.size() && sum-arr[i]>=0) {
        r.push_back(arr[i]);

        findNumbers(arr, sum-arr[i], res, r, i);
        i++;

        //if not correct then remove this element from combination - BACKTRACK
        r.pop_back();
    }
}

vector<vector<int> > combinationSum(vector<int> &arr, int sum) {
    sort(arr.begin(), arr.end());

    //IMPORTANT TRICK TO REMOVE DUPLICATES USING STL
    arr.erase(unique(arr.begin(), arr.end()), arr.end());

    vector<int> r;
    vector<vector<int> > res;
    findNumbers(arr, sum, res, r, 0);       //last one is iterator for indidividial array combinations 

    return res;
}

int main() {
    int n, x;
    vector<int> arr;

    cin >> n;
    while(n--) {
        int num;
        cin >> num;
        arr.push_back(num);
    }

    cin >> x;       //required sum

    vector<vector<int> > res = combinationSum(arr, x);      //vector of vector where each vector is one ans

    /* print all answers */
    for(int i=0; i<res.size(); i++) {
        if(res[i].size() > 0) {
            for(int j=0; j<res[i].size(); j++) {
                cout << res[i][j] << " ";
            }
            cout << endl;
        }
    }

    return (0);
}