//Count pairs such that x^y > y^x
//use: if y>x then x^y>y^x
#include<iostream>
using namespace std;

int main() {
    int t;
    cin >> t;

    while(t--)
    {
        int m, n;
        cin >> m >> n;
        int *X = new int[m];
        int *Y = new  int[n];

        for(int i=0; i<m; i++)
            cin >> X[i];
        for(int i=0; i<n; i++)
            cin >> Y[i];
        
    }
}