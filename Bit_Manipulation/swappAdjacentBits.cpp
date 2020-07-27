#include<iostream>
using namespace std;

int swapAdjacent(int n) {
    int evenBits = n & 0xAAAAAAAA;      //8 times A in hex is a 32 bit no. with all even bits as 1 and all odd bits as 0
    int  oddBits = n & 0x55555555;      //same 32 bit no. with odd bits 1 and even bits 0

    //even position bit will be swapped with the odd bit to its right 
    evenBits = evenBits>>1;
    oddBits = oddBits<<1;

    return evenBits | oddBits;
}

int main() {
    int n;
    cin >> n;

    cout << swapAdjacent(n) << endl;

    return (0);
}