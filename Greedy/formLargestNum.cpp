#include<iostream>
using namespace std;


//we have to form the largest number having digit sum s, and no. of digits d
void largestNum(int s, int d) {
    int res[d];

    for(int i=0; i<d; i++) {
        if(s>=9) {
            res[i] = 9;
            s -= 9;
        }
        else
        {
            res[i] = s;
            s = 0;
        }      
    }

    for(int i=0; i<d; i++)
        cout << res[i];
    cout << endl;
}

int main() {
    int s, d;
    cin >> s >> d;

    largestNum(s, d);

    return (0);
}