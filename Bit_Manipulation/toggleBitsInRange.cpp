#include<iostream>
using namespace std;

unsigned int toggleBits(unsigned int n, unsigned int l, unsigned int r) {

    //this will create a mask in which set bits are from l to r position
    //memorise this to create masking array
    int mask = ((l<<r)-1) ^ ((1 << (l-1)) - 1);

    return (n^mask);  //use XOR with 1 to flip bits
}

int main() {
    unsigned int n, l, r;
    cin >> n >> l >> r;

    cout << toggleBits(n, l, r) << endl;

    return (0);
}