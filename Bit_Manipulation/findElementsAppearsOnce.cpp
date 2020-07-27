/* all other elements occur twice (can be given as thrice also) 
    find the element which occurs once only 
*/

#include<iostream>
using namespace std;

int findLonelyInCouple(int *arr, int n) {
    //xor of number with itself is 0
    //xor of number with 0 is itself
    //just do xor of all

    int x = 0;
    for(int i=0; i<n; i++) {
        x = x ^ arr[i];
    }

    return x;
}

int main() {
    int n;
    cin >> n;
    int *arr = new int[n];
    for(int i=0; i<n; i++)
        cin >> arr[i];

    cout << findLonelyInCouple(arr, n) << endl;

    return (0);
}