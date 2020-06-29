/* count all paths from top left to bottom right of matrix
can move only right or down */

#include<iostream>
using namespace std;

int paths(int x, int y) {
    if(x==1 || y==1)
        return 1;

    return paths(x-1, y) + paths(x, y-1);
}

int main() {
    cout << paths(3,3) << endl;

    return (0);
}