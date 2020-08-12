#include<iostream>
#include<stack>
#include<cstring>
using namespace std;

bool isBalanced(string s) {
    stack<char> st;

    for(int i=0; i<s.length(); i++) {
        //opening bracket
        if(s[i]=='(' || s[i]=='[' || s[i]=='{') {
            st.push(s[i]);
        }

        //closing bracket
        else
        {
            if(i==0 && st.empty())
                return false;

            char ch = st.top();
            st.pop();

            switch(s[i]) {
                case '}' : if(ch != '{') 
                                return false;
                            break;
                case ']' : if(ch != '[')
                                return false;
                            break;
                case ')' : if(ch != '(')
                                return false;
                            break;
            }
        }
    }

    return true;
}

int main() {
    string s1 = "[()]{}{[()()]()}";
    string s2 = "[(])";
    string s3 = "}([]){";

    cout << isBalanced(s1) << endl;
    cout << isBalanced(s2) << endl;
    cout << isBalanced(s3) << endl;

    return (0); 
}