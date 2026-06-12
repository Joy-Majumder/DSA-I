#include <iostream>
#include <vector>
#include <list>
#include <stack>
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

    void topoDFS(int u, vector<bool>& vis, stack<int>& st) {
        vis[u] = true;
        for (int v : l[u]) {
            if (!vis[v]) topoDFS(v, vis, st);
        }
        st.push(u); // Push to stack when processing finishes
    }

    void topologicalSort() {
        vector<bool> vis(V, false);
        stack<int> st;

        for (int i = 0; i < V; i++) {
            if (!vis[i]) topoDFS(i, vis, st);
        }

        cout << "Topological sort: ";
        while (!st.empty()) {
            cout << st.top() << (st.size() == 1 ? "" : ", ");
            st.pop();
        }
        cout << endl;
    }
};

int main() {
    DirectedGraph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 3);

    g.topologicalSort();
    return 0;
}