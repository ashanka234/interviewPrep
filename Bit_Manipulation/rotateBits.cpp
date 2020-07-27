#include<iostream>
using namespace std;

int leftRotate(int n, unsigned int d) {

    //first part will shift left normal half
    //second part will append the rotated part to the end using OR
    return (n<<d) | (n>>(32-d));        //32 because INT is 32 bit
}

int rightRotate(int n, unsigned int d) {
    return (n>>d) | (n<<(32-d));
}

int main() {
    int n, d;
    cin >> n >> d;

    cout << leftRotate(n, d) << endl;
    cout << rightRotate(n, d) << endl;

    return (0);
}