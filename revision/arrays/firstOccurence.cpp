#include<iostream>
#include<cstring>
using namespace std;

int strstr(string s1, string s2) {
    if(s2.length() > s1.length())
        return -1;

    for(int i=0; i<s1.length(); i++) {
        if(s1[i] == s2[0]) {
            string sub = s1.substr(i, s2.length());

            if(s2.compare(sub) == 0)
                return i;
        }
    }

    return -1;
}

int main() {
    string s1, s2;
    cin >> s1 >> s2;

    cout << strstr(s1, s2) << endl;
    cout << s1.find(s2) << endl;

    return (0);
}