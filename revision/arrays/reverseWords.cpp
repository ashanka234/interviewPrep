#include<iostream>
#include<cstring>
#include<vector>
using namespace std;

string reverseWords(string str) {
    int word_end = 0;
    int word_begin = 0;

    string res = "";
    string word;
    vector<string> reversedWords;

    for(int i=0; i<str.length(); i++) {

        if(str[i] == ' ' || i==str.length()-1) {     //one word end
            word_end = i-1;

            //extract current word
            if(i==str.length()-1) 
                word = str.substr(word_begin, word_end - word_begin+2);
            else 
                word = str.substr(word_begin, word_end - word_begin+1);
            //cout << word << endl;

            word_begin = word_end + 2;

            //reverse current word
            reverse(word.begin(), word.end());
            //cout << word << endl;
            reversedWords.push_back(word);
        }
    }

    //put into res in reverse order of appearance
    for(int i=reversedWords.size()-1; i>=0; i--) {
        res += (reversedWords[i] + " ");
    }

    return res;
}

int main() {
    string sentence = "i love to code";
    //cin >> sentence;

    cout << reverseWords(sentence) << endl;

    return (0);
}