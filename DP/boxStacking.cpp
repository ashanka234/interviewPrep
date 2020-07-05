/* V IMP QUES - asked in Goldman Sachs 
    its a variation of longest increasing subsequence. here consider each rotation of a box as separate box
    then follow same algo of LIS to maximise height
*/

#include<iostream>
#include<algorithm>
using namespace std;

struct Box {
    //height, width, depth
    int h;      //height
    int w;      //breadth
    int d;      //length
};

bool myCompare(Box b1, Box b2) {
    return ((b1.d*b1.w) > (b2.d*b2.w));     //sort in increasing order of base area
}

int  maxStackHeight(Box *arr, int n) {

    Box rot[3*n];        //each box can be rotated in 3 ways, each rotation will be saved as  individual box
    int index = 0;      //iterator for new rot array
    int res = -1;

    for(int i=0; i<n; i++) {
        //make all 3 rotations  by fixing one,  and adjusting other two -  memorise this order
        rot[index].h = arr[i].h;
        rot[index].d = max(arr[i].d, arr[i].w);
        rot[index].w = min(arr[i].d, arr[i].w);
        index++;

        rot[index].h = arr[i].w;
        rot[index].d = max(arr[i].d, arr[i].h);
        rot[index].w = min(arr[i].d, arr[i].h);
        index++;

        rot[index].h = arr[i].d;
        rot[index].d = max(arr[i].h, arr[i].w);
        rot[index].w = min(arr[i].h, arr[i].w);
        index++;
    }


    //now we will only work w new rot array
    n = 3*n;
    sort(rot, rot+n, myCompare);

    int dp[n];      //dp[i] represents the max height possible with i boxes
    for(int i=0; i<n; i++)
        dp[i] = rot[i].h;       //min  height can be height of each one individual box

    for(int i=1; i<n; i++) {
        for(int j=0; j<i; j++) {
            //base area of lower one must be greater than the one on top of it
            if(rot[i].w<rot[j].w && rot[i].d<rot[j].d && dp[i]<dp[j]+rot[i].h) {
                    dp[i] = dp[j] + rot[i].h;           //including the current should increase max height till previous
            }
        }
    }

   /* for(int i=0; i<n; i++)
        cout << rot[i].h << " ";
    cout << endl;

    for(int i=0; i<n; i++)
        cout << dp[i] << " ";
    cout << endl; */

    for(int i=0; i<n; i++)
        res = max(res, dp[i]);

    return res;
}

int main() {
    Box arr[] = { {4, 6, 7}, {1, 2, 3}, {4, 5, 6}, {10, 12, 32} };  //4 boxes
    int n = sizeof(arr)/sizeof(Box);

    cout << maxStackHeight(arr, n) << endl;

    return (0);
}