#include<iostream>
#include<cstring>
using namespace std;

int getVal(char ch) {
    if(ch == 'I')
        return 1;
    if(ch == 'V')
        return 5;
    if(ch == 'X')
        return 10;
    if(ch == 'L')
        return 50;
    if(ch == 'C')
        return 100;
    if(ch == 'D')
        return 500;
    if(ch == 'M')
        return 1000;

    return -1;
}

int romanToInteger(string s) {
    int ans = 0;

    for(int i=0; i<s.length(); i++) {
        int s1 = getVal(s[i]);

        if(i+1 < s.length()) {
            int s2 = getVal(s[i+1]);

            if(s1>=s2) {     //agla number chota hai so directly add current
                ans +=s1;
            }
            else {      //agla bada hai so add the difference like IX is 10-1=9 
                ans += s2-s1;
                i++;        //dono milake ek number hai so go to next
            }
        }
        else {
            ans += s1;      //last number
        }
    }

    return ans;
}


int main() {
    string str;
    cin >> str;

    cout << romanToInteger(str) << endl;

    return (0);
}