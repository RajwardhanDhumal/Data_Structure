#include <iostream>
using namespace std;

class Graph {
public:
    int t_edge, t_nodes;
    int parent[10]; 
    typedef struct Edge {
        int u, v, weight;
    } ED;
    ED e[10];
    void create();
    void display();
    void kruskal();
    int min_edge();
    int find(int);
};

void Graph::create() {
    cout << "\nEnter number of Nodes: ";
    cin >> t_nodes;
    cout << "Enter number of Edges: ";
    cin >> t_edge;
    for (int i = 1; i <= t_edge; i++) {
        cout << "Enter edge (v1 and v2) and Cost: ";
        cin >> e[i].u >> e[i].v >> e[i].weight;
    }
}

void Graph::display() {
    cout << "\nThe graph contains following edges:";
    for (int i = 1; i <= t_edge; i++) {
        cout << "\n";
        cout << e[i].u << "\t";
        cout << e[i].v << "\t";
        cout << e[i].weight << "\t";
    }
}

void Graph::kruskal() 
{
    int a, b, j, k;
    for (int i = 1; i <= t_nodes; i++)
        parent[i] = i;

    int pos;
    pos = min_edge(); 
    a = e[pos].u;
    b = e[pos].v;
    j = find(a);
    k = find(b);

    cout << "\nThe parent of vertices are: " << j << "\t" << k;
    if (j != k) {
        cout << "\nAdding edge (" << a << ", " << b << ") to MST.";
        parent[j] = k;
    } else {
        cout << "\nEdge (" << a << ", " << b << ") forms a cycle, not adding to MST.";
    }
}

int Graph::min_edge() {
    int min = 999;
    int pos = -1;
    for (int i = 1; i <= t_edge; i++) {
        if (min > e[i].weight) {
            min = e[i].weight;
            pos = i; // Update the position of the minimum edge
        }
    }
    return pos; // Return the position of the minimum edge
}

int Graph::find(int p) {
    while (parent[p] != p)
        p = parent[p];
    return p;
}

int main() {
    int choice;
    Graph g;
    cout << "Welcome to Kruskal's Algorithm";
    do {
        cout << "\n1. Read a graph";
        cout << "\n2. Display a graph";
        cout << "\n3. Kruskal's method to find MST";
        cout << "\n4. Exit";
        cout << "\nEnter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                g.create();
                break;

            case 2:
                g.display();
                break;

            case 3:
                g.kruskal();
                break;
        }
    } while (choice != 4);

    return 0;
}
