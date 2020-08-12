#include<iostream>
#include<cstring>
using namespace std;

bool isRotated(string s1, string s2) {
    int n = s1.length();
    string clockwise = s1.substr(n-2, 2) + s1.substr(0, n-2);
    string anticlockwise = s1.substr(2, n-2) + s1.substr(0, 2);

    //cout << clockwise << " " << anticlockwise << endl;

    return (s2.compare(clockwise) || s2.compare(anticlockwise));
}

int main() {
    string s1 = "amazon";
    string s2 = "azonam";

    cout << isRotated(s1, s2) << endl;

    return (0);
}