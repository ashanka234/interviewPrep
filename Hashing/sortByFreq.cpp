#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;

bool myCompare(pair<int, int> &p1, pair<int, int> &p2) {
    if(p1.second==p2.second)        //if freq same of 2 elements, the smaller element comes first
        return p1.first<p2.first;
    
    return p1.second > p2.second;       //element w figher freq comes first
}

void sortByFreq(int *arr, int n) {
    map<int, int> freq;

    /* for(int i=0; i<arr.size(); i++) 
        cout << arr[i] << " ";
    cout << "size "<< arr.size() << endl; */

    for(int i=0; i<n; i++)      //store frequency of each element
        freq[arr[i]]++;
    
    int s = freq.size();
    cout << s << endl;
    //convert the map into array of pairs of <element, freq>
    pair<int, int> pairArr[s];
    int i = 0;
    for(map<int,int>::iterator it=freq.begin(); it!=freq.end(); it++) 
        pairArr[i++] = (make_pair(it->first, it->second));

    sort(pairArr, pairArr+s, myCompare);

    vector<int> res;
    for(int i=0; i<s; i++) {
        int count = pairArr[i].second;
        while(count--) {
            //cout << count << endl;
            res.push_back(pairArr[i].first);
            //cout << pairArr[i].first << " ";
        }
    }

    for(int i=0; i<res.size(); i++) 
        cout << res[i] << " ";
    cout << endl;
}   

int main() {
    int n;
    cin >> n;
    //vector<int> arr;

    /*while(n--) {
        int num;
        cin >> num;
        arr.push_back(num);
    } */
    int *arr =  new int[n];
    for(int i=0; i<n; i++)
        cin >> arr[i];

    /* for(int i=0; i<arr.size(); i++) 
        cout << arr[i] << " ";
    cout << endl; */

    sortByFreq(arr, n);

    return (0);
}