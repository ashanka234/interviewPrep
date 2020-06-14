#include<iostream>
#include<cstring>
using namespace std;

char *removeUtil(char *str, char *last_removed) {
    //if length is 0 or 1 base case
    if(str[0]=='\0' || str[1]=='\0') {
        return str;
    }

    //remove leftmost adjacent duplicates
    if(str[0] == str[1]) {
        *last_removed = str[0];

        while(str[1] && str[0]==str[1]) //recur for remaining till same character is there
        {
            str++;
        }
        str++;
        return removeUtil(str, last_removed);
    }

    //by now first char is different from second so uske aage ka dekhenge
    char *rem_str = removeUtil(str+1, last_removed);

    if(rem_str[0] && rem_str[0]==str[0]) {
        *last_removed = str[0];
        return (rem_str+1);
    }

    if(rem_str[0]=='\0' && *last_removed==str[0]) {
        return rem_str;
    }

    rem_str--;
    rem_str[0] = str[0];
    return rem_str;
}

char  *removeDuplicates(char *s) {
    char last_removed = '\0';
    return removeUtil(s, &last_removed);
}

int main() {
    char str[100];
    cin >> str;

    cout << removeDuplicates(str) << endl;

    return (0);
}