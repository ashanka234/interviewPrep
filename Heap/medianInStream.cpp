/* Very commonly asked queston */

#include<iostream>
#include<queue>
#include<vector>
using  namespace std;

void getMedians(double *arr, int n) {
    priority_queue<double> s;       //min heap for smaller elements  - greatest will be on top
    priority_queue<double, vector<double>, greater<double> > g;     //max heap for greater elements  -- smallest will be on top

    double median = arr[0];
    s.push(arr[0]);
    cout << median << " ";

    for(int i=1; i<n; i++) {
        double x = arr[i];

        if(s.size() > g.size()) {       //left heap greater than right heap
            if(x<median) {
                g.push(s.top());        
                s.pop();
                s.push(x);
            }
            else
            {
                g.push(x);
            }

            median = (s.top() + g.top())/2.0;
        }

        else if(s.size() == g.size()) {
            if(x<median) {
                s.push(x);
                median = (double) s.top();
            }
            else
            {
                g.push(x);
                median = (double) g.top();
            }
        }

        else {
            if(x>median) {
                s.push(g.top());
                g.pop();
                g.push(x);
            }
            else
            {
                s.push(x);
            }
            median = (s.top() + g.top())/2.0;
        }

        cout << median << " ";
    }
}

int main() {
    double arr[] = {5, 15, 10, 20, 3}; 
    int n = sizeof(arr)/sizeof(arr[0]); 

    getMedians(arr, n);
    cout << endl;

    return (0);
}