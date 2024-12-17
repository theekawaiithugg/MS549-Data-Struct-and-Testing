#pragma once
#include <iostream>
#include <vector>
#include <queue>
#include <limits>
#include "functions.h"

using namespace std;

// Constructor for the Graph class, initializes the adjacency list
Graph::Graph(int v) : vertices(v), adjList(v) {}

// Adds an edge to the graph (both directions for an undirected graph)
void Graph::addEdge(int from, int to, int weight ) {
    
    adjList[from].push_back({ to, weight });
    adjList[to].push_back({ from, weight }); // For undirected graph
}

// Implements Dijkstra's shortest path algorithm for adjacency list
void Graph::dijkstra(int source) {
    vector<int> dist(vertices, numeric_limits<int>::max()); // Initialize distance vector with max values
    dist[source] = 0;
    
    // Priority queue for selecting the vertex with the smallest distance
    priority_queue<pair<int, int>,vector<std::pair<int, int>>, greater<>> pq;
    pq.push({ 0, source });

    while (!pq.empty()) {
        int currDist = pq.top().first;
        int u = pq.top().second;
        pq.pop();
        // Skip if the distance is outdated
        if (currDist > dist[u]) continue;
        // Relaxation step for adjacent vertices
        for (const auto& edge : adjList[u]) {
            int v = edge.to;
            int weight = edge.weight;

            if (dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                pq.push({ dist[v], v });
            }
        }
    }

    // Print distances
    // Print the shortest distances from the source to all vertices
    for (int i = 0; i < vertices; ++i) {
        cout << "Distance from " << source << " to " << i << ": " << dist[i] << endl;
    }
}

// Implements Prim's algorithm for Minimum Spanning Tree (MST) using adjacency list
void Graph::prim() {
    vector<int> parent(vertices, -1);
    vector<int> key(vertices, numeric_limits<int>::max());
    vector<bool> inMST(vertices, false);

    key[0] = 0; // Start from vertex 0
    for (int i = 0; i < vertices - 1; ++i) {
        // Find the vertex with the smallest key value not yet in MST
        int u = -1;
        for (int v = 0; v < vertices; ++v) {
            if (!inMST[v] && (u == -1 || key[v] < key[u])) {
                u = v;
            }
        }

        inMST[u] = true;

        // Update key and parent for adjacent vertices
        for (const auto& edge : adjList[u]) {
            int v = edge.to;
            int weight = edge.weight;
            if (!inMST[v] && weight < key[v]) {
                key[v] = weight;
                parent[v] = u;
            }
        }
    }

    // Print the edges of the MST
    for (int i = 1; i < vertices; ++i) {
        cout << "Edge: " << parent[i] << " - " << i << endl;
    }
}

// Utility function for Depth-First Search (DFS) in adjacency list
void Graph::dfsUtil(int v, vector<bool>& visited) {
    visited[v] = true;
    cout << v << " ";

    for (const auto& edge : adjList[v]) {
        if (!visited[edge.to]) {
            dfsUtil(edge.to, visited);
        }
    }
}

// Performs DFS traversal starting from a given vertex
void Graph::dfs(int start) {
    vector<bool> visited(vertices, false);
    dfsUtil(start, visited);
}

// Prints the adjacency list representation of the graph
void Graph::printGraph() {
    for (int i = 0; i <vertices; ++i) {
        cout << i << ": ";
        for (const auto& edge : adjList[i]) {
            cout << "(" << edge.to << ", " << edge.weight << ") ";
        }
        cout << endl;
    }
}

// Constructor for GraphMatrix, initializes adjacency matrix
 GraphMatrix ::GraphMatrix(int v) : vertices(v) {
    matrix.resize(vertices, vector<int>(vertices, numeric_limits<int>::max()));
    for (int i = 0; i < vertices; i++)
        matrix[i][i] = 0; // Distance to self is zero
}

 // Adds an edge to the adjacency matrix
void GraphMatrix:: addEdge(int from, int to, int weight) {
    matrix[from][to] = weight;
    matrix[to][from] = weight; // For undirected graphs
}

// Prints the adjacency matrix
void GraphMatrix::printGraph()
{
    cout << "Adjacency Matrix Representation:\n";
    for (int i = 0; i < vertices; ++i) {
        for (int j = 0; j < vertices; ++j) {
            if (matrix[i][j] == numeric_limits<int>::max())
                cout << "INF ";
            else
                cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

// Dijkstra's shortest path algorithm for adjacency matrix
void GraphMatrix::dijkstra(int source) 
{
    vector<int> dist(vertices, numeric_limits<int>::max());
    vector<bool> visited(vertices, false);
    dist[source] = 0;

    for (int count = 0; count < vertices - 1; ++count) {
        // Find the vertex with the minimum distance
        int u = -1, minDist = numeric_limits<int>::max();
        for (int i = 0; i < vertices; ++i) {
            if (!visited[i] && dist[i] < minDist) {
                minDist = dist[i];
                u = i;
            }
        }

        visited[u] = true;

        // Update distances for adjacent vertices
        for (int v = 0; v < vertices; ++v) {
            if (!visited[v] && matrix[u][v] != numeric_limits<int>::max() &&
                dist[u] + matrix[u][v] < dist[v]) {
                dist[v] = dist[u] + matrix[u][v];
            }
        }
    }

    // Print distances
    cout << "Dijkstra's Shortest Path (Matrix):\n";
    for (int i = 0; i < vertices; ++i) {
        cout << "Distance from " << source << " to " << i << ": " << dist[i] << endl;
    }
}

// Implements Prim's algorithm for adjacency matrix
void GraphMatrix::prim() {
    vector<int> parent(vertices, -1);
    vector<int> key(vertices, numeric_limits<int>::max());
    vector<bool> inMST(vertices, false);

    key[0] = 0; // Start from vertex 0

    for (int count = 0; count < vertices - 1; ++count) {
        int u = -1, minKey = numeric_limits<int>::max();

        for (int i = 0; i < vertices; ++i) {
            if (!inMST[i] && key[i] < minKey) {
                minKey = key[i];
                u = i;
            }
        }

        inMST[u] = true;

        for (int v = 0; v < vertices; ++v) {
            if (matrix[u][v] != numeric_limits<int>::max() && !inMST[v] && matrix[u][v] < key[v]) {
                key[v] = matrix[u][v];
                parent[v] = u;
            }
        }
    }

    // Print MST
    cout << "Prim's MST (Matrix):\n";
    for (int i = 1; i < vertices; ++i)
        cout << parent[i] << " - " << i << " (Weight: " << matrix[i][parent[i]] << ")\n";
}

// Utility function for Depth-First Search (DFS) in adjacency matrix
void GraphMatrix::dfsUtil(int v, vector<bool>& visited) {
    visited[v] = true;
    cout << v << " ";

    for (int i = 0; i < vertices; ++i) {
        if (matrix[v][i] != numeric_limits<int>::max() && !visited[i]) {
            dfsUtil(i, visited);
        }
    }
}

// Performs DFS traversal starting from a given vertex
void GraphMatrix::dfs(int start) {
    vector<bool> visited(vertices, false);
    cout << "DFS (Matrix): ";
    dfsUtil(start, visited);
    cout << endl;
}

// Adds an edge to the edge list
void GraphEdgeList::addEdge(int from, int to, int weight) {
    edgeList.push_back(make_tuple(from, to, weight));
}

// Prints the edge list representation
void GraphEdgeList::printGraph() {
    cout << "Edge List Representation:\n";
    for (auto& edge : edgeList) {
        cout << get<0>(edge) << " --(" << get<2>(edge) << ")--> " << get<1>(edge) << endl;
    }
}
// Dijkstra's shortest path algorithm for edge list
void GraphEdgeList::dijkstra(int source) {
    vector<int> dist(vertices, numeric_limits<int>::max());
    dist[source] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    pq.push({ 0, source }); // Distance, vertex

    while (!pq.empty()) {
        int currDist = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        if (currDist > dist[u]) continue;

        // Relax all edges
        for (auto& edge : edgeList) {
            int from = get<0>(edge), to = get<1>(edge), weight = get<2>(edge);
            if (from == u && dist[u] + weight < dist[to]) {
                dist[to] = dist[u] + weight;
                pq.push({ dist[to], to });
            }
        }
    }

    // Print distances
    cout << "Dijkstra's Shortest Path (Edge List):\n";
    for (int i = 0; i < vertices; ++i) {
        cout << "Distance from " << source << " to " << i << ": " << dist[i] << endl;
    }
}
// Implements Prim's algorithm for edge list
void GraphEdgeList::prim() {
    vector<int> key(vertices, numeric_limits<int>::max());
    vector<int> parent(vertices, -1);
    vector<bool> inMST(vertices, false);

    key[0] = 0;

    for (int count = 0; count < vertices - 1; ++count) {
        int u = -1, minKey = numeric_limits<int>::max();

        for (int i = 0; i < vertices; ++i) {
            if (!inMST[i] && key[i] < minKey) {
                minKey = key[i];
                u = i;
            }
        }

        inMST[u] = true;

        for (auto& edge : edgeList) {
            int from = get<0>(edge), to = get<1>(edge), weight = get<2>(edge);
            if (from == u && !inMST[to] && weight < key[to]) {
                key[to] = weight;
                parent[to] = u;
            }
        }
    }

    // Print MST
    cout << "Prim's MST (Edge List):\n";
    for (int i = 1; i < vertices; ++i)
        cout << parent[i] << " - " << i << " (Weight: " << key[i] << ")\n";
}
// Utility function for Depth-First Search (DFS) in edge list
void GraphEdgeList::dfsUtil(int v, vector<bool>& visited) {
    visited[v] = true;
    cout << v << " ";

    for (auto& edge : edgeList) {
        int from = get<0>(edge), to = get<1>(edge);
        if (from == v && !visited[to]) {
            dfsUtil(to, visited);
        }
    }
}

// Performs DFS traversal starting from a given vertex
void GraphEdgeList::dfs(int start) {
    vector<bool> visited(vertices, false);
    cout << "DFS (Edge List): ";
    dfsUtil(start, visited);
    cout << endl;
}