/* V IMP QUES - often asked in different forms but same concept.
    sometimes they can add  different cost also for each operation
*/

#include<iostream>
#include<cstring>
using namespace std;


//we've to  convert s1 into s2 with min no. of steps
// 3 operatins - insert, remove, replace
int editDistance(string s1, string s2, int m, int n) {
    int dp[m+1][n+1];       //dp[i][j] represents min steps required to convert s1 till i, into s2 till j

    for(int i=0; i<=m; i++) {
        for(int j=0; j<=n; j++) {
            if(i==0) 
                dp[i][j] = j;       //insert all char of s2 total j no. of chars 

            else if(j==0)
                dp[i][j] = i;       //remove all chars of s2

            else if(s1[i-1] == s2[j-1])     //if char is same then dont do anything, continue to previous char
                dp[i][j] = dp[i-1][j-1];

            else        //chars are diff, so we have to consider all 3 operations
            {
                dp[i][j] = 1 + min(dp[i][j-1],      //insert - s1 mei insert kra to make last chars equal, s2 remains same so come to previous char
                                min(dp[i-1][j],     //remove - s1 ka last remove kra, so now come 1 char back in s1
                                    dp[i-1][j-1]));     //replace-dono ka last same bana diya, so now come one char previous in both
            }
            
        }
    }

    return dp[m][n];
}

int main() {
    string s1, s2;
    cin >> s1 >> s2;

    cout << editDistance(s1, s2, s1.length(), s2.length()) << endl;

    return (0);  
}