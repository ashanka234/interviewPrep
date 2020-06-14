#include<iostream>
#include<cstring>
using namespace std;

void permutate(string s, int l, int r) {
    //base case
    if(l == r)  
        cout << s << endl;      //reached last char ie bottom row of treeab

    else {
        for(int i=l; i<=r; i++) {
            swap(s[l], s[i]);
            permutate(s, l+1, r);
            swap(s[l], s[i]);       //backtrack
        }
    }
}


//total n! permutations, takes n time to print each
// hence O(n * n!) complexity
int main() {
    string str;
    cin >> str;
    int n = str.length();

    permutate(str, 0, n-1);

    return (0);
}