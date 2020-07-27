#include<iostream>
using namespace std;

int findFirstSetBit(int n) {
    int i=1;
    int m = 1;

    while(!(n & m)) {
        m = m<<1;
        i++;
    }

    return i;
}

int main() {
    int n;
    cin >> n;

    cout << findFirstSetBit(n) << endl;

    return (0);
}