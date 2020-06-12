#include<iostream>
#include<algorithm>
#include<cstring>
#include<vector>
using namespace std;

bool myCompare(string X, string Y) {
    string XY = X.append(Y);
    string YX = Y.append(X);

    if(XY.compare(YX))
        return true;
    else 
        return false;
}

void printLargestNum(vector<string> arr) {
    sort(arr.begin(), arr.end(), myCompare);

    for(int i=0; i<arr.size(); i++) {
        cout << arr[i];
    }
}

int main() {
    vector<string> arr;

    int n;
    string num;
    cin >> n;

    for(int i=0; i<n; i++) {
        cin >> num;
        arr.push_back(num);
    }

    printLargestNum(arr);
    cout << endl;

    return (0);
}