#include<iostream>
#include<utility>
#include<climits>
#include<queue>
using namespace std;

#define row 9
#define col 10

struct qNode {
    pair<int, int> pt;
    int dist;
};

bool isValid(int i, int j) {
    if(i>=0 && i<row && j>=0 && j<col)
        return true;

    return false;
}

int BFS(int mat[row][col], pair<int, int> &src, pair<int, int> &dest) {
    if(mat[src.first][src.second]==0 || mat[dest.first][dest.second]==0)
        return -1;      //src and dest cells cant be 0 value

    bool visited[row][col];
    memset(visited, false, sizeof(visited));

    visited[src.first][src.second] = true;      //current cell mark as visited

    queue<qNode> q;

    qNode s = {src, 0};
    q.push(s);

    while(!q.empty()) {
        qNode curr = q.front();
        q.pop();

        pair<int, int> pt = curr.pt;

        //if reached dest
        if(pt.first==dest.first && pt.second==dest.second)
            return curr.dist;       //answer found

        int rowNum[] = {-1, 0, 0, 1};       //up, left,  right, down
        int colNum[] = {0, -1, 1, 0};

        for(int i=0; i<4; i++) {        //cuz only 4 directions are possible from current cell
            int r = pt.first + rowNum[i];
            int c = pt.second + colNum[i];

            if(isValid(r,c) && mat[r][c]==1 && !visited[r][c]) {
                visited[r][c] = true;
                qNode nextCell = {make_pair(r, c), curr.dist+1};

                q.push(nextCell);
            }
        }
    } 

    return -1;      //not able to reach destination
}

int main() {
    int mat[row][col] = 
    { 
        { 1, 0, 1, 1, 1, 1, 0, 1, 1, 1 }, 
        { 1, 0, 1, 0, 1, 1, 1, 0, 1, 1 }, 
        { 1, 1, 1, 0, 1, 1, 0, 1, 0, 1 }, 
        { 0, 0, 0, 0, 1, 0, 0, 0, 0, 1 }, 
        { 1, 1, 1, 0, 1, 1, 1, 0, 1, 0 }, 
        { 1, 0, 1, 1, 1, 1, 0, 1, 0, 0 }, 
        { 1, 0, 0, 0, 0, 0, 0, 0, 0, 1 }, 
        { 1, 0, 1, 1, 1, 1, 0, 1, 1, 1 }, 
        { 1, 1, 0, 0, 0, 0, 1, 0, 0, 1 } 
    }; 

    pair<int, int> src = make_pair(0, 0);
    pair<int, int> dest = make_pair(3, 4);

    int dist = BFS(mat, src, dest);

    (dist!=INT_MAX)? cout<<dist : cout << "-1";
    cout << endl;

    return (0);
}