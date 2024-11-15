#include <iostream>
#include <queue>
#include <stack>
using namespace std;


class Graph {
    int V; 
    int **adjMatrix; 

public:
    Graph(int V);
    void addEdge(int u, int v);
    void BFS(int start);
    void DFS(int start);
    void DFSUtil(int v, bool visited[]); 
    ~Graph(); 
};

Graph::Graph(int V) {
    this->V = V;
    adjMatrix = new int*[V];
    for (int i = 0; i < V; i++) {
        adjMatrix[i] = new int[V];
        for (int j = 0; j < V; j++) {
            adjMatrix[i][j] = 0;
        }
    }
}

void Graph::addEdge(int u, int v) {
    adjMatrix[u][v] = 1;
    adjMatrix[v][u] = 1; // Undirected graph
}

void Graph::BFS(int start) {
    bool *visited = new bool[V];
    for (int i = 0; i < V; i++)
        visited[i] = false;

    queue<int> q;
    visited[start] = true;
    q.push(start);

    while (!q.empty()) {
        int node = q.front();
        cout << node << " ";
        q.pop();

        for (int i = 0; i < V; i++) {
            if (adjMatrix[node][i] == 1 && !visited[i]) {
                visited[i] = true;
                q.push(i);
            }
        }
    }
    delete[] visited;
    cout << endl;
}

void Graph::DFS(int start) {
    bool *visited = new bool[V];
    for (int i = 0; i < V; i++)
        visited[i] = false;

    DFSUtil(start, visited);
    cout << endl;
    delete[] visited;
}

void Graph::DFSUtil(int v, bool visited[]) {
    visited[v] = true;
    cout << v << " ";

    for (int i = 0; i < V; i++) {
        if (adjMatrix[v][i] == 1 && !visited[i]) {
            DFSUtil(i, visited);
        }
    }
}

Graph::~Graph() {
    for (int i = 0; i < V; i++)
        delete[] adjMatrix[i];
    delete[] adjMatrix;
}


class HashTable {
    int *table;
    int size;

public:
    HashTable(int size);
    void insert(int key);
    void display();
    ~HashTable();
};

HashTable::HashTable(int size) {
    this->size = size;
    table = new int[size];
    for (int i = 0; i < size; i++) {
        table[i] = -1; 
    }
}

void HashTable::insert(int key) {
    int hashIndex = key % size;

    
    while (table[hashIndex] != -1) {
        hashIndex = (hashIndex + 1) % size;
    }

    table[hashIndex] = key;
}

void HashTable::display() {
    for (int i = 0; i < size; i++) {
        if (table[i] != -1)
            cout << i << " --> " << table[i] << endl;
        else
            cout << i << " --> " << "Empty" << endl;
    }
}

HashTable::~HashTable() {
    delete[] table;
}

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
                int size, n, key;
                cout << "Enter size of hash table: ";
                cin >> size;
                HashTable ht(size);

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

