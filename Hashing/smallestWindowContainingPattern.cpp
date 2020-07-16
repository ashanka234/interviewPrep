/* High level question */

#include<iostream>
#include<cstring>
#include<unordered_map>
#include<climits>
using namespace std;

string getSmallestWindow(string str, string pat) {
    int len1 = str.length();
    int len2 = pat.length();

    if(len2 > len1)
        return "";

    unordered_map<char, int> freq_str;
    unordered_map<char, int> freq_pat;

    for(int i=0; i<len2; i++) {
        freq_pat[pat[i]]++;
    }

    int start=0, start_idx=-1, minLen=INT_MAX;

    int count=0;
    for(int j=0; j<len1; j++) {
        freq_str[str[j]]++;

        if(freq_str[str[j]] <= freq_pat[str[j]]) {
            count++;
        }

        if(count==len2) {       //found pattern

            while(freq_str[str[start]] > freq_pat[str[start]] || freq_pat[str[start]]==0) {
                if(freq_str[str[start]] > freq_pat[str[start]]) {
                    freq_str[str[start]]--;
                }

                start++;
            }

            int windowLen = j - start + 1;
            if(minLen > windowLen) {
                minLen = windowLen;
                start_idx = start;
            }
        }
    }

    if(start_idx==-1) {
        return " ";
    }
    return str.substr(start_idx, minLen);
}

int main() {
    string s1, s2;
    cin >> s1 >> s2;

    cout << getSmallestWindow(s1, s2) << endl;

    return (0);
}