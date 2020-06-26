#include<iostream>
#include<queue>
using namespace std;

struct myStack {
    queue<int> q1;
    queue<int> q2;

    //push operation costly
    void push(int x) {
        if(!q1.empty()) {
            while(!q1.empty()) {
                q2.push(q1.front());
                q1.pop();
            }
        }

        q1.push(x);

        while(!q2.empty()) {
            q1.push(q2.front());
            q2.pop();
        }
    }

    int pop() {
        if(!q1.empty()) {
            int x = q1.front();
            q1.pop();

            return x;
        }

        return -1;
    }
};

struct myStack1 {
    queue<int> q1;
    queue<int> q2;

    void push(int x) {
        q1.push(x);
    }

    //pop operation is costly
    int pop() {
        if(!q1.empty()) {
            while(q1.size() > 1) {
                q2.push(q1.front());
                q1.pop();
            }
        }

        int x = q1.front();
        q1.pop();

        while(!q2.empty()) {
            q1.push(q2.front());
            q2.pop();
        }
        
        return x;
    }
};

int main() {
    myStack1 st;
    st.push(4);
    st.push(3);
    st.push(2);
    st.push(1);

    cout << st.pop() << endl;
    cout << st.pop() << endl;
    cout << st.pop() << endl;
    cout << st.pop() << endl;

    return (0);
}