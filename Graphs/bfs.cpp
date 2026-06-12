#include<iostream>
#include<vector>
#include<list>
#include<queue>
using namespace std;

class Graph{ // building our graph so yea
    int V;
    list<int> *l; // int *arr

    
public:
    Graph(int V){
        this->V=V;
        l = new list<int>[V];
    }
    void addEdge(int u, int v){ // in this add edge fucntion we will add here U,V so yeap
        l[u].push_back(v);
        l[v].push_back(u);
    }
    // BFS
    void bfs(){
        queue<int>Q;
        vector<bool>vis(V, false);
        Q.push(0); // src node
        vis[0] = true;
        while (Q.size()>0)
        {
            int u = Q.front(); // src - u;
            Q.pop();
            cout<<u<<" ";

            for (int v : l[u]){
                if (!vis[v])
                {
                    vis[v] = true;
                    Q.push(v);
                }
                
            }
        }
        
    }
    //DFS
    void dfsHelper(int u, vector<bool>&vis){
        cout<<u<<" ";
        vis[u]=true;
        for (int v : l[u])
        {
            if (!vis[v])
            {
                dfsHelper(v, vis);
            }
            
        }
    }
    void dfs(){
        int src = 0;
        vector<bool> vis(V, false);
        dfsHelper(src, vis);
    }
};

int main(){
    Graph g(5); // here we are added the number of vertices here so 
    g.addEdge(0,1);
    g.addEdge(1,2);
    g.addEdge(1,3);
    // g.addEdge(2,3);
    g.addEdge(2,4);

    g.bfs();
    cout<<endl;
    g.dfs();
}