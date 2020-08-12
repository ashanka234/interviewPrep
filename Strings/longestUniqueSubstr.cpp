#include<iostream>
#include<cstring>
#include<unordered_map>
using namespace std;


// O(n^2) solutioin
int getLongestUniqueSubstr(string s) {
    int n = s.length();
    int res = 0;

    unordered_map<char, bool> visited(false);

    for(int i=0; i<n; i++) {
        for(int j=i; j<n; j++) {
            if(visited[s[j]] == true)       //current window mei yeh wala already aa chuka hai so try next window
                break;

            else {
                res = max(res, j-i+1);      //current wale ko include kara answer window mei
                visited[s[j]] = true;
            }
        }
        visited[s[i]] = false;        //remove first char of prev window
    }

    return res;
}

// O(n) solution
int getLongestUniqueSubstr_1(string s) {
    //cout << "here 0\n";
    int n = s.length();
    //cout << "here 1\n";
    int res = 0;
    //cout << "here 2\n";

    unordered_map<char, int> lastIndex;
    //cout << "here 3\n";
    int i=0;        //window starting
    
    //cout << "here 4\n";
    for(int j=0; j<n; j++) {        //ending of window
        //cout << "here 5\n";
        i = max(i, lastIndex[s[j]]+1);      //+1 because lenght is increasing by 1

        res = max(res, j-i+1);
        lastIndex[s[j]] = j;
    }

    return res;
}

int main() {
    string s;
    cin >> s;

    cout << getLongestUniqueSubstr(s) << endl;
    cout << getLongestUniqueSubstr_1(s) << endl;

    return (0);
}