#include<iostream>
using namespace std;

void removeAdjDuplicates(char *str) {
    if(str[0] == '\0')
        return;

    if(str[0] == str[1]) {      //adj duplicate found
        //shift left
        int i=0;
        while(str[i] != '\0') {
            str[i] = str[i+1];
            i++;
        }
        removeAdjDuplicates(str);
    }

    //if adj duplicate not found
    removeAdjDuplicates(str+1);
}

int main() {
    char str[] = "aabccd";
    int n = sizeof(str)/sizeof(str[0]);

    removeAdjDuplicates(str);
    cout << str << endl;

    return (0);
}