#include<iostream>
using namespace std;

int josephus(int n, int k) {
    if(n==1)
        return 1;       //if only 1 person, the  he is only the winner

    //this function returns the position considering the k%n+1 position as 1 position in each call
    //but we need answer wrt original 1 position, hence the k-1 adjustment
    return (josephus(n-1, k)+k-1)%n + 1;      //after kill, n-1 people left
                                        // then sword paased to the next person hence the +1
                                        //%n to handle the case if k > n toh ghumke aa jayega pura
}

int main() {
    int n, k;
    cin >> n >> k;

    cout << josephus(n, k) << endl;

    return (0);
}