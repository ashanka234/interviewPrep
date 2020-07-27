#include<iostream>
using namespace std;

int countSetBits(int n) {
    int res = 0;

    while(n) {
        if(n&1)
            res++;
        n = n >> 1;
    }

    return res;
}

int main() {
    int n;
    cin >> n;

    cout << countSetBits(n) << endl;

    return (0);
}