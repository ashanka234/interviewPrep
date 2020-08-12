#include<iostream>
#include<algorithm>
using namespace std;

struct Box {
    int h;
    int w; 
    int d;
};

bool myCompare(Box b1, Box b2) {
    return (b1.w*b1.d > b2.w*b2.d);
}

int getMaxHeight(Box *arr, int n) {
    Box rotations[3*n];
    int itr=0;

    for(int i=0; i<n; i++) {
        rotations[itr].h = arr[i].h;
        rotations[itr].d = max(arr[i].d, arr[i].w);
        rotations[itr].w = min(arr[i].d, arr[i].w);
        itr++;

        rotations[itr].h = arr[i].w;
        rotations[itr].d = max(arr[i].d, arr[i].h);
        rotations[itr].w = min(arr[i].d, arr[i].h);
        itr++;

        rotations[itr].h = arr[i].d;
        rotations[itr].d = max(arr[i].h, arr[i].w);
        rotations[itr].w = min(arr[i].h, arr[i].w);
        itr++;
    }

    sort(rotations, rotations+(3*n), myCompare);

    /* for(int i=0; i<3*n; i++) {
        cout << rotations[i].h << " " << rotations[i].w << " " << rotations[i].d << endl;
    } */

    int maxHeight = 0;
    int dp[3*n];
    for(int i=0; i<3*n; i++)
        dp[i] = rotations[i].h;

    for(int i=1; i<3*n; i++) {
        for(int j=0; j<i; j++) {
            if(rotations[i].w<rotations[j].w && rotations[i].d<rotations[j].d)
                dp[i] = max(dp[i], dp[j] + rotations[i].h);
        }
    }

    for(int i=0; i<3*n; i++) {
        /* cout << dp[i] << " "; */
        maxHeight = max(maxHeight, dp[i]);
    } cout << endl;

    return maxHeight;
}

int main() {
    Box arr[] = { {4, 6, 7}, {1, 2, 3}, {4, 5, 6}, {10, 12, 32} };
    int n = sizeof(arr)/sizeof(arr[0]);

    cout << getMaxHeight(arr, n) << endl;

    return (0);    
}