#include<iostream>
#include<vector>
#include<list>
#include<queue>
using namespace std;

class Graph{
    int V;
    list<int> *l;
    bool isUndir;
public:
    Graph(int V){
        this->V = V;
        l = new list<int>[V];
        this->isUndir = isUndir;
    }  

    void addEdge(int U, int V){
        l[U].push_back(V);
        l[V].push_back(U);
    }

    void print(){
        for(int U=0; U<V; U++){
            list<int> neighbours = l[U];
            cout << U << " : ";
            for(int V : neighbours){
                cout << V << " ";
            }
            cout << endl;
        }
    }

    void bfs(){
        queue<int> q;
        vector<bool> vis(V, false);
        q.push(0);
        vis[0] = true;

        while(!q.empty()){
            int u = q.front();
            q.pop();
            cout << u << " ";

            for(int v : l[u]){
                if(!vis[v]){
                    vis[v] = true;
                    q.push(v);
                }
            }
        }
        cout << endl;
    }

    void dfs(int u, vector<bool> &vis){
        vis[u] = true;
        cout << u <<" ";
        list<int> neighbours = l[u];

        for(int v : neighbours){
            if(!vis[v]){
                dfs(v, vis);
            }
        }
    }
    bool pathHelper(int src, int dest, vector<bool> &vis){
        if(src == dest){
            return true;
        }
        vis[src] = src;
        list<int> neighbours = l[src];

        for(int v : neighbours){
            if(!vis[v]){
                if(pathHelper(v, dest, vis)){
                    return true;
                }
            }
        }
        return false;
    }
    bool hashpath(int src, int dest){
        vector<bool> vis(V, false);
        return pathHelper(src, dest, vis);
    }

    bool UndirectedCycleHelper(int src, int par, vector<bool> & vis){
        vis[src] = true;
        list<int> neighbours = l[src];

        for(int V : neighbours){
            if(!vis[V]){
                if(UndirectedCycleHelper(V, src, vis)){
                    return true;
                }

            } else if( V!= par){
                return true;

            }
        }
        return false;
    }
    bool isCycleUndir(){
        vector<bool> vis(V,false);
        return UndirectedCycleHelper(0,-1,vis);
    }

};

int main(){
    Graph graph(7); // Changed to 7 vertices (0 to 6)
    graph.addEdge(0,1);
    graph.addEdge(0,2);
    graph.addEdge(1,3);
    graph.addEdge(2,4);
    graph.addEdge(3,4);
    graph.addEdge(3,5);
    graph.addEdge(4,5);
    graph.addEdge(5,6);

   // cout << "Graph adjacency list:" << endl;
    //graph.print();
    
    //cout << "\nBFS traversal starting from vertex 0:" << endl;
   // graph.bfs();
     
   //vector<bool>vis(7,false);
   // graph.dfs(0, vis);

    return 0;
}