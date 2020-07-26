/**
 * spanning tree - a subgraph in which all vertices must be connected
 * One graph can have many spanning trees
 * they must be connected with minimum no. of edges to make MST (minimum weighted)
 * both Prims and Kruskal's are Greedy  based algo
 * both are important named algos so memorise
 * */

#include<iostream>
#include<climits>
using namespace std;

#define V 5

int minKey(int *key, bool *mstSet) {
    int min_index, min = INT_MAX;

    for(int v=0; v<V; v++) {
        if(key[v] < min && !mstSet[v]) {
            min = key[v];
            min_index = v;
        }
    }

    return min_index;
}

void printMST(int *parent, int graph[V][V]) {
    cout << "Edge \tWeight" << endl;

    for(int i=1; i<V; i++) {
        cout  << parent[i] << " - " << i << " \t" << graph[i][parent[i]] << endl;
    }
}


// Time complexity is O(V^2)
void primMST(int graph[V][V]) {
    int parent[V];
    int key[V];
    bool mstSet[V];

    for(int i=0; i<V; i++) {
        key[i] = INT_MAX;       //to represent INF
        mstSet[i] = false;
    }

    key[0] = 0;
    parent[0] = -1;

    for(int count=0; count < V-1; count++) {
        int u = minKey(key, mstSet);        //pick the minimum weight edge which is not yet visited

        mstSet[u] = true;

        for(int v=0; v<V; v++) {
            if(graph[u][v]!=0 && !mstSet[v] && graph[u][v] < key[v]) {
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }

    printMST(parent, graph);
}

int main() {
    
    int graph[V][V] = { { 0, 2, 0, 6, 0 },  
                        { 2, 0, 3, 8, 5 },  
                        { 0, 3, 0, 0, 7 },  
                        { 6, 8, 0, 0, 9 },  
                        { 0, 5, 7, 9, 0 } };  
  
    primMST(graph);

    return (0);
}