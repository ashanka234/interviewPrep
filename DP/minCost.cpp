/* find min cost to reach N from 0
    2 operations allowed - add 1 (cost P) or multiply by 2(cost q)
*/

#include<iostream>
using namespace std;

int minCost(int n, int p, int q) {
    int cost = 0;

    //we will try to reach from n to 0
    while(n>0) {
        if(n&1) {       //if n is odd - only step to reach n would be to add 1 to n-1, cuz we cant divide odd no. by 2
            cost += p;
            n--;
        }
        else {
            int temp = n/2;

            if(q<temp*p) {
                cost += q;      //divide by 2
            }
            else
            {
                cost += (temp*p);       //going from n to n/2 is same as adding 1, n/2 times
            }
            n = n/2;
        }
    }

    return cost;
}

int minOperations(int n) {
    int res = 0;

    while(n>0) {
        if(n&1) {
            res++;
            n--;
        }
        else
        {
            res++;
            n = n/2;
        }
        
    }

    return res;
}

int main() {
    int n, p, q;
    //cin >> n >> p >> q;

    //cout << minCost(n, p, q) << endl;

    cin >> n;
    cout << minOperations(n) <<  endl;

    return (0);
}