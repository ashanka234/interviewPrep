#include<iostream>
#include<cstring>
#include<unordered_map>
using namespace std;

bool isAnagram(string s1, string s2) {
    unordered_map<char, int> freq;

    for(int i=0; i<s1.length(); i++)
        freq[s1[i]]++;

    for(int i=0; i<s2.length(); i++)
        freq[s2[i]]--;

    for(unordered_map<char, int>::iterator it=freq.begin(); it!= freq.end(); ++it) {
        if(it->second != 0)
            return false;
    }

    return true;
}

int main() {
    string s1, s2;
    cin >> s1 >> s2;

    cout << isAnagram(s1, s2) << endl;

    return (0);
}