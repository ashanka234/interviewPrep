/* Difficult question */
#include<iostream>
#include<vector>
using namespace std;

class PetrolPump {
public:
    int petrol;
    int distance;
};

int printTour(vector<PetrolPump> arr) {
    int start = 0;
    int end = 1;

    int curr_petrol = arr[start].petrol - arr[start].distance;

    while(curr_petrol<0 || start!=end) {        //find first one where petrol is less than distance
        while(curr_petrol<0 && start!=end) {        //if curr-petrol become negative, then remove this one from start as we cannot start from here
            //dont consider these ones 
            curr_petrol -= arr[start].petrol - arr[start].distance;
            start = (start+1) % arr.size();      //useful trick for circular traversal of array

            if(start == 0)
                return -1;      //again 0 being considered as start, so no solution possuble
        }

        //add current petrol pump
        curr_petrol += arr[end].petrol - arr[end].distance;
        end = (end+1)%arr.size();
    }

    return start;
}

int main() {
    vector<PetrolPump> arr;
    int n;
    cin >> n;

    while(n--) {
        int petrol, distance;
        PetrolPump petrolPump;
        cin >> petrol >> distance;
        petrolPump.petrol = petrol;
        petrolPump.distance = distance;
        arr.push_back(petrolPump);
    }

    cout << printTour(arr) << endl;

    return (0);
}