#include <iostream>
#include <queue>
#include <stack>
#include <list>
#include <vector>
#include <map>

using namespace std;

/**
 * @brief https://takeuforward.org/data-structure/detect-a-cycle-in-directed-graph-using-dfs/
 * https://favtutor.com/blogs/detect-cycle-in-directed-graph
 * https://favtutor.com/blogs/detect-cycle-in-directed-graph
 */
class Graph
{
    private:
        int V;
        map<int, vector<int>> adj;

    public:
        Graph(int V);
        void addEdge(int v, int w);
        bool isCyclic();
        void bfs(int startNode);
        void dfs(int startNode);
};

Graph::Graph(int V): V(V) {
}

void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w);
}

void Graph::bfs(int startNode)
{
    queue<int> q;
    vector<bool> visited(V, false);

    visited[startNode] = true;
    q.push(startNode);

    while (!q.empty())
    {
        int currentNode = q.front();
        q.pop();
        std::cout << currentNode << std::endl;

        for( auto i : adj[currentNode])
        {
            if (!visited[i])
            {
                visited[i] = true;
                q.push(i);
            }
        }
    }
}

void Graph::dfs(int startNode)
{
    stack<int> s;
    vector<bool> visited(V, false);

    s.push(startNode);

    while (!s.empty())
    {
        int currentNode = s.top();
        s.pop();

        if(!visited[startNode])
        {
            std::cout << currentNode << std::endl;
            visited[startNode] = true;
        }

        for( auto i : adj[currentNode])
        {
            if (!visited[i])
            {
                s.push(i);
            }
        }
    }
}

bool Graph::isCyclic()
{

    vector<int> inDegree(V,0);
    queue<int> q;
    int visited = 0;

    // Calculate in-degree of each vertex
    for (int u=0; u < V; u++)
    {
        for (auto v: adj[u])
        {
            inDegree[v]++;
        }
    }

    // enqueue vertices with 0 in-degree
    for (int u=0; u<V; u++)
    {
        if (inDegree[u] == 0)
        {
            q.push(u);
        }
    }

    // BFS traversal
    while( !q.empty())
    {
        int u = q.front();
        q.pop();
        visited++;
        for(auto v: adj[u])
        {
            inDegree[v]--;
            if (inDegree[v] == 0)
            {
                q.push(v);
            }
        }
    }
    return visited != V;
}

int main()
{
    Graph g(6);
    g.addEdge(0,1);
    g.addEdge(0,2);
    g.addEdge(1,3);
    g.addEdge(4,1);
    g.addEdge(4,5);
    g.addEdge(5,3);

    std::cout << "BFS traversal:" << std::endl;
    g.bfs(0);

    std::cout << "DFS traversal:" << std::endl;
    g.dfs(0);

    if (g.isCyclic()) {
        cout << "Graph contains cycle." << endl;
    }
    else {
        cout << "Graph does not contain cycle." << endl;
    }

    return 0;
}
