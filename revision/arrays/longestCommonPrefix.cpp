#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

string lcpUtil(string str, string prefix) {
    string res = "";

    for(int i=0, j=0; i<str.length() && j<prefix.length(); i++, j++) {
        if(str[i] != prefix[j])
            break;
        res += prefix[j];
    }

    return res;
}

//using word matching
string lcp(string *arr, int n) {
    string prefix = arr[0];

    for(int i=0; i<n; i++) {
        prefix = lcpUtil(arr[i], prefix);
    }

    return prefix;
}

//using sorting
string lcp_2(string arr[], int n) {
    if(n==0)
        return 0;

    if(n==1)
        return arr[0];

    sort(arr, arr+n);

    int len = min(arr[0].length(), arr[n-1].length());
    string first = arr[0];
    string last = arr[n-1];

    int i=0;
    while(i<len && first[i]==last[i])
        i++;

    return first.substr(0, i);
}

int main() {
    string arr[] = {"geeksforgeeks", "geeks",  "geek", "geezer"}; 
    int n = sizeof(arr) / sizeof(arr[0]); 

    cout << lcp(arr, n) << endl;
    cout << lcp_2(arr, n) << endl;

    return (0);
}