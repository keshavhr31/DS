#include<iostream>
#include<list>
using namespace std;

class Graph
{
    int V;
    list<int> *adj;

    void DFSUtil(int v, bool visited[]);
public:
    Graph(int V);
    void addEdge(int v, int w);

    void DFS(int v);
};

Graph::Graph(int V)
{
    this->V = V;
    adj = new list<int>[V];
}

void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w);
}

void Graph::DFSUtil(int v, bool visited[])
{
    visited[v] = true;
    cout << v << " ";

    list<int>::iterator i;
    for (i = adj[v].begin(); i != adj[v].end(); ++i)
        if (!visited[*i])
            DFSUtil(*i, visited);
}

void Graph::DFS(int v)
{
    bool *visited = new bool[V];
    for (int i = 0; i < V; i++)
        visited[i] = false;

    DFSUtil(v, visited);
}

int main()
{
    Graph k(4);
    k.addEdge(0, 1);
    k.addEdge(0, 2);
    k.addEdge(1, 2);
    k.addEdge(2, 0);
    k.addEdge(2, 3);
    k.addEdge(3, 3);

    cout << "Following is Depth First Traversal"
    " (starting from vertex 2) \n";
    k.DFS(2);

    return 0;
}
