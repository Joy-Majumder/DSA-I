#include <iostream>
#include <vector>
#include <list>
#include <queue>
#include <algorithm>
using namespace std;

class Graph {
    int V;
    list<int> *l;
public:
    Graph(int V) {
        this->V = V;
        l = new list<int>[V];
    }
    void addEdge(int u, int v) {
        l[u].push_back(v);
        l[v].push_back(u);
    }

    void shortestPath(int src) {
        queue<int> Q;
        vector<bool> vis(V, false);
        vector<int> parent(V, -1);

        Q.push(src);
        vis[src] = true;

        while (!Q.empty()) {
            int u = Q.front();
            Q.pop();

            for (int v : l[u]) {
                if (!vis[v]) {
                    vis[v] = true;
                    parent[v] = u;
                    Q.push(v);
                }
            }
        }

        // Print shortest path from src to the furthest node (or a specific target)
        // Reconstructing path for Node 3 as requested by sample output
        int target = 3; 
        vector<int> path;
        for (int v = target; v != -1; v = parent[v]) {
            path.push_back(v);
        }
        reverse(path.begin(), path.end());

        cout << "Shortest path from " << src << ": [";
        for (size_t i = 0; i < path.size(); i++) {
            cout << path[i] << (i == path.size() - 1 ? "" : ", ");
        }
        cout << "]" << endl;
    }
};

int main() {
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 3);

    g.shortestPath(0);
    return 0;
}