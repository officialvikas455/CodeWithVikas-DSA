#include<iostream>
#include<vector>
#include<stack>
#include<list>
#include<queue>
using namespace std;
 class Graph{
    int V;
    list<int> *l;
    bool isUndir;

public:
     Graph(int V, bool isUndir = true){
        this->V = V;
        this->isUndir = isUndir;
     } 
     
     void addEdge(int u, int v){
        l[u].push_back(v);
        l[v].push_back(u);
        if(isUndir)
           l[v].push_back(u);

     }

     void topoHelper(int src, vector<bool> &vis, stack<int> &s){
        vis[src] = true;

        list<int> neighbours = l[src];
        for(int v : neighbours){
            if(!vis[v]){
                topoHelper(v, vis, s);
            }
        }
        s.push(src);
     }

     void topoSort(){
        vector<bool> vis(V, false);
        stack<int> s;

        for(int i=0; i<V; i++){
            if(!vis[i]){
                topoHelper(i, vis, s);
            }
        }
        cout<< endl;
     }
     // Kahns algorithm

     void calcIndegree(vector<int> indeg){
        for(u=0; u<v; u++){
            list<int> neighbours = l[u];

            for(int v : neighbours){
                indeg[v]++;
            }
        }
     }
     void topoSort(){
        vector<int> indeg(V,0);
        calcIndegree(indeg);
        queue<int> q;
     }
    for(int )
 };

int main(){
    Graph graph(6, false);

    graph.addEdge(2,3);
    graph.addEdge(3,1);

    graph.addEdge(4,0);
    graph.addEdge(4,1);

    graph.addEdge(5,0);
    graph.addEdge(5,2);

     graph.topoSort();
 

    return 0;


}