#include<iostream>
#include<cstring>
#include<unordered_map>
using namespace std;

int longestUniqueSubstr(string str) {
    unordered_map<char, int> lastIndex;
    int res=0;
    int i=0; 

    for(int j=0; j<str.length(); j++) {
        i = max(i, lastIndex[str[j]]+1);

        res = max(res, j-i+1);

        lastIndex[str[j]] = j;
    }

    return res;
}

int main() {
    string str = "geeksforgeeks";

    cout << longestUniqueSubstr(str) << endl;

    return (0);
}