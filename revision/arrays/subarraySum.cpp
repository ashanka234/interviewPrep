#include<iostream>
#include<unordered_map>
using namespace std;

void subarraySum(int *arr, int n, int sum) {
    unordered_map<int, int> map;
    int currSum = 0;

    for(int i=0; i<n; i++) {
        currSum += arr[i];
        
        if(currSum == sum) {
            cout << 0 << " to " << i << endl;
            return;
        }

        if(map.find(currSum-sum) != map.end()) {
            cout << map[currSum-sum]+1 << " to " << i << endl;
            return;
        }

        map[currSum] = i;
        //currSum=0;
    }

    cout << "not found\n";
}

int main() {
    int arr[] = {1, 4, 20, 3, 10, 5};
    int n = sizeof(arr)/sizeof(arr[0]);

    int sum = 27;

    subarraySum(arr, n, sum);

    return (0);
}