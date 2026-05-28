#include <iostream>
#include <list>
#include <vector>
#include <queue>
using namespace std;

class Graph {
public:
    int V;
    list<int> *l;

    Graph(int V) {
        this->V = V;
        l = new list<int>[V];
    }

    void addEdge(int U, int V) {
        l[U].push_back(V);
        l[V].push_back(U);
    }

    void print() {
        for (int U = 0; U < V; U++) {
            cout << U << " : ";
            for (int V : l[U]) {
                cout << V << " ";
            }
            cout << endl;
        }
    }

    bool isBipartite() {
        vector<int> color(V, -1);
        queue<int> q;

        // Handle disconnected graphs
        for (int start = 0; start < V; start++) {
            if (color[start] == -1) {
                q.push(start);
                color[start] = 0;

                while (!q.empty()) {
                    int curr = q.front();
                    q.pop();

                    for (int v : l[curr]) {
                        if (color[v] == -1) {
                            color[v] = !color[curr];
                            q.push(v);
                        } else if (color[v] == color[curr]) {
                            return false;
                        }
                    }
                }
            }
        }

        return true;
    }
};

int main() {
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 3);
    g.addEdge(1, 2);
    g.addEdge(2, 3);

    g.print();

    if (g.isBipartite()) {
        cout << "Graph is Bipartite" << endl;
    } else {
        cout << "Graph is NOT Bipartite" << endl;
    }

    return 0;
}
