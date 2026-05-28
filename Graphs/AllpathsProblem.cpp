#include<iostream>
#include<vector>
#include<list>
#include<queue>
using namespace std;

class Graph{
    int v;
    list<int> *l;
public:
 Graph(int v){
        this->v = v;
        l = new list<int>[v];
    }  

    void addEdge(int u, int v){
        l[u].push_back(v);
        l[v].push_back(u);
    }

    void print(){
        for(int u=0; u<v; u++){
            list<int> neighbours = l[u];
            cout << u << " : ";
            for(int v : l[u]){
                cout << v << " ";
            }
            cout << endl;
        }
    }

    void bfs(){
        queue<int> q;
        vector<bool> vis(v, false);
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

    void pathHelper(int src, int dest, vector<bool> &vis, string &path){
        if(src == dest){
            cout << path << dest<< endl;
            return;
        }
        vis[src] =true;
        path += to_string(src);
        list<int> neighbors = l[src];

        for(int v : neighbors){
            if(!vis[v]){
                pathHelper(v, dest, vis, path);
            }
        }
        path = path.substr(0,path.size()-1);
        vis[src] = false;
    }


     

    void printAllPaths(int src, int dest){
        vector<bool>vis(v, false);
        string path="";
        pathHelper(src, dest,vis, path);

    }

}; 

int main(){
    Graph graph(6);

    graph.addEdge(0,3);
    graph.addEdge(2,3);
    graph.addEdge(3,1);
    graph.addEdge(4,0);
    graph.addEdge(4,1);
    graph.addEdge(5,0);
    graph.addEdge(5,2);

    cout << "All paths from vertex 5 to vertex 1:" << endl;
    graph.printAllPaths(5, 1);

    return 0;
}