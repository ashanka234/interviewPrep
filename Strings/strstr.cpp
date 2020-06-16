#include<iostream>
#include<cstring>
using namespace std;

//we need to find first occurence of s2 in s1 and return the starting index
int myStrStr(string s1, string s2) {
    if(s2.length() > s1.length())
        return -1;

    if(s2.length() == 0)
        return -1;
    
    for(int i=0; i<s1.length(); i++) {
        if(s1[i] == s2[0]) {
            string substring = s1.substr(i, s2.length());
            if(s2.compare(substring) == 0)
                return i;
        }
    }

    return -1;
}

int strstr2(string s, string x) {
    int found = s.find(x);
    return found;
}

int main() {
    string s1, s2;
    cin >> s1 >> s2;

    cout << myStrStr(s1, s2) << endl;
    cout << strstr2(s1, s2) << endl;


    return (0);
}