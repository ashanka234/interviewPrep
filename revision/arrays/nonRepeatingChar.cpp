#include<iostream>
#include<queue>
#include<cstring>
#include<unordered_map> 
using namespace std;

void printNonRepeatingChars(string s) {
    unordered_map<char, int> freq;
    queue<char> q;

    for(int i=0; i<s.length(); i++) {
        q.push(s[i]);
        freq[s[i]]++;

        while(!q.empty()) {
            char ch = q.front();
            if(freq[ch] > 1) 
                q.pop();
            else  {
                cout << ch << " ";
                break;
            }
        }

        if(q.empty()) {
            cout << -1 << " ";
        }
    }
    cout << endl;
}

int main() {
    string s = "aabc";
    printNonRepeatingChars(s);

    return (0);
}