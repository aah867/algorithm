
// Online C++ Compiler - Build, Compile and Run your C++ programs online in your favorite browser

#include <iostream>
#include <vector>

using namespace std;

class Graph
{
    int v;
    vector<vector<int>> adj;
    bool isCycleUtil(int src, vector<bool>& visited, int parent)
    {
        visited[src] = true;
        for (auto i: adj[src])
        {
            if (i != parent)
            {
                if (visited[i])
                {
                    return true;
                }
                if (!visited[i] && isCycleUtil(i, visited, src))
                {
                    return true;
                }
            }
        }
        return false;
    }
        
    public:
        Graph(int v) {
            this->v = v;
            adj.resize(v);
        }
        void addEdge(int u, int v)
        {
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        bool isCycle()
        {
            vector<bool> visited(v, false);
            for(int i=0; i<v; i++)
            {
                std::cout << "-" << std::endl;
                if (!visited[i] && isCycleUtil(i, visited, -1))
                {
                    return true;
                }
            }
            return false;
        }
};

int main()
{
    Graph g(5);
    g.addEdge(0,1);
    g.addEdge(1,2);
    g.addEdge(2,3);
    g.addEdge(3,4);
    g.addEdge(4,1);

    if (g.isCycle())
    {
        std::cout << "It's a cycle!" << std::endl;
    }
    else
    {
        std::cout << "NO cycle!" << std::endl;
    }
}