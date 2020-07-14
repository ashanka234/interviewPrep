#include<iostream>
#include<unordered_map>
using namespace std;

void findQuadruplet(int *arr, int n, int X) {
    unordered_map<int, pair<int, int> > mp;     //it will store sum of pair mapped to the pair itself
    for(int i=0; i<n-1; i++) {
        for(int j=i+1; j<n; j++) {
            mp[arr[i]+arr[j]] = make_pair(i,j);
        }
    }

    for(int i=0; i<n-1; i++) {
        for(int j=i+1; j<n; j++) {
            int sum =  arr[i] + arr[j];

            if(mp.find(X - sum) != mp.end()) {      //if remaining sum excluding current 2 nos. exists in hash
                pair<int, int> p = mp[X-sum];

                //check that all 4 are unique
                if(p.first!=i && p.first!=j && p.second!=i && p.second!=j) {
                    cout << arr[i] << " " << arr[j] << " "
                    << arr[p.first] << " " << arr[p.second] << endl;
                    return;     //ans found
                }
            }
        }
    }
    cout << "Not found\n";
}

int main() {
    int arr[] = { 10, 20, 30, 40, 1, 2 }; 
    int n = sizeof(arr)/sizeof(int);
    int X = 91; 

    findQuadruplet(arr, n, X);
    cout << endl;

    return (0);
}