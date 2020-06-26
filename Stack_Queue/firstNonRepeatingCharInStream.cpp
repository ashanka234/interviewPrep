#include<iostream>
#include<queue>
#include<cstring>
using namespace std;

void printFirstNonRepeating(string str) {
    queue<char> q;
    int freq[27] = { 0 };

    for(int i=0; i<str.length(); i++) {
        q.push(str[i]);
        freq[str[i]-'a']++;     //considering only lower case chars are in the stream

        //check for first non repeating char
        while(!q.empty()) {
            if(freq[q.front()-'a'] > 1) {       //means it is repeating char
                q.pop();
            }
            else {
                cout << q.front() << " ";
                break;
            }
        }
        if(q.empty()) 
            cout << -1 << " ";
    }

    cout << endl;
}

int main() {
    string str;
    cin >> str;

    printFirstNonRepeating(str);
    cout << endl;

    return (0);
}