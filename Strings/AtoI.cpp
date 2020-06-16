#include<iostream>
#include<cstring>
using namespace std;

bool isNumeric(char ch) {
    return (ch >='0' && ch <='9') ? true : false;
}

int myAtoI(string s) {
    if(s == "")
        return 0;

    int res = 0;
    int sign = 1;

    int i=0;

    if(s[i] == '-')
    {
        sign = -1;
        i++;
    }

    for(;i<s.length(); i++) {
        if(!isNumeric(s[i]))
            return false;

        res = res*10 + (s[i]-'0');
    }

    return sign*res;
}


int main() {
    string s;

    cin >> s;

    cout << myAtoI(s) << endl;

    return (0);
}