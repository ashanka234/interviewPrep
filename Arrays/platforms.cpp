#include<iostream>
#include<algorithm>
#include<utility>
#include<stack>
#include<vector>
using namespace std;

int getMaxPlatforms(int *arr, int *dep, int n) {
    sort(arr, arr+n);
    sort(dep, dep+n);

    int plats=1, ans=1;      //min 1 platform required
    int i=1, j=0;

    while(i<n && j<n) {

        if(arr[i] <= dep[j]) {      //train has arrived and standing at platform
            plats++;
            i++;
        }

        else if(arr[i] > dep[j]) {      //train has departed
            plats--;
            j++;
        }

        ans = max(ans, plats);
    }

    return ans;
}


//alternate method using stack
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
    int n;
    cin >> n;

    int *arr = new int[n];
    int *dep = new int[n];

    for(int i=0; i<n; i++)
        cin >> arr[i];
    for(int i=0; i<n; i++)
        cin >> dep[i];

    cout << getMaxPlatforms(arr, dep, n) << endl;

    return (0);
}