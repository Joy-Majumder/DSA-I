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

    void dfsHelper(int u, vector<bool>& vis, vector<int>& component) {
        vis[u] = true;
        component.push_back(u);
        for (int v : l[u]) {
            if (!vis[v]) dfsHelper(v, vis);
        }
    }

    void findConnectedComponents() {
        vector<bool> vis(V, false);
        cout << "Connected components: ";
        bool first = true;

        for (int i = 0; i < V; i++) {
            if (!vis[i]) {
                vector<int> component;
                dfsHelper(i, vis, component);
                
                for (int node : component) {
                    if (!first) cout << ", ";
                    cout << node;
                    first = false;
                }
            }
        }
        cout << endl;
    }
};

int main() {
    Graph g(3);
    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.findConnectedComponents();
    return 0;
}