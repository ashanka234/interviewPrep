#include<iostream>
using namespace std;


//important method, used many times
int countSetBits(int n) {
    int count=0;

    while(n) {
        count++;
        n = n & (n-1);
    }
    return count;
}

int getDifference(int n1, int n2) {
    //this can be done by simply counting set bits in n1^n2
    return countSetBits(n1^n2);
}

int main() {
    int n1, n2;
    cin >> n1 >> n2;

    cout << getDifference(n1, n2) << endl;

    return (0);
}