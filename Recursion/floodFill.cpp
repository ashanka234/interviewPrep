#include<iostream>
using namespace std;

void floodFillUtil(int arr[][8], int x, int y, int prevColor, int newColor) {
    if(x<0 || x>=8 || y<0 || y>=8)
        return;

    if(arr[x][y] == newColor)
        return;
    if(arr[x][y] != prevColor)
        return;

    arr[x][y] = newColor;

    floodFillUtil(arr, x+1, y, prevColor,  newColor);
    floodFillUtil(arr, x-1, y, prevColor,  newColor);
    floodFillUtil(arr, x, y+1, prevColor,  newColor);
    floodFillUtil(arr, x, y-1, prevColor,  newColor);
}

void floodFill(int arr[][8], int x, int y, int newColor) {
    int prevColor = arr[x][y];
    floodFillUtil(arr, x, y, prevColor, newColor);
}

int main() {
    int grid[][8] = {{1, 1, 1, 1, 1, 1, 1, 1}, 
                      {1, 1, 1, 1, 1, 1, 0, 0}, 
                      {1, 0, 0, 1, 1, 0, 1, 1}, 
                      {1, 2, 2, 2, 2, 0, 1, 0}, 
                      {1, 1, 1, 2, 2, 0, 1, 0}, 
                      {1, 1, 1, 2, 2, 2, 2, 0}, 
                      {1, 1, 1, 1, 1, 2, 1, 1}, 
                      {1, 1, 1, 1, 1, 2, 2, 1}};

    int x=4, y=4, newColor=3;

    floodFill(grid, x, y, newColor);

    for(int i=0; i<8; i++) {
        for(int j=0; j<8; j++) {
            cout << grid[i][j] << " ";
        }
        cout << endl;
    }
}