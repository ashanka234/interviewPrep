/* VVVV IMP QUESTION - asked in Amazon and many companies directly as it is */

#include<iostream>
#include<list>
#include<unordered_map>
using namespace std;

class LRUcache {
    list<int> dq;
    unordered_map<int, list<int>::iterator> ma;
    int csize;      //cache size

public:
    LRUcache(int n) {
        csize = n;
    }
    void refer(int);
    void display();
};

void LRUcache::refer(int x) {       //refers the key x with cache
    //if not present in cache
    if(ma.find(x) == ma.end()) {
        //if cache is full , then delete the least recently used element. and then it will insert at front
        if(dq.size() == csize) {
            int last = dq.back();
            dq.pop_back();
            ma.erase(last);
        }
    }

    //if present in cache, delete it. we will insert it at front
    else {  
        dq.erase(ma[x]);        //jis bhi jagah pe hai present waha se hata  do. ma[x] is mapped to a list iterator location
    }

    //push at front
    dq.push_front(x);
    ma[x] = dq.begin();     //location of new element is at front 
}

void LRUcache::display() {
    list<int>::iterator it;
    for(it=dq.begin(); it!=dq.end(); it++) {
        cout << *it << " ";
    }
    cout << endl;
}

int main() {

    LRUcache lruCache(4);
    lruCache.refer(1);
    lruCache.refer(2);
    lruCache.refer(3);
    lruCache.refer(1);
    lruCache.refer(4);
    lruCache.refer(5);

    lruCache.display();


    return (0);
}