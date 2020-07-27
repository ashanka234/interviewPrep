#include<iostream>
using namespace std;

int setKthBit(int n, unsigned int k) {
    return ((1<<k) | n);        //memorise
}

int main() {
    int n, k;
    cin >> n >> k;

    cout << setKthBit(n, k) << endl;

    return (0);
}