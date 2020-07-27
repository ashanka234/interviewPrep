#include<iostream>
using namespace std;

bool isKthBitSet(int n, int k) {
    //return (1<<(k-1)) & n;      //using left shift

    return (n>>(k-1)) & 1;      //using right shift
}

int main() {
    int n, k;
    cin >> n >> k;

    cout << isKthBitSet(n, k) << endl;

    return (0);
}