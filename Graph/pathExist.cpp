#include<iostream>
#include<list>
#include<queue>
using namespace std;

#define N 4

class Graph {
    int V;
    list<int> *adj;

public:
    Graph(int V) {
        this->V = V;
        adj = new list<int>[V];
    }

    void addEdge(int v, int w) {
        adj[v].push_back(w);
        adj[w].push_back(v);        //it is undirected graph
    }

    bool BFS(int s, int d);
};

bool Graph::BFS(int s, int d) {
    if(s==d)
        return true;

    bool *visited = new bool[V];
    for(int i=0; i<V; i++)
        visited[i] = false;

    queue<int> q;

    visited[s] = true;
    q.push(s);

    while(!q.empty()) {
        int curr = q.front();
        q.pop();

        for(list<int>::iterator it=adj[curr].begin(); it!=adj[curr].end(); ++it) {
            if(*it == d)
                return true;        //destination reached

            else if(!visited[*it]) {
                visited[*it] = true;
                q.push(*it);
            }
        }
    }

    return false;       //not able to reach destination
}

bool isSafe(int i, int j, int mat[][N]) {
    if(i>=0 && i<N && j>=0 && j<N)
        return true;

    return false;
}

bool findPath(int mat[][N]) {
    int s, d;
    int V = N*N + 2;        // IMPORTANT FORRMULA 
    Graph g(V);


    //we will now convert the matrix into a graph
    int k=1;
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            if(mat[i][j] != 0) {
                // 4 directions from current cell - up, left, right, down

                if(isSafe(i, j+1, mat))     //right
                    g.addEdge(k, k+1);
                if(isSafe(i, j-1, mat))     //left
                    g.addEdge(k, k-1);
                if(isSafe(i+1, j, mat) && j<N-1)        //down
                    g.addEdge(k, k+N);
                if(isSafe(i-1, j, mat) && i>0)     //up
                    g.addEdge(k, k-N);
            }

            if(mat[i][j] == 1)
                s = k;

            if(mat[i][j] == 2)
                d = k;

            k++;
        }
    }

    return g.BFS(s, d);
}

int main() {
    int mat[N][N] = { { 0, 3, 0, 1 }, 
                    { 3, 0, 3, 3 }, 
                    { 2, 3, 3, 3 }, 
                    { 0, 3, 3, 3 } };

    cout << findPath(mat) << endl;

    return (0);
}