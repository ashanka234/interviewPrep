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

int toRoman(string str) {
    int res = 0;

    for(int i=0; i<str.length(); i++) {
        int n1 = getVal(str[i]);

        if(i+1 < str.length()) {
            int n2 = getVal(str[i+1]);

            if(n2 > n1) {
                res += (n2-n1);
                i++;
            }
            else
            {
                res += n1;
            }  
        }
        else
        {
            res += n1;
        }
    }

    return res;
}

int main() {
    string str;
    cin >> str;

    cout << toRoman(str) << endl;

    return (0);
}