#include<iostream>
#include<cstring>
using namespace std;

bool isRotated(string s1, string s2) {
    if(s1.length() != s2.length()) 
        return false;

    string clockwise = "";
    string anti_cloclwise = "";

    int len = s2.length();

    anti_cloclwise = anti_cloclwise + s2.substr(len-2, 2) + s2.substr(0, len-2); // (len-2 to len-1) + (0 to len-3)
    clockwise = clockwise + s2.substr(2, len) + s2.substr(0, 2);

    if(s1.compare(anti_cloclwise)==0 || s1.compare(clockwise)==0) 
        return true;
    else 
        return false;
}


int main() {
    string s1, s2;
    cin >> s1 >> s2;

    cout << isRotated(s1, s2) << endl;

    return (0);
}