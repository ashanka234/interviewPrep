#include<iostream>
#include<stack>
using namespace std;


//here Enqueue operation is costly
struct myQueue1 {
    stack<int> s1, s2;

    void enqueue(int x) {
        while(!s1.empty()) {    //transfer all elements from s1 to s2
            s2.push(s1.top());
            s1.pop();       
        }
    

        s1.push(x);

        //now put everything back in s1
        //matlab naya wala element sabse neeche insert ho gya i.e. it will get out last
        while(!s2.empty()) {
            s1.push(s2.top());
            s2.pop();
        }
    }

    int dequeue() {
        if(!s1.empty()) {
            int x = s1.top();
            s1.pop();

            return x;
        }
    }
};

//here dequeue is costly
struct myQueue2 {
    stack<int> s1, s2;

    void enqueue(int x) {
        s1.push(x);
    }

    int dequeue() {
        if(s1.empty() && s2.empty()) {
            return -1;
        }


        //agar s1 mei sab hai toh ulta krke nikalo
        //s2 mei sab hai toh direct top nikal do because ulte order mei stored hai
        if(s2.empty()) {        
            while(!s1.empty()) {
                s2.push(s1.top());      //s2 mei ulte order mei ghuse hai so if s1 is empty and content is in s2, then directly
                                        //return the top element
                s1.pop();
            }
        }

        int x=s2.top();     
        s2.pop();

        return x;
    }
};

int main() {
    myQueue1 q1;
    myQueue2 q2;

    q1.enqueue(1); 
    q1.enqueue(2);
    q1.enqueue(3);
    cout << q1.dequeue() << endl;

    q2.enqueue(4);
    q2.enqueue(5);
    q2.enqueue(6);
    cout << q2.dequeue() << " " << q2.dequeue() << endl;

    return (0);
}