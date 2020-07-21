/* important question - often asked in manuy modified forms */
/* it is similar to finding number of connected components in graph */

#include<iostream>
using namespace std;

#define row 5
#define col 5

bool isSafe(int mat[][col], int i, int j, bool visited[][col]) {
    if(i>=0 && i<row && j>=0 && j<col && mat[i][j]==1 && !visited[i][j])
        return true;

    return false;
}

void DFS(int mat[][col], int i, int j, bool visited[][col]) {
    //8 directions from each cell
    static int rowNum[] = {-1, -1, -1, 0, 0, 1, 1, 1};      //upar 3, beech mei 2, neeche 3
    static int colNum[] = {-1, 0, 1, -1, 1, -1, 0, 1};      //traversal horizontally

    visited[i][j] = true;

    for(int k=0; k<8; k++) {
        if(isSafe(mat, i+rowNum[k], j+colNum[k], visited))
            DFS(mat, i+rowNum[k], j+colNum[k], visited);
    }
}

int countIslands(int mat[][col]) {
    bool visited[row][col];
    //memset(visited, 0, sizeof(visited));
    for(int i=0; i<row; i++)
        for(int j=0; j<col; j++) 
            visited[i][j] = false;

    int res=0;

    for(int i=0; i<row; i++) {
        for(int j=0; j<col; j++) {
            if(mat[i][j]==1 && !visited[i][j]) {
                DFS(mat, i, j, visited);

                res++;      //each DFS call will cover one full island, so add that in count
            }
        }
    }

    return res;
}

int main() {
    int mat[][col] = { { 1, 1, 0, 0, 0 }, 
                     { 0, 1, 0, 0, 1 }, 
                     { 1, 0, 0, 1, 1 }, 
                     { 0, 0, 0, 0, 0 }, 
                     { 1, 0, 1, 0, 1 } };

    cout << countIslands(mat) << endl;

    return (0);
}