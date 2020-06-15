#include<iostream>
#include<cstring>
#include<unordered_map>
using namespace std;

string removeDuplicates(string s) {
    unordered_map<char, int> myHash(0);
    string ans = "";
    
    for(int i=0; i<s.length(); i++) {
        if(myHash.find(s[i]) == myHash.end()) {     //char first time aa rha hai
            ans = ans + s[i];
            myHash[s[i]]++;
        }
    }

    return ans;
}

int main() {
    string str;
    cin >> str;

    cout << removeDuplicates(str) << endl;

    return (0);
}