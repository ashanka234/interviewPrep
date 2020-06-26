/* difficult ques, unlikely to be asked */
#include<iostream>
#include<queue>
using namespace std;

int r, c;

struct ele {
    int x;
    int y;
};

//check if cell is valid
bool isValid(int i, int j) {
    if(i>=0 && j>=0 && i<r && j<c) {
        return true;
    }

    return false;
}

//check if current one is delimitter ie (-1. -1)
bool isDelimitter(ele temp) {
    return (temp.x==-1 && temp.y==-1);
}

//check if grid contains any fresh orange
bool checkFreshOranges(int arr[3][5]) {
    for(int i=0; i<r; i++) {
        for(int j=0; j<c; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    for(int i=0; i<r; i++) {
        for(int j=0; j<c; j++) {
            if(arr[i][j] == 1) {
                return true;        //there are fresh oranges present
            }
        }
    }

    return false;
}

int rotOranges(int arr[3][5]) {
    queue<ele> q;
    ele temp;
    int ans = 0;

    for(int i=0; i<r; i++) {
        for(int j=0; j<c; j++) {
            if(arr[i][j] == 2) {        //push all rotten oranges into queue
                temp.x = i;
                temp.y = j;
                q.push(temp);
            }
        }
    }

    //now push a delimitter after first pass, at the rear
    temp.x = -1;
    temp.y = -1;
    q.push(temp);

    //now make the neighbour oranges rotten
    while(!q.empty()) {
        bool flag = false;      //it will become true if atleast one orange is made rotten in this current iteration of rotting
        
        //process all elements till delimitter
        while(!isDelimitter(q.front())) {
        
            temp = q.front();

            //now check all 4 neighbours
            if(isValid(temp.x+1, temp.y) && arr[temp.x=1][temp.y]==1) {       //down 
                if(!flag) {     //it is the first orange to get rotten in this iteration
                    flag = true;
                    ans++;      //increase the time. it will be increased only for the first orange to rot in each iteration
                }
                arr[temp.x+1][temp.y] = 2;   //rot it
                temp.x++;
                q.push(temp);

                temp.x--;       //bring back to current cell to check others
            }

            if(isValid(temp.x-1, temp.y) && arr[temp.x-1][temp.y]==1) {       //up
                if(!flag) ans++, flag=true;
                arr[temp.x-1][temp.y] = 2;
                temp.x--;
                q.push(temp);       

                temp.x++;
            }

            if(isValid(temp.x, temp.y+1) && arr[temp.x][temp.y+1]==1) {       //right
                if(!flag) ans++, flag=true;
                arr[temp.x][temp.y+1] = 2;
                temp.y++;
                q.push(temp);

                temp.y--;
            }

            if(isValid(temp.x, temp.y-1) && arr[temp.x][temp.y-1]==1) {       //left
                if(!flag) ans++, flag=true;
                arr[temp.x][temp.y-1] = 2;
                temp.y--;
                q.push(temp);

                temp.y++;
            }
            
            //current orange has rotted all possible. now pop it
            q.pop();
        }       
        //all the newly rotted oranges are pushed after the delimitter
        //all oranges of current iteration finished. Now pop delimitter
        q.pop();

        //push new delimitter if queue has the next set of oranges 
        if(!q.empty()) {
            temp.x = -1;
            temp.y = -1;
            q.push(temp);
        }
    }
    //cout << ans << endl;
    
    //we have rotted all oranges that was possible
    if(checkFreshOranges(arr))      //grid still has fresh oranges present. means not possible to rot all
        return -1; 
    
    else 
        return ans;
}

int main() {
    
    //int r, c;
    /*cin >> r >> c;

    for(int i=0; i<r; i++) {
        for(int j=0; j<c; j++) {
            cin >> arr[r][c];
        }
    } */

    r = 3; c = 5;
    int arr[][5] = {{2, 1, 0, 2, 1}, 
                    {1, 0, 1, 2, 1}, 
                    {1, 0, 0, 2, 1}};

    cout << rotOranges(arr) << endl;

    return (0);
}