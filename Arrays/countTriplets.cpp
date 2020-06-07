#include<iostream>
#include<climits>
#include<algorithm>
using namespace std;

int countTriplets(int *arr, int n) {
    int maxVal=INT_MIN;
    for(int i=0; i<n; i++) {
        if(arr[i] > maxVal) 
            maxVal = arr[i];
    }

    int *freq = new int[maxVal+1];    //freq array 
    for(int i=0; i<=maxVal; i++)    
        freq[i] = 0;

    for(int i=0; i<n; i++)      //store freq of each element
    {
        freq[arr[i]]++;
    }

    int ways=0;

    //0,0,0 - f(0)C3
    ways += freq[0] * (freq[0]-1) * (freq[0]-2) / 6;

    //0,x,x - f(0) * f(x)C2
    for(int i=1; i<maxVal; i++) {
        ways += freq[0] * freq[i] * (freq[i]-1) / 2;
    }

    //x,x,2x - f(2x) * f(x)C2
    for(int i=1; 2*i <= maxVal; i++) {
        ways += freq[2*i] * freq[i] * (freq[i]-1) / 2;
    }

    //x,y,x+y - f(x)*f(y)*f(x+y)
    for(int i=1; i<=maxVal; i++) {
        for(int j=i+1; i+j<=maxVal; j++) {
            ways += freq[i] * freq[j] * freq[i+j];
        }
    }

    return ways;
}

//2nd method - easier
int countTriplets2(int *arr, int n) {
    sort(arr,arr+n);
    int j,k,ways=0;

    for(int i=0; i<n-2; i++) {
        j=i+1;      //j traverses from left 
        k=j+1;      //k traverses from right
        //first try consecutive triplet

        while(k<n) {
            if(arr[i] + arr[j] == arr[k])       //triplet found
            {
                ways++;
                j++;        //try next triplet
            }
            else if(arr[i] + arr[j] < arr[k]) {     //i is fixed, move j and k
                j++;
                k++;
            }

            k++;        //i,j fixed move k
        }
    }

    return ways;
}

int main() {
    int t;
    cin >> t;

    while(t--) {
        int n;
        int *arr;
        cin >> n;
        arr = new int[n];

        for(int i=0; i<n; i++) {
            cin >> arr[i];
        }

        cout << countTriplets2(arr, n) << endl;
    }

    return (0);
}