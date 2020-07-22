#include<iostream>
#include<list>
#include<cstring>
using namespace std;

/* we will use Eulerian path, on a graph consisting of 26 vertices (each alphabet)
    Eulerian path is a path which traverse each vertex only once, starting and ending at the same vertex 
    it is possible only in directed graph, with in degree and out degree same for every vertex, and all
    non-zero degree vertices form 1 strongly connected component 
*/

class Graph {
    int V;
    list<int> *adj;
    int *in;        //in degree

public:
    Graph(int V) {
        this->V = V;
        adj = new list<int>[V];
        in = new int[V];
        for(int i=0; i<V; i++)      //initially set in degree as 0 for all vertices
            in[i] = 0;
    }

    void addEdge(int v, int w) {
        adj[v].push_back(w);
        in[w]++;        
    }

    bool isEulerianCycle();
    bool isSC();        //strongly connected 
    void DFSUtil(int v, bool *visited);
    Graph getTranspose();
};

bool Graph::isEulerianCycle() {
    if(!isSC())
        return false;

    for(int i=0; i<V; i++) {
        if(adj[i].size() != in[i])      //adj[i].size() is same as out degree
            return false;
    }

    return true;
}

void Graph::DFSUtil(int v, bool *visited) {
    visited[v] = true;

    for(auto it=adj[v].begin(); it!=adj[v].end(); ++it) {
        if(!visited[*it]) {
            DFSUtil(*it, visited);
        }
    }
}

Graph Graph::getTranspose() {
    Graph g(V);

    for(int i=0; i<V; i++) {
        for(auto it=adj[i].begin(); it!=adj[i].end(); ++it) {
            g.adj[*it].push_back(i);
            g.in[i]++;
        }
    }

    return g;       //transposed graph
}

bool Graph::isSC() {
    bool *visited = new bool[V];
    for(int i=0; i<V; i++)
        visited[i] = false;

    int n;
    for(n=0; n<V; n++) {        //find first vertex with non zero out degree
        if(adj[n].size() > 0)
            break;
    }

    DFSUtil(n, visited);

    for(int i=0; i<V; i++) {
        if(adj[i].size()>0 && !visited[i])  //DFS must have visited all the vertices for strongly connected
            return false;
    }

    Graph gr = getTranspose();

    //for next DFS traversal
    for(int i=0; i<V; i++)
        visited[i] = false;

    gr.DFSUtil(n, visited);

    //again all vertices should be visited in DFS of transposed graph
    for(int i=0; i<V; i++) {
        if(adj[i].size()>0 && !visited[i])
            return false;
    }

    return true;
}

bool canChained(string *arr, int n) {
    Graph g(26);        //graph with 26 vertices

    for(int i=0; i<n; i++) {
        string str = arr[i];
        g.addEdge(str[0]-'a', str[str.length()-1]-'a');     //edge created from first to last character of the current string
    }

    //if Eulerian Cycle exist, then can be chained
    return g.isEulerianCycle();
}

int main() {
    string arr1[] =  {"for", "geek", "rig", "kaf"}; 
    int n1 = sizeof(arr1)/sizeof(arr1[0]);

    cout << canChained(arr1, n1) << endl;

    string arr2[] =  {"aab", "abb"}; 
    int n2 = sizeof(arr2)/sizeof(arr2[0]); 

    cout << canChained(arr2, n2) << endl;

    return (0);
}