#include<iostream>
#include<map>
using namespace std;

void printCommon(int *arr1, int *arr2, int *arr3, int n1, int n2, int n3) {
    map<int, int> freq;

    for(int i=0; i<n1; i++) {
        if(freq[arr1[i]]==0)
            freq[arr1[1]]++;
    }

    for(int i=0; i<n2; i++) {
        if(freq[arr2[i]]!=0)
            freq[arr2[i]]++;
    }

    for(int i=0; i<n3; i++) {
        if(freq[arr3[i]]!=0)
            freq[arr3[i]]++;
    }
    
    //cout << freq.size() << endl;

    for(map<int,int>::iterator it=freq.begin(); it!=freq.end(); it++) {
        /* if(it->second == 3) 
            cout << it->first << " "; */
        cout << it->first << " " << it->second <<endl;
    }
    cout << endl;
}

int main() {
    int n1=6, n2=5, n3=8;
    int arr1[] = {1 ,5 ,10 ,20 ,40 ,80};
    int arr2[] = {6 ,7 ,20 ,80 ,100};
    int arr3[] = {3 ,4 ,15 ,20, 30, 70, 80, 120};

    printCommon(arr1, arr2, arr3, n1, n2, n3);

    return (0);
}