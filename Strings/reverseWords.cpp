#include<iostream>
#include<cstring>
using namespace std;

void reverse(char *start, char *end) {
    char temp;
    while(start < end) {
        temp = *start;
        *start = *end;
        *end = temp;
        start++; end--;
    }
}

void reverseWords(char *str) {
    char *word_begin = str;
    char *temp = str;

    while(*temp) {
        temp++;

        if(*temp == '\0') {     //last word
            reverse(word_begin, temp-1);
        }

        else if(*temp == ' ') {
            reverse(word_begin, temp-1);
            word_begin = temp+1;    //next word start
        }
    }

    reverse(str, temp-1);
}

int main() {
    char str[100];
    //cin >> str;
    cin.getline(str, 100);
    //char str[] = "i love to do programming";
    reverseWords(str);

    cout << str << endl;

    return (0);
}