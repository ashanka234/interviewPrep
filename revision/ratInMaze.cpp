#include<iostream>
using namespace std;

#define N 4

void printSolution(int sol[][N]) {
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            cout << sol[i][j] << " ";
        }
        cout << endl;
    }
}

bool isSafe(int maze[][N], int x, int y) {
    if(x>=0 && x<N && y>=0 && y<N && maze[x][y]==1)
        return true;

    return false;
}

bool solveMazeUtil(int maze[][N], int sol[][N], int x, int y) {
    if(x==N-1 && y==N-1 && maze[x][y]==1) {
        sol[x][y] = 1;
        return true;
    }

    if(isSafe(maze, x, y)) {
        sol[x][y] = 1;

        if(solveMazeUtil(maze, sol, x+1, y))
            return true;
        if(solveMazeUtil(maze, sol, x, y+1))
            return true;

        sol[x][y] = 0;
        return false;
    }

    return false;
}

bool solveMaze(int maze[][N]) {
    int sol[N][N] = { { 0, 0, 0, 0 }, 
                      { 0, 0, 0, 0 }, 
                      { 0, 0, 0, 0 }, 
                      { 0, 0, 0, 0 } };

    if(!solveMazeUtil(maze, sol, 0, 0))
        return false;

    printSolution(sol);
    return true;
}

int main() {
    int maze[N][N] = { { 1, 0, 0, 0 }, 
                       { 1, 1, 0, 1 }, 
                       { 0, 1, 0, 0 }, 
                       { 1, 1, 1, 1 } };

    solveMaze(maze);

    return (0);
}