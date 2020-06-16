#include<iostream>
#include<cstring>
using namespace std;

string getPrefixUtil(string prefix, string str) {
    string res="";

    for(int i=0, j=0; i<prefix.length() && j<str.length(); i++, j++) {
        if(prefix[i] != str[j]) 
            break;

        res = res + prefix[i];
    }

    return res;
}

string getPrefix(string *arr, int n) {
    string prefix = arr[0];

    for(int i=0; i<n; i++) {
        prefix = getPrefixUtil(prefix, arr[i]);
    }

    return prefix;
}

int main() {
    int n;
    cin >> n;

    string *arr = new string[n];

    for(int i=0; i<n; i++)
        cin >> arr[i];

    cout << getPrefix(arr, n) << endl;

    return (0);
}