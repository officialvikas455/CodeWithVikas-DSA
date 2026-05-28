#include <iostream>
#include <vector>
#include <climits>  // For INT_MAX
using namespace std;

class Edge {
public:
    int v;
    int wt;

    Edge(int v, int wt) {
        this->v = v;
        this->wt = wt;
    }
};

void bellmanFord(vector<vector<Edge>> &graph, int v, int src) {
    vector<int> dist(v, INT_MAX);
    dist[src] = 0;

    for (int i = 0; i < v - 1; i++) {
        for (int u = 0; u < v; u++) {
            for (Edge e : graph[u]) {
                if (dist[u] != INT_MAX && dist[e.v] > dist[u] + e.wt) {
                    dist[e.v] = dist[u] + e.wt;
                }
            }
        }
    }

    for (int i = 0; i < v; i++) {
        cout << dist[i] << " ";
    }
    cout << endl;
}

int main() {
    int v = 5;
    vector<vector<Edge>> graph(v);  // Corrected declaration

    graph[0].push_back(Edge(1, 2));
    graph[0].push_back(Edge(2, 4));

    graph[1].push_back(Edge(2, -4));  // Changed from graph[0] to graph[1]
    graph[1].push_back(Edge(3, 2));   // Changed from graph[0] to graph[1]
    graph[1].push_back(Edge(4, 4));   // Changed from graph[0] to graph[1]
    graph[3].push_back(Edge(1, -1));  // Changed from graph[0] to graph[3]

    bellmanFord(graph, v, 0);

    return 0;
}
