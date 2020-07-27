/* number is sparse if no 2 or more consecutive bits are set */

#include<iostream>
using namespace std;

bool isSparse(int n) {
    // n & n/2 should be 0 for sparse

    return !(n & (n>>1));       //n>>1 is same as n/2
}

int main() {
    int n;
    cin >> n;

    cout << isSparse(n) << endl;

    return (0);
}