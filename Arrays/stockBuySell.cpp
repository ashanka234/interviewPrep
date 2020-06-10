#include<iostream>
#include<algorithm>
#include<climits>
using namespace std;


//this method is if buying selling allowed only once
//basically we have to get max difference between 2 elements
// but greater element must come after smaller one
// ## we cant sort because order of elements is important ##
int getMaxProfit(int *arr, int n) {
    int maxProfit = arr[1] - arr[0];
    int minPrice = arr[0];

    for(int i=1; i<n; i++) {
        int profit = arr[i] - minPrice;
        if(profit > maxProfit)
            maxProfit = profit;
        
        if(arr[i] < minPrice)
            minPrice = arr[i];
    }

    return maxProfit;
}

//this method if we can buy sell multiple times
//still cant sort as order is important
int getMaxProfit_1(int *price, int n) {
    if(n==1)
        return -1;

    int netProfit = 0;
    int i=0;
    while(i < n-1) {
        //find local min for buy 
        while(i<n-1 && price[i]>=price[i+1])        //next price kam hai toh yaha nhi buy krna
        {
            i++;
        }
        if(i == n-1)        //no such condition possible -> no soln
            return -1;
        int buy = i;
        i++;

        //now find local max for selling
        while(i<n && price[i] >= price[i-1]) {
            i++;
        }

        int sell = i-1;     //yaha condition fullfill hui matlab yaha less ho gya h price than previous -> previous one is sell price
        netProfit += price[sell] - price[i];
        cout << "Buy on day " << buy << "\tSell on day " << sell << endl;

    }

    return netProfit;
}

int main() {
    int n;
    cin >> n;
    int *arr = new int[n];

    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }

    cout << getMaxProfit_1(arr, n) << endl;

    return (0);
}