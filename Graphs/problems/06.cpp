#include <iostream>
#include <vector>
#include <list>
using namespace std;

class DirectedGraph {
    int V;
    list<int> *l;
public:
    DirectedGraph(int V) {
        this->V = V;
        l = new list<int>[V];
    }
    void addEdge(int u, int v) {
        l[u].push_back(v); 
    }

    bool dfsCycleCheck(int u, vector<bool>& vis, vector<bool>& stackVis) {
        vis[u] = true;
        stackVis[u] = true;

        for (int v : l[u]) {
            if (!vis[v]) {
                if (dfsCycleCheck(v, vis, stackVis)) return true;
            } else if (stackVis[v]) {
                return true;
            }
        }

        stackVis[u] = false; 
        return false;
    }

    bool hasCycle() {
        vector<bool> vis(V, false);
        vector<bool> stackVis(V, false);
        for (int i = 0; i < V; i++) {
            if (!vis[i]) {
                if (dfsCycleCheck(i, vis, stackVis)) return true;
            }
        }
        return false;
    }
};

int main() {
    DirectedGraph g(3);
    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(2, 0);

    if (g.hasCycle()) cout << "The graph contains a cycle" << endl;
    else cout << "No cycle detected" << endl;
    return 0;
}
