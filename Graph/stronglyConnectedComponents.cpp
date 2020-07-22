/* Korasaju's algorithm */

#include<iostream>
#include<list>
#include<stack>
using namespace std;

class Graph {
    int V;
    list<int> *adj;

    void fillOrder(int v, bool *visited, stack<int> &st);
    void DFSUtil(int v, bool *visited);

public:
    Graph(int  V);
    void addEdge(int v, int w);
    void printSCCs();
    Graph getTranspose();
};

Graph::Graph(int V) {
    this->V = V;
    adj = new list<int>[V];
}

void Graph::addEdge(int v, int w) {
    adj[v].push_back(w);
}

void Graph::DFSUtil(int v, bool *visited) {
    visited[v] = true;
    cout << v << " ";

    for(auto it=adj[v].begin(); it!=adj[v].end(); ++it) {
        if(!visited[*it])
            DFSUtil(*it, visited);
    }
}

Graph Graph::getTranspose() {
    Graph trans(V);

    for(int v=0; v<V; v++) {
        for(auto it=adj[v].begin(); it!=adj[v].end(); ++it)
            trans.adj[*it].push_back(v);
    }

    return trans;
}

void Graph::fillOrder(int v, bool *visited, stack<int> &st) {
    visited[v]  = true;

    for(auto it=adj[v].begin(); it!=adj[v].end(); ++it) {
        if(!visited[*it]) {
            fillOrder(*it, visited, st);
        }
    }

    st.push(v);
}

void Graph::printSCCs() {
    stack<int> st;

    bool *visited = new bool[V];
    for(int i=0; i<V; i++)
        visited[i] = false;

    for(int i=0; i<V; i++) {
        if(!visited[i])
            fillOrder(i, visited, st);
    }

    Graph transpose = getTranspose();

    for(int i=0; i<V; i++)
        visited[i] = false;     //for second time DFS

    int count = 0;
    while(!st.empty()) {
        int v = st.top();
        st.pop();

        if(!visited[v]) {
            transpose.DFSUtil(v, visited);       //print the strongly connected components
            count++;
            cout << endl;
        }
    }

    cout << "Total no. of strongly connected components: " << count << endl;
}

int main() {
    Graph g(5); 
    g.addEdge(1, 0); 
    g.addEdge(0, 2); 
    g.addEdge(2, 1); 
    g.addEdge(0, 3); 
    g.addEdge(3, 4); 

    g.printSCCs();

    return (0);
}