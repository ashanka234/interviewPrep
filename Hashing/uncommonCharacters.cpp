#include<iostream>
#include<cstring>
#include<unordered_map>
#include<set>
using namespace std;

void printUncommon(string s1, string s2) {
    unordered_map<char, int> mp;
    set<char> res;

    for(int i=0; i<s1.length(); i++) {
        mp[s1[i]]=1;        //this char is coming only in s1
    }

    for(int i=0; i<s2.length(); i++) {
        if(mp.find(s2[i]) == mp.end())
            res.insert(s2[i]);      //char belongs to s2 but not s1
        else
            mp[s2[i]] = 2;  //common character found
    }


    for(int i=0; i<s1.length(); i++) {
        if(mp[s1[i]]==1)        //char belongs to s1 but not s2
            res.insert(s1[i]);
    }

    for(auto it=res.begin(); it!=res.end(); it++) {
        cout << *it << " ";
    }
}

int main() {
    string s1, s2;
    cin >> s1 >> s2;

    printUncommon(s1, s2);
    cout << endl;

    return (0);
}