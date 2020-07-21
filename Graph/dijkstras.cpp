/**
 * VERY IMP name algo - Single source shortest path (Dijkstra's algo)
 * it is for directed weighted graph
 * O(n^2) because n vertices, each vertex will do relaxation of at most n vertices i.e if its connected to all vertices
 * it is a Greedy algorithm
 */

#include<iostream>
#include<climits>
using namespace std;

#define V 9

void printDistance(int *dist) {
    cout << "vertex \t\t distance\n";       //table heading
    for(int i=0; i<V; i++)
        cout << i << " \t\t " << dist[i] << endl;
}

//this method will find the vertex with min distane from current vertex, among those that are not yet visited
int minDistance(int dist[], bool visited[]) {
    int minIndex, min_dist=INT_MAX;

    for(int i=0; i<V; i++) {
        if(dist[i]<=min_dist && !visited[i]) {      //note that its <= in the condition 
            min_dist = dist[i];
            minIndex = i;
        }
    }

    return minIndex;
}

void dijkstra(int graph[V][V], int src) {
    int *dist = new int[V];
    bool *visited = new bool[V];

    for(int i=0; i<V; i++) {
        dist[i] = INT_MAX;
        visited[i] = false;
    }

    dist[src] = 0;

    for(int i=0; i<V-1; i++) {
        int u = minDistance(dist, visited);
        visited[u] = true;          //we have now moved to the local min dist node

        for(int  v=0; v<V; v++) {
            if(!visited[v] && graph[i][v]!=0 
            && dist[i]!=INT_MAX                     
            && dist[i] + graph[i][v] < dist[v])         //relaxation step
            {
                dist[v] = dist[i] + graph[i][v];
            }
        }
    }

    printDistance(dist);
    cout << endl;
}

int main() {

    //graph is represented in adjacency matrix form
    int graph[V][V] = { { 0, 4, 0, 0, 0, 0, 0, 8, 0 }, 
                        { 4, 0, 8, 0, 0, 0, 0, 11, 0 }, 
                        { 0, 8, 0, 7, 0, 4, 0, 0, 2 }, 
                        { 0, 0, 7, 0, 9, 14, 0, 0, 0 }, 
                        { 0, 0, 0, 9, 0, 10, 0, 0, 0 }, 
                        { 0, 0, 4, 14, 10, 0, 2, 0, 0 }, 
                        { 0, 0, 0, 0, 0, 2, 0, 1, 6 }, 
                        { 8, 11, 0, 0, 0, 0, 1, 0, 7 }, 
                        { 0, 0, 2, 0, 0, 0, 6, 7, 0 } };

    dijkstra(graph, 0);         //vertex 0 is the source

    return (0);
}