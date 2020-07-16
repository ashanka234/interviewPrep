#include<iostream>
#include<cstring>
#include<unordered_map>
#include<climits>
using namespace std;

char minIndexChar(string str, string patt) {
    int minIndex = INT_MAX;
    unordered_map<char, int> mp;

    for(int i=0; i<str.length(); i++) {
        if(mp.find(str[i]) == mp.end())
            mp[str[i]] = i;
    }

    for(int i=0; i<patt.length(); i++) {
        if(mp.find(patt[i]) != mp.end() && mp[patt[i]] < minIndex) {
            minIndex = mp[patt[i]];
        }
    }

    if(minIndex != INT_MAX) {
        return str[minIndex];
    }
    return '\0';
} 

int main() {
    string str, patt;
    cin >> str >> patt;

    cout << minIndexChar(str, patt) << endl;

    return (0);
}