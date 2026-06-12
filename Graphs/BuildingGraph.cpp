#include<iostream>
#include<vector>
#include<list>
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
    void printGraph(){
        for(int i = 0; i<V;i++){
            cout<<"Vertex "<<i<<" is connected to : ";
            for(int neighbour : l[i]){
                cout<<neighbour<<", ";
            }
            cout<<endl;
        }
    }
};

int main(){
    Graph g(5); // here we are added the number of vertices here so 
    g.addEdge(0,1);
    g.addEdge(1,2);
    g.addEdge(1,3);
    g.addEdge(2,3);
    g.addEdge(2,4);

    g.printGraph();
}