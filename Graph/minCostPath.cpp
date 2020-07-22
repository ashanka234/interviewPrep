/** in this question we can travel left right up down all 4 sides
 * so we cant use DP appraoch.
 * We will use Dijsktra's algorithm here
 */

#include<iostream>
#include<set>
#include<climits>
using namespace std;

#define row 5
#define col 5

struct cell {
    int x;
    int y;
    int dist;

    cell(int x, int y, int dist) {
        this->x = x;
        this->y = y;
        this->dist = dist;
    }
};

bool operator<(const cell &a, const cell &b) {      //operator overloading < to compare 2 cells
    if(a.dist == b.dist) {
        if(a.x != b.x)
            return a.x < b.x;
        else
            return a.y < b.y;
    }

    return a.dist < b.dist;
}

bool isSafe(int i, int j) {
    if(i>=0 && i<row && j>=0 && j<col)
        return true;

    return false;
}

int shortestPath(int grid[row][col]) {
    /* for(int i=0; i<row; i++) {
        for(int j=0; j<col; j++) 
            cout << grid[i][j] << " ";
        cout << endl;
    }
    cout << endl; */

    int dis[row][col];
    for(int i=0; i<row; i++) {
        for(int j=0; j<col; j++) 
           dis[i][j] = INT_MAX;
    }

    int rowNum[] = {-1, 0, 1, 0};       //up, right, down, left
    int colNum[] = {0, 1, 0, -1};

    set<cell> st;

    st.insert(cell(0,0,0));     //cell with x,y as 0,0 and dist also 0
    dis[0][0] = grid[0][0];

    while(!st.empty()) {
        cell k = *st.begin();
        st.erase(st.begin());

        //now look at all 4 neighbours
        for(int i=0; i<4; i++) {
            int x = k.x + rowNum[i];
            int y = k.y + colNum[i];

            if(!isSafe(x, y))
                continue;

            if(dis[k.x][k.y]+grid[x][y] < dis[x][y]) {
                if(dis[x][y] != INT_MAX) {
                    st.erase(st.find(cell(x, y, dis[x][y])));
                }

                dis[x][y] = dis[k.x][k.y] + grid[x][y];
                st.insert(cell(x, y, dis[x][y]));
            }
        }
    }

    /* for(int i=0; i<row; i++) {
        for(int j=0; j<col; j++) 
            cout << dis[i][j] << " ";
        cout << endl;
    } */
    
    return dis[row-1][col-1];
}

int main() {
    
    int grid[row][col] = { {31, 100, 65, 12, 18} , 
                            {10, 13, 47, 157, 6}, 
                            {100, 113, 174, 11, 33}, 
                            {88, 124, 41, 20, 140}, 
                            {99, 32, 111, 41, 20} };

    cout << shortestPath(grid) << endl;

    return (0);
}