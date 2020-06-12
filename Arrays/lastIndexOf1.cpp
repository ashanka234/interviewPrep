#include<iostream>
#include<cstring>
using namespace std;

int getLastIndex(string s) {
    for(int i=s.length()-1; i>=0; i--) {
        if(s[i]&1) {
            return i;
        }
    }

    return -1;
}

int main() {
    string str;

    cin >> str;

    cout << getLastIndex(str) << endl;

    return (0);
}