/**
 * IMPORTANT NAME ALGO
 * floyd warshall - used to find all pairs shortest path
 * it is DP based algo for weighted directed graph
 * */

#include<iostream>
#include<climits>
using namespace std;

#define V 4
#define INF 99999

void printSolution(int dist[][V]) {
    for(int i=0; i<V; i++) {
        for(int j=0; j<V; j++) {
            if(dist[i][j] == INF) 
                cout << "INF   ";
            else
                cout << dist[i][j] << "     ";
        }
        cout << endl;
    }
}

void floydWarshall(int graph[][V]) {
    int dist[V][V];

    for(int i=0; i<V; i++) {
        for(int j=0; j<V; j++) {
            dist[i][j] = graph[i][j];
        }
    }


    for(int k=0; k<V; k++) {        //intermediate vertex
        for(int i=0; i<V; i++) {        //source
            for(int j=0; j<V; j++) {        //destination
                if(dist[i][k] + dist[k][j] < dist[i][j])        //its like associative property of addition
                    dist[i][j] = dist[i][k] + dist[k][j];
            }   
        }
    }

    printSolution(dist);
}

int main() {

    //graph is given in adjacecy matrix form
    int graph[V][V] = { {0, 5, INF, 10},  
                        {INF, 0, 3, INF},  
                        {INF, INF, 0, 1},  
                        {INF, INF, INF, 0} };

    floydWarshall(graph);

    return (0);
}