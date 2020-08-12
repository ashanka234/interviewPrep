#include<iostream>
#include<climits>
using namespace std;

int getMaxProfit(int *prices, int n) {
    int maxProfit = INT_MIN;
    int minPrice = prices[0];

    for(int i=1; i<n; i++) {
        int profit = prices[i] - minPrice;
        if(profit > maxProfit)
            maxProfit = profit;

        if(prices[i] < minPrice)
            minPrice = prices[i];
    }

    return maxProfit;
}

int getMaxProfit_1(int *prices, int n) {
    int profit = 0;
    int i=0; 

    while(i<n-1) {
        while(prices[i]>=prices[i+1] && i<n-1)
            i++;

        if(i == n-1)
            return -1;

        int buy = i;
        i++;

        while(i<n && prices[i]>=prices[i-1]) {
            i++;
        }
        int sell =  i-1;

        profit += prices[sell]-prices[buy];
    }

    return profit;
}

int main() {
    int price[] = { 100, 180, 260, 310, 40, 535, 695 }; 
    int n = sizeof(price)/sizeof(price[0]);

    cout << getMaxProfit(price, n) << endl;
    cout << getMaxProfit_1(price, n) << endl;

    return (0);
}