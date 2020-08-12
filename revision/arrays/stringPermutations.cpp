#include<iostream>
#include<cstring>
using namespace std;

void permutateUtil(string s, int l, int r) {
    if(l==r)
        cout << s << endl;

    else {
        for(int i=l; i<=r; i++) {
            swap(s[l], s[i]);
            permutateUtil(s, l+1, r);
            swap(s[l], s[i]);

        }
    }
}

void permutate(string s) {
    int l=0;
    int r = s.length()-1;

    permutateUtil(s, l, r);
}

int  main() {
    string s = "abc";

    permutate(s);
    cout << endl;

    return (0);
}