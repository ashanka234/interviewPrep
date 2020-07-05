/* tricky question - we are trying to beat the opponent, so at each chance we will maximise
    our own points, while  also minimse  the coins left for opponent 
*/

#include<iostream>
using namespace std;

int maxPoints(int *arr, int n) {
    int dp[n][n];       //dp[i][j] represents max value user can collect  if coins are from i to j

    //i and j are at a dist of 'gap'  from each other
    for(int gap=0; gap<n; gap++) {
        for(int i=0, j=gap; j<n; j++, i++) {
            int x = ((i+2)<=j)?
                    dp[i+2][j]:0;       //both chose coin from starting pos

            int y = (i+1 <= j-1)?
                    dp[i+1][j-1]:0;     //first chose from start, second  chose from end

            int z = (i<=j-2)?
                    dp[i][j-2]:0;       //both chose from last position

            dp[i][j] = max(arr[i] + min(x,y),       //chose from starting first, the min is because we have to minimse the possible points for opponent
                            arr[j] + min(z,y));     //chose from ending first,
        }
    }

    return dp[0][n-1];
}

int main() {
    int n;
    cin >> n;
    int *arr = new int[n];

    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }

    cout << maxPoints(arr, n) << endl;

    return (0);
}