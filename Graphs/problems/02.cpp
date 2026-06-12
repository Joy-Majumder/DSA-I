#include <iostream>
#include <vector>
#include <list>
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

    void dfsHelper(int u, vector<bool>& vis) {
        vis[u] = true;
        for (int v : l[u]) {
            if (!vis[v]) dfsHelper(v, vis);
        }
    }

    bool isConnected() {
        vector<bool> vis(V, false);
        dfsHelper(0, vis); // Start from node 0

        for (bool visited : vis) {
            if (!visited){
                 return false;
                } // If any node is unvisited, it's disconnected
        }
        return true;
    }
};

int main() {
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(2, 3);

    if (g.isConnected()) cout << "The graph is connected" << endl;
    else cout << "The graph is not connected" << endl;
    return 0;
}