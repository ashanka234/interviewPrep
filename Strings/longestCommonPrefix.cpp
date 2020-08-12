#include<iostream>
#include<cstring>
using namespace std;

string getPrefixUtil(string prefix, string str) {
    string res="";

    //check if this prefix is in the current string, or till where its present
    for(int i=0, j=0; i<prefix.length() && j<str.length(); i++, j++) {
        if(prefix[i] != str[j]) 
            break;

        res = res + prefix[i];
    }

    return res;
}


//using word matching
string getPrefix(string *arr, int n) {
    string prefix = arr[0];

    for(int i=0; i<n; i++) {
        prefix = getPrefixUtil(prefix, arr[i]);
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
    int n;
    cin >> n;

    string *arr = new string[n];

    for(int i=0; i<n; i++)
        cin >> arr[i];

    cout << getPrefix(arr, n) << endl;

    return (0);
}