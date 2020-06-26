/* We have to get minimum element in O(1) time and O(1) space */
#include<iostream>
#include<stack>
using namespace std;

struct myStack {
    stack<int> st;
    int minEle;

    void push(int x) {
        if(st.empty()) {
            minEle = x;
            st.push(x);
            return;
        }

        if(x<minEle) {
            st.push(2*x - minEle);
            minEle = x;
        }
        else
        {
            st.push(x);
        }
    }

    int pop() {
        if(!st.empty()) {
            int t = st.top();
            st.pop();

            if(t<minEle) {
                int x = minEle;
                minEle = 2*minEle - t;

                return x;
            }
            else {
                return t;
            }
        }
    }

    int getMin() {
        if(!st.empty()) {
            return minEle;
        }
    }

    int peek() {
        if(!st.empty()) {
            int t= st.top();

            if(t<minEle)
                return minEle;
            else
                return t;
        }
    }
};

int main() {
    int n;
    cin >> n;

    myStack st;

    while(n--) {
        int num;
        cin >> num;
        st.push(num);
    }

    cout << st.getMin() << endl;
    cout << st.pop() << endl;
    cout << st.peek() << endl;
    cout << st.getMin() << endl;

    return (0);

}