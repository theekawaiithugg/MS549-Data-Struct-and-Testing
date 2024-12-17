#pragma once
#include <iostream>
#include <vector>
#include <queue>
#include <limits>
#include <tuple>

using namespace std;

// Structure to represent an edge in the graph
struct Edge {
    int to; // Destination vertex
    int weight; // Weight of the edge
};


// Class to represent a graph using an adjacency list
class Graph {
public:
    int vertices;
    vector<std::vector<Edge>> adjList;

    Graph(int v);

    void addEdge(int from, int to, int weight );
    void dijkstra(int source); //Shortest Path
    void prim();//Minimum Spanning Tree
    void dfsUtil(int v, vector<bool>& visited);
    void dfs(int start);//Depth First search
    void printGraph();
};

// Class to represent a graph using an adjacency matrix
class GraphMatrix {
private:
    int vertices;
    vector<vector<int>> matrix;

public:
    GraphMatrix(int v);

    void addEdge(int from, int to, int weight);

    void printGraph();

    void dijkstra(int source);
    void prim();
    void dfsUtil(int v, vector<bool>& visited);
    void dfs(int start);
};

// Class to represent a graph using an edge list       7757




class GraphEdgeList {
private:
    int vertices;
    vector<tuple<int, int, int>> edgeList; // (from, to, weight)

public:
    // Constructor accepting number of vertices
    GraphEdgeList(int v) : vertices(v) {}

    void addEdge(int from, int to, int weight);

    void printGraph();

    void dijkstra(int source);
    void prim();
    void dfsUtil(int v, vector<bool>& visited);
    void dfs(int start);
};