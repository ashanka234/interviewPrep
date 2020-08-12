#include<iostream>
#include<stack>
using namespace std;

class MyStack {
    stack<int> st;
    int minEle;

public:
    void push(int);
    int pop();
    int getMin();
    int peek();
};

void MyStack::push(int d) {
    if(st.empty()) {
        st.push(d);
        minEle = d;
    }
    else if(d < minEle) {
        st.push(2*d - minEle);
        minEle = d;
    }
    else
    {
        st.push(d);
    }
 }

 int MyStack::pop() {
     if(!st.empty()) {
        int t = st.top();
        st.pop();

        if(t < minEle) {
            int x = minEle;
            minEle = 2*minEle - t;

            return x;
        }
        else
            return t;
     }
 }

 int MyStack::getMin() {
    if(!st.empty())
        return minEle;
 }

 int MyStack::peek() {
     if(!st.empty()) {
        int t = st.top();

        if(t < minEle)
            return t;
        else 
            return minEle;
     }
 }

int main() {
    MyStack s; 
    s.push(3); 
    s.push(5); 
    cout << s.getMin() << endl;
    s.push(2); 
    s.push(1); 
    cout << s.getMin() << endl; 
    cout << s.pop() << endl; 
    cout << s.getMin() << endl; 
    cout << s.pop() << endl; 
    cout << s.peek() << endl; 

    return (0);
}