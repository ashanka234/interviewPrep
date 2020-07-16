#include<iostream>
#include<unordered_set>
#include<cstring>
using namespace std;

char getFirstRepeatingChar(string str) {
    unordered_set<char> s;       //set stores only distinct characters, retrieval in O(n) time

    for(int i=0; i<str.length(); i++) {
        char ch = str[i];

        if(s.find(ch) != s.end())       //repeating character found; we dont need to explicitely check if the distance between the 
                                        //occurences of the char is least, its automatically adjusted
            return ch;

        else 
            s.insert(ch);
    }

    return '\0';
}

int main() {
    string s;
    cin >> s;

    cout << getFirstRepeatingChar(s) << endl;

    return (0);
}