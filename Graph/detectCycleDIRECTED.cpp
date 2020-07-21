#include<iostream>
#include<list>
using namespace std;

class Graph {
    int V;
    list<int> *adj;
    bool isCyclicUtil(int v, bool *visited, bool *rs);

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
}

bool Graph::isCyclicUtil(int v, bool *visited, bool *recStack) {
    if(!visited[v]) {
        visited[v]  = true;
        recStack[v] = true;     //put in recStack

        for(list<int>::iterator it=adj[v].begin(); it!=adj[v].end(); ++it) {
            if(!visited[*it] && isCyclicUtil(*it, visited, recStack))
                return true;
            else if(recStack[*it] == true)      //current node is inside the recStack
                return true;
        }
    }

    recStack[v] = false;        //remove from recStack
    return false;
}

bool Graph::isCyclic() {
    bool *visited = new bool[V];
    bool *recStack = new bool[V];

    for(int i=0; i<V; i++) {
        visited[i] = false;
        recStack[i] = false;
    }

    for(int u=0; u<V; u++) {
        if(isCyclicUtil(u, visited, recStack))
            return true;
    }

    return false;
}

int main() {
    Graph g(4); 
    g.addEdge(0, 1); 
    g.addEdge(0, 2); 
    g.addEdge(1, 2); 
    g.addEdge(2, 0); 
    g.addEdge(2, 3); 
    g.addEdge(3, 3);

    cout << g.isCyclic() << endl;

    return (0);
}