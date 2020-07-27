#include<iostream>
using namespace std;

bool isPowerOf2(int n) {
    if(n == 0)
        return false;

    //power of 2 is always like 1 followed by all 0's
    //if we subtract  1 from it, it become all 1's with the first bit 0
    //basically it will become compliment 
    //so if we take AND of both, we should get 0
    return (n & (n-1))==0;      //n-1 is the 1's compliment
}

int main() {
    int n;
    cin >> n;

    cout << isPowerOf2(n) << endl;
}