/**
 * Only for Directed Acyclic Graph (DAG)
 * for each edge u->v, u must come before v after sorting 
 **/

#include<iostream>
#include<list>
#include<stack>
using namespace std;

class Graph {
    int V;
    list<int> *adj;
    void topologicalSortUtil(int v, bool *visited, stack<int> &st);

public:
    Graph(int V);
    void addEdge(int v, int w);
    void topologicalSort();
};

Graph::Graph(int V) {
    this->V = V;
    adj = new list<int>[V];
}

void Graph::addEdge(int v, int w) {
    adj[v].push_back(w);
}

void Graph::topologicalSortUtil(int v, bool visited[], stack<int> &st) {
    visited[v] = true;

    for(auto it=adj[v].begin(); it!=adj[v].end(); ++it) {
        if(!visited[*it]) {
            topologicalSortUtil(*it, visited, st);
        }
    }

    st.push(v);
}

void Graph::topologicalSort() {
    bool *visited = new bool[V];
    for(int i=0; i<V; i++)
        visited[i] = false;
    stack<int> st;

    for(int u=0; u<V; u++) {
        if(!visited[u])
            topologicalSortUtil(u, visited, st);
    }

    //answer is stored in stack
    while(!st.empty()) {
        cout << st.top() << " ";
        st.pop();
    }
    cout << endl;
}

int main() {

    Graph g(6); 
    g.addEdge(5, 2); 
    g.addEdge(5, 0); 
    g.addEdge(4, 0); 
    g.addEdge(4, 1); 
    g.addEdge(2, 3); 
    g.addEdge(3, 1); 

    g.topologicalSort();

    return (0);
}