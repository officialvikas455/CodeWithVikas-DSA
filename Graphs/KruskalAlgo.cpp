#include<iostream>
#include<vector>
#include<list>
#include<queue>
using namespace std;

class Edge{
    public:
      int u;
      int v;
      int wt;
   Edge(int u, int v ,int wt){
    this->u = u;
    this->v = v;
    this->wt = wt;
   }   

};
class Graph{
public:
    vector<Edge> edges;
    int V;
    vector<int> par;
    vector<int> rank;
 Graph(int V){
    this-> V = V;
 } 
 void find(int x){
    if(par[x]==x){
        return x;
    }
    return par[x] = find(par[x]);
 }
void addEdge(int U, int V, int wt){
    edges.push_back(Edge(U,V, wt));
   } 
   void UnionByRank(int u, int v){
    int parU = find(u);
    int parV = find(v);

    if(rank[parU] == rank[parV]){
        par[parV] = parU;
        rank[parU]++;
    }else if(rank[parU] > rank[parV]){
        par[parV] = parU;
    }else{
        par[parU] = parV;
    }
   } 
   void kruscal(){
    sort(edges.begin(), edges.end(),[](Edge &a, Edge &b){return a.wt < b.wt});
    int minCost=0;

    for(int i=0; i<edges.size() && count< V-1; i++){
        Edge e = edges[i];
        int parU = find(e.u);
        int parV = find(e.v);

        if(parU != parV){ // no cycle edge
          UnionByRank(parU,parV);
          minCost += e.wt;
        }

    }
    cout <<" min Cost=" << minCost << endl;
   }
         
};


int main(){
    return 0;
}