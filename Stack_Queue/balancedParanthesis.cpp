#include<iostream>
#include<stack>
#include<cstring>
using namespace std;

bool isBalanced(string str) {
    stack<char> st;

    for(int i=0; i<str.length(); i++) {
        if(str[i]=='(' || str[i]=='[' ||  str[i]=='{') {        //if opening bracket, then push to stack
            st.push(str[i]);
        }

        else {      //str[i] is closing bracket
            char ch;
            switch(str[i]) {
                case ')' : ch = st.top();
                        st.pop();
                        if(ch != '(')
                            return false;
                        break;
                case ']' : ch = st.top();
                        st.pop();
                        if(ch != '[')
                            return false;
                        break;
                case '}' : ch = st.top();
                        st.pop();
                        if(ch != '{')
                            return false;
                        break;
            }
        }
    }

    return true;
}

int main() {
    string str;
    cin >> str;

    cout << isBalanced(str) << endl;

    return (0);
}