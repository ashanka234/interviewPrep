#include<iostream>
using namespace std;

void spiralPrint(int mat[10][10], int r, int c) {

    int l, m, n, k;
    //l - starting column
    //n - ending column
    //k - starting row
    //m - ending row

    int i;
    l=0; k=0;
    n = c;
    m = r;

    while(l<n && k<m)       //traverse starting to ending
    {
        for(i=l; i<n; i++) {        //top row
            cout << mat[k][i] << " " ;
        }    
        k++;

        for(i=k; i<m; i++) {        //right side column
            cout << mat[i][n-1] << " ";
        }
        n--;

        for(i=n-1; i>=l; i--) {     //bottom row
            cout << mat[m-1][i] << " ";
        }
        m--;

        for(i=m-1; i>=k; i--) {     //left side column
            cout << mat[i][l] << " ";
        }
        l++;
    }
}

int main() {
    int r, c;
    cin >> r >> c;

    int mat[10][10];
    for(int i=0; i<r; i++) {
        for(int j=0; j<c; j++) {
            cin >> mat[i][j];
        }
    }

    spiralPrint(mat, r, c);
    cout << endl;

    return (0);
}