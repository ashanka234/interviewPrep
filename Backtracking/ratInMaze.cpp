/* name problem - typical ques */
#include<iostream>
#define n 4
using namespace std;

void printSolution(int arr[n][n]) {
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

bool isSafe(int maze[n][n], int x, int y) {
    if(x>=0 && x<n && y>=0 && y<n && maze[x][y]==1) 
        return true;

    return false;
}

bool solveMazeUtil(int maze[n][n], int x, int y, int sol[n][n]) {
    //reached goal (x,y)
    if(x==n-1 && y==n-1 && maze[x][y]==1) {
        sol[x][y] = 1;
        return true;
    }

    if(isSafe(maze, x, y)) {
        sol[x][y] = 1;
        if(solveMazeUtil(maze, x+1, y, sol) == true)        //move down
            return true;

        if(solveMazeUtil(maze, x,  y+1, sol)==true)     //move right
            return true;

        //backtrack - if  none of the above 2 worked then current cell is not part of solution
        sol[x][y] = 0;
        return false;
    }

    return false;
}

bool solveMaze(int maze[n][n]) {
    int sol[n][n] = { { 0, 0, 0, 0 }, 
                      { 0, 0, 0, 0 }, 
                      { 0, 0, 0, 0 }, 
                      { 0, 0, 0, 0 } };

    if(solveMazeUtil(maze, 0, 0, sol) == false)
        return false;
    
    printSolution(sol);
    return true;
}

int main() {
    int maze[n][n] = { { 1, 0, 0, 0 }, 
                       { 1, 1, 0, 1 }, 
                       { 0, 1, 0, 0 }, 
                       { 1, 1, 1, 1 } };

    solveMaze(maze);

    return (0);
}