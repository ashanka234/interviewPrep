/* HIGH LEVEL QUES 
A - print A
ctrl A - select all
ctrl C - copy
ctrl v - past 
using these 4 we have to print max no. of A's. 
we can only press n number of keys */

#include<iostream>
#include<algorithm>
using namespace std;

int getMaxA(int n) {
    //for n up to 6, max we can do is print all A's n times
    if(n<=6)
        return n;

    int res = 0;

    int b;      //breakpoint - yaha tak all A's, then copy paste the same string n-b times
    //for select+copy+past we need 3 presses
    for(b=n-3; b>=1; b--) {
        int curr = (n-b-1) * getMaxA(b);        //if b is breakpoint, then repeating string is till n-b-1, and of length b 
                                                //in the remaining n-b presses, we will just paste the same n-b times
                                                //last 3 presses for select copy paste
        res = max(curr, res);                                       
    }

    return res;
}

int main() {
    int n;
    cin >> n;

    cout << getMaxA(n) << endl;

    return (0);
}