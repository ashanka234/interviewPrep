#include<iostream>
#include<list>
using namespace std;

class Graph {
    int V;
    list<int> *adj;
    bool isCyclicUtil(int v, bool *visited, int parent);

public:
    Graph(int V);
    void addEdge(int v, int w);
    bool isCyclic();
};

Graph::Graph(int V) {
    this->V = V;
    adj = new list<int>[V];
}

void Graph::addEdge(int v, int w) {
    adj[v].push_back(w);
    adj[w].push_back(v);        //cuz graph is cyclic so add edge from both to both
}

bool Graph::isCyclicUtil(int v, bool *visited, int parent) {
    visited[v] = true;

    for(list<int>::iterator it=adj[v].begin(); it!=adj[v].end(); ++it) {
        if(!visited[*it]) {
            if(isCyclicUtil(*it, visited, v))
                return true;
        }

        else if(*it != parent)      //adjacent node is already visited but is not parent of current, means there is cycle
            return true;
    }

    return false;
}

bool Graph::isCyclic() {
    bool *visited = new bool[V];
    for(int i=0; i<V; i++)
        visited[i] = false;

    for(int u=0; u<V; u++) {
        if(!visited[u]) {
            if(isCyclicUtil(u, visited, -1))
                return true;
        }
    }
    return false;
}

int main() {
    Graph g1(5); 
    g1.addEdge(1, 0); 
    g1.addEdge(0, 2); 
    g1.addEdge(2, 1); 
    g1.addEdge(0, 3); 
    g1.addEdge(3, 4); 

    cout << g1.isCyclic() << endl;

    Graph g2(3); 
    g2.addEdge(0, 1); 
    g2.addEdge(1, 2); 

    cout << g2.isCyclic() << endl;

    return (0);
}