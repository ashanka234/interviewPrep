#include<iostream>
using namespace std;
#define N 4

void spiralPrint(int mat[][N]) {
    int l, m, n, k;
    //l = starting column
    //n = ending column
    //m = ending row
    //k = starting row
    int i;
    l=0; k=0;
    n=N-1; m=N-1;

    while(l<=n && k<=m) {
        for(int i=l; i<=n; i++) {
            cout << mat[k][i] << " ";
        }
        k++;

        for(i=k; i<=m; i++) {
            cout << mat[i][n] << " ";
        }
        n--;

        for(i=n; i>=l; i--) {
            cout << mat[m][i] << " ";
        }
        m--;

        for(i=m; i>=k; i--) {
            cout << mat[i][l] << " ";
        }
        l++;
    }
}

int main() {
    int mat[][N] = { {1, 2, 3, 4},
                     {5, 6, 7, 8},
                     {9, 10, 11, 12}, 
                     {13, 14, 15, 16} };
    
    spiralPrint(mat);
    cout << endl;

    return (0);
}