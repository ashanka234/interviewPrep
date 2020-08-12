#include<iostream>
using namespace std;

int minCost(int n, int p, int q) {
    int totalCost = 0;

    while(n) {
        if(n & 1) {     //odd number
            totalCost += p;
            n--;
        }
        else
        {

            if(n/2*p < q) {
                totalCost += n/2*p;
            }
            else
            {
                totalCost += q;
            }
            n = n/2;
        }
    }

    return totalCost;
}
            
int main() {
    int n = 9;
    int p = 5;
    int q = 1;

    cout << minCost(n, p, q) << endl;

    return (0);
}