#include<iostream>
#include<utility>
#include<algorithm>
using namespace std;

//we need to create an edge between 2 elements which will become in correct position after swapping wrt sorted array
int minSwaps(int *arr, int n) {
    pair<int, int>  arrayPos[n];        //first is arr[i], second is i (index)

    for(int i=0; i<n; i++) {
        arrayPos[i].first = arr[i];
        arrayPos[i].second = i;
    }

    sort(arrayPos, arrayPos+n);

    bool visited[n];
    for(int i=0; i<n; i++)
        visited[i] = false;

    int count=0;

    for(int i=0; i<n; i++) {
        if(visited[i]==true || arrayPos[i].second==i) 
            continue;       //no swapping required or already swapped 

        int cycleSize=0;
        int j = i;
        while(!visited[j]) {
            visited[j] = true;

            j = arrayPos[j].second;       //the second is storing its index position in original unsorted array
                                        //this step is like iterating to next node in the cycle, so we can traverse full cycle
            cycleSize++;
        }

        if(cycleSize>0) {
            count += (cycleSize-1);       //for cycle size of n, n-1 swaps are reauired
        }
    }

    return count;
}

int main() {
    int n;
    cin >> n;
    int *arr = new int[n];

    for(int i=0; i<n; i++)
        cin >> arr[i];

    cout << minSwaps(arr, n) << endl;

    return (0);
}