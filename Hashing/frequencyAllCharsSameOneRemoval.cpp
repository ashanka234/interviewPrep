#include<iostream>
#include<unordered_map>
#include<cstring>
using namespace std;

bool isAllSameFreq(unordered_map<char, int> &mp) {

    unordered_map<char, int>::iterator it = mp.begin();
    int sameFreq = it->second;
    it++;
    for(; it!=mp.end(); it++) {
        if(it->second>0 && it->second != sameFreq)
            return false;
    }

    return true;
}

bool isPossibleAllCharsSameFrequencyOneRemoval(string &str) {

    int l = str.length();
    unordered_map<char, int> mp;

    for(int i=0; i<l; i++)
        mp[str[i]]++;

    if(isAllSameFreq(mp))
        return true;

    for(auto it=mp.begin(); it!=mp.end(); it++) {
        it->second--;       //try to remove this char once
        if(isAllSameFreq(mp))
            return true;
        it->second++;       //if failed then put it back
    }

    return false;
}

int main() {
    string str;
    cin >> str;

    cout << isPossibleAllCharsSameFrequencyOneRemoval(str) << endl;

    return (0);
}