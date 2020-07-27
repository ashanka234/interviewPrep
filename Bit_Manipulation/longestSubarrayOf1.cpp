#include<iostream>
using namespace std;

int maxConsecutive1s(int n) {
    int res = 0;

    while(n) {
        n = n & (n << 1);       //this will reduce the length of each subsequence of 1's by 1
        res++;
    }

    return res;
}

int main() {
    int n;
    cin >> n;

    cout << maxConsecutive1s(n) << endl;

    return (0);
}