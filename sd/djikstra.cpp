#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;

#define MAX_NODES 100  // Maximum number of nodes
#define INF INT_MAX    // Infinity (used for unreachable nodes)

int graph[MAX_NODES][MAX_NODES];
int numNodes = 0;

// Function to initialize the graph with no edges (infinity weights)
void initializeGraph(int n) {
    numNodes = n;
    for (int i = 0; i < numNodes; ++i)
        for (int j = 0; j < numNodes; ++j)
            graph[i][j] = (i == j) ? 0 : INF;  // No edge (infinity), 0 for self-loop
}

// Function to add an edge between two nodes with a given weight
void addEdge(int src, int dest, int weight) {
    if (src < numNodes && dest < numNodes) {
        graph[src][dest] = weight;
    } else {
        cout << "Error: Node out of range\n";
    }
}

// Utility function to find the vertex with minimum distance value
int minDistance(int dist[], bool visited[]) {
    int min = INF, min_index;

    for (int v = 0; v < numNodes; v++)
        if (!visited[v] && dist[v] <= min) {
            min = dist[v];
            min_index = v;
        }

    return min_index;
}

// Dijkstra's algorithm to find shortest path from a given source node
void dijkstra(int src) {
    int dist[MAX_NODES];
    bool visited[MAX_NODES] = {false};

    // Initialize all distances as infinity
    for (int i = 0; i < numNodes; i++)
        dist[i] = INF;

    // Distance from source to itself is always 0
    dist[src] = 0;

    for (int count = 0; count < numNodes - 1; count++) {
        // Pick the minimum distance vertex from the set of vertices not yet processed
        int u = minDistance(dist, visited);

        // Mark the chosen vertex as processed
        visited[u] = true;

        // Update dist value of the adjacent vertices of the picked vertex
        for (int v = 0; v < numNodes; v++) {
            if (!visited[v] && graph[u][v] != INF && dist[u] != INF &&
                dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    // Print the shortest distances from the source
    cout << "Shortest distances from node " << src << ":\n";
    for (int i = 0; i < numNodes; i++) {
        if (dist[i] == INF) {
            cout << "Node " << i << " is unreachable\n";
        } else {
            cout << "To node " << i << " -> " << dist[i] << "\n";
        }
    }
}

// Main menu-driven program
int main() {
    int choice, n, src, dest, weight, startNode;

    cout << "Enter the number of nodes in the graph: ";
    cin >> n;
    initializeGraph(n);

    do {
        cout << "\nMenu:\n";
        cout << "1. Add an edge\n";
        cout << "2. Find shortest path from a starting node\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter source node, destination node, and weight of the edge: ";
                cin >> src >> dest >> weight;
                addEdge(src, dest, weight);
                cout << "Edge added from node " << src << " to node " << dest << " with weight " << weight << "\n";
                break;
            case 2:
                cout << "Enter the starting node: ";
                cin >> startNode;
                if (startNode >= 0 && startNode < n) {
                    dijkstra(startNode);
                } else {
                    cout << "Invalid starting node!\n";
                }
                break;
            case 3:
                cout << "Exiting program...\n";
                break;
            default:
                cout << "Invalid choice! Please try again.\n";
                break;
        }
    } while (choice != 3);

    return 0;
}

