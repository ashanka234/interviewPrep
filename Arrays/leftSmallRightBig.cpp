#include<iostream>
#include<algorithm>
#include<climits>
using namespace std;

//we need to get elemenet such that on left all ele are smaller and on right all are bigger
int getAns(int *arr, int n) {
    int *leftMax = new int[n];
    leftMax[0] = INT_MIN;

    for(int i=1; i<n; i++) {
        leftMax[i] = max(leftMax[i-1], arr[i-1]);       //leftMax[i] means max element to the left of current element
    }

    int rightMin = INT_MAX;

    for(int i=n-1; i>=0; i--) { 
        if(leftMax[i] < arr[i] && rightMin > arr[i])        //curr ke left pure mei jo max hai woh current se chota hona chahiye
                                                            //and right pure mei jo min hai woh current se bada hona chahiye
            return i;

        rightMin = min(rightMin, arr[i]);       //right subarray pure ka min element track rakhna hai
    }

    return -1;
    
}

int main() {
    int n;
    cin >> n;

    int *arr = new int[n];

    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }

    cout << getAns(arr, n) << endl;     //this method return index

    return (0);
}