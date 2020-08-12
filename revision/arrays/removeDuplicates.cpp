#include<iostream>
#include<cstring>
#include<set>
using namespace std;

string removeDuplicates(string str) {
    set<char> mySet;

    for(int i=0; i<str.length(); i++)
        mySet.insert(str[i]);

    string res = "";
    for(auto it=mySet.begin(); it!=mySet.end(); ++it) {
        res += *it;
    }

    return res;
}

int main() {
    string str = "geeksforgeeks";

    cout << removeDuplicates(str) << endl;

    return (0);
}