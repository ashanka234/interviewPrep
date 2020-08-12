#include<iostream>
#include<algorithm>
#include<stack>
#include<vector>
#include<utility>
using namespace std;

bool myCompare(pair<int, char> p1, pair<int, char> p2) {
    return p1.first < p2.first;         //sort based on time
}

int platforms(int *arr, int *dep, int n) {
    vector<pair<int, char> > v;       //'a' for arrival times, 'd' for departure times

    for(int i=0; i<n; i++) {
        pair<int, char> p = make_pair(arr[i], 'a');
        v.push_back(p);
    }

    for(int i=0; i<n; i++) {
        pair<int, char> p = make_pair(dep[i], 'd');
        v.push_back(p);
    }

    sort(v.begin(), v.end(), myCompare);

    stack<int> st;
    int res = 0, plats=1;

    for(int i=0; i<v.size(); i++) {
        if(v[i].second == 'a') {
            st.push(v[i].first);
            res++;
            plats = max(plats, res);
        }
        else
        {
            st.pop();
            res--;
        }    
    }
    return plats;
}

int main() {
    /* int arr[] = { 900, 940, 950, 1100, 1500, 1800 }; 
    int dep[] = { 910, 1200, 1120, 1130, 1900, 2000 }; */
    int arr[] = {900, 940};
    int dep[] = {910, 1200};
    int n = sizeof(arr) / sizeof(arr[0]); 

    cout << platforms(arr, dep, n) << endl;

    return (0);
}