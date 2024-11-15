#include <iostream>
#include <queue>
#include <stack>
using namespace std;

struct Graph {
    int V;
    int **adjMatrix;

    Graph(int V) {
        this->V = V;
        adjMatrix = new int*[V];
        for (int i = 0; i < V; i++) {
            adjMatrix[i] = new int[V];
            for (int j = 0; j < V; j++) {
                adjMatrix[i][j] = 0;
            }
        }
    }

    void addEdge(int u, int v) {
        adjMatrix[u][v] = 1;
        adjMatrix[v][u] = 1; // Undirected graph
    }

    void BFS(int start) {
        bool visited[V] = {false};
        queue<int> q;
        visited[start] = true;
        q.push(start);

        while (!q.empty()) {
            int node = q.front();
            q.pop();
            cout << node << " ";

            for (int i = 0; i < V; i++) {
                if (adjMatrix[node][i] == 1 && !visited[i]) {
                    visited[i] = true;
                    q.push(i);
                }
            }
        }
        cout << endl;
    }

    void DFSUtil(int v, bool visited[]) {
        visited[v] = true;
        cout << v << " ";
        for (int i = 0; i < V; i++) {
            if (adjMatrix[v][i] == 1 && !visited[i]) {
                DFSUtil(i, visited);
            }
        }
    }

    void DFS(int start) {
        bool visited[V] = {false};
        DFSUtil(start, visited);
        cout << endl;
    }

    ~Graph() {
        for (int i = 0; i < V; i++)
            delete[] adjMatrix[i];
        delete[] adjMatrix;
    }
};

struct HashTable {
    int *table;
    int size;
    int probeStep; // Variable for probing step

    HashTable(int size, int probeStep) {
        this->size = size;
        this->probeStep = probeStep;
        table = new int[size];
        for (int i = 0; i < size; i++) {
            table[i] = -1;
        }
    }

    void insert(int key) {
        int hashIndex = key % size;
        int originalIndex = hashIndex;

        while (table[hashIndex] != -1) {
            hashIndex = (hashIndex + probeStep) % size;
            if (hashIndex == originalIndex) { // Table is full
                cout << "Hash table is full. Cannot insert key " << key << endl;
                return;
            }
        }

        table[hashIndex] = key;
    }

    void display() {
        for (int i = 0; i < size; i++) {
            if (table[i] != -1)
                cout << i << " --> " << table[i] << endl;
            else
                cout << i << " --> Empty" << endl;
        }
    }

    ~HashTable() {
        delete[] table;
    }
};

int main() {
    int choice;
    cout << "Menu:\n";
    cout << "1. BFS\n";
    cout << "2. DFS\n";
    cout << "3. Hashing using Linear Probing\n";
    cout << "4. Exit\n";

    while (true) {
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                int V, E, u, v, start;
                cout << "Enter number of vertices: ";
                cin >> V;
                Graph g(V);

                cout << "Enter number of edges: ";
                cin >> E;

                for (int i = 0; i < E; i++) {
                    cout << "Enter edge (u v): ";
                    cin >> u >> v;
                    g.addEdge(u, v);
                }

                cout << "Enter starting vertex for BFS: ";
                cin >> start;
                cout << "BFS Traversal: ";
                g.BFS(start);
                break;
            }

            case 2: {
                int V, E, u, v, start;
                cout << "Enter number of vertices: ";
                cin >> V;
                Graph g(V);

                cout << "Enter number of edges: ";
                cin >> E;

                for (int i = 0; i < E; i++) {
                    cout << "Enter edge (u v): ";
                    cin >> u >> v;
                    g.addEdge(u, v);
                }

                cout << "Enter starting vertex for DFS: ";
                cin >> start;
                cout << "DFS Traversal: ";
                g.DFS(start);
                break;
            }

            case 3: {
                int size, n, key, probeStep;
                cout << "Enter size of hash table: ";
                cin >> size;
                cout << "Enter probing step (e.g., 1 for standard linear probing, or another value like 2, 3, 4): ";
                cin >> probeStep;

                HashTable ht(size, probeStep);

                cout << "Enter number of keys to insert: ";
                cin >> n;

                for (int i = 0; i < n; i++) {
                    cout << "Enter key: ";
                    cin >> key;
                    ht.insert(key);
                }

                cout << "Hash Table: \n";
                ht.display();
                break;
            }

            case 4:
                exit(0);

            default:
                cout << "Invalid choice!\n";
        }
    }

    return 0;
}

