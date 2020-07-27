#include<iostream>
#include<cmath>
using namespace std;

int rightmostSetBit(int n) {
    //V IMP TRICK - memorise this
    
    return log2(n & -n) + 1;
}


//it can be done by getting rightmost set bit of m^n
int rightmostDifferentBit(int n, int m) {
    return rightmostSetBit(m^n);
}

int main() {
    int n, m;
    cin >> n >> m;
    cout << rightmostDifferentBit(n, m) << endl;

    return (0);
}