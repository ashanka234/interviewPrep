#include<iostream>
using namespace std;

struct PetrolPump {
    int petrol;
    int dist;
};

int tourStart(PetrolPump *arr, int n) {
    int start=0; 
    int end=1;

    int curr_petrol = arr[start].petrol - arr[start].dist;

    while(start!=end || curr_petrol<0) {
        while(start!=end && curr_petrol<0) {
            curr_petrol -= (arr[start].petrol - arr[start].dist);
            start = (start+1)%n;

            if(start==0)
                return -1;
        }

        curr_petrol += (arr[end].petrol - arr[end].dist);
        end = (end+1)%n;
    }

    return start;
}

int main() {
    PetrolPump arr[] = {{6, 4}, {3, 6}, {7, 3}};
    int n = sizeof(arr)/sizeof(arr[0]);

    cout << tourStart(arr, n) << endl;

    return (0);
}