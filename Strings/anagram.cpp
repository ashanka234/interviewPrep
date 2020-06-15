#include<iostream>
#include<cstring>
#include<unordered_map>
using namespace std;

bool isAnagram(string s1, string s2) {
    unordered_map<char, int> myMap(0);

    if(s1.length() != s2.length()) {
        return false;
    }

    for(int i=0; i<s1.length(); i++) {
        myMap[s1[i]]++;
    }

    for(int i=0; i<s2.length(); i++) {
        myMap[s2[i]]--;
    }

    unordered_map<char, int>::iterator it;
    for(it=myMap.begin(); it!=myMap.end(); it++) {
        if((*it).second != 0) {
            return false;
        }
    }

    return true;
}

int main() {
    string s1, s2;
    cin >> s1 >> s2;

    if(isAnagram(s1, s2)) {
        cout << "YES\n";
    }
    else {
        cout << "NO\n";
    }

    return (0);
}