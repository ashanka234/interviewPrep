#include<iostream>
#include<cstring>
using namespace std;

int AtoI(string s) {
    if(s=="")
        return 0;

    int res = 0;
    int sign = 1;

    int i=0;
    if(s[i] == '-') {
        sign = -1;
        i++;
    }

    while(i < s.length()) {
        if(s[i]>='0' && s[i]<='9') {
            res = res*10 + (s[i]-'0');
        }
        else
            return false;

        i++;    
    }

    return sign*res;
}

int main() {
    string s;
    cin >> s;

    cout << AtoI(s) << endl;

    return (0);
}