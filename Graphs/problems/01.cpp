#include <iostream>
#include <vector>
#include <list>
#include <queue>
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

    bool isBipartite() {
        vector<int> color(V, -1); // -1 means uncolored
        
        for (int i = 0; i < V; i++) {
            if (color[i] == -1) { // If not visited
                queue<int> Q;
                Q.push(i);
                color[i] = 0; // Start coloring with 0

                while (!Q.empty()) {
                    int u = Q.front();
                    Q.pop();

                    for (int v : l[u]) {
                        if (color[v] == -1) {
                            color[v] = 1 - color[u]; // Alternate color (0 to 1, or 1 to 0)
                            Q.push(v);
                        } else if (color[v] == color[u]) {
                            return false; // Neighbor has the same color -> Not Bipartite!
                        }
                    }
                }
            }
        }
        return true;
    }
};

int main() {
    // Parsing sample input matrix representation into your adjacency list format
    Graph g(3);
    g.addEdge(0, 1);
    g.addEdge(1, 2);

    if (g.isBipartite()) cout << "The graph is bipartite" << endl;
    else cout << "The graph is not bipartite" << endl;
    return 0;
}