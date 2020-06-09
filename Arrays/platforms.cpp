#include<iostream>
#include<algorithm>
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