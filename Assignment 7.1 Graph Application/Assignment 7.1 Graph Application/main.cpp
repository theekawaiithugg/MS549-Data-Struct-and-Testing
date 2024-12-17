#include "functions.h"
#include <chrono>


using namespace std;
int main() {
    int vertices = 20; // 20 vertices
    Graph g(vertices); // 20 vertices Adjacency List
    GraphMatrix gm(vertices);        // Adjacency Matrix
    GraphEdgeList ge(vertices);      // Edge List

    // Add edges to the Adjacency List graph
    //There are 20 edges explicitly defined, where each addEdge call connects two nodes.
    // Add edges (roads) between the locations
    // Each edge represents a road connecting two locations with a weight (distance)
    g.addEdge(0, 1, 5); //Point Vicente State Marine Conservation Area
    g.addEdge(1, 2, 4); // Los Verdes Golf Course
    g.addEdge(2, 3, 6); //Terranea Resort
    g.addEdge(3, 4, 3); //Rancho Palos Verdes (Central)
    g.addEdge(4, 5, 2); //Trump National Golf Club
    g.addEdge(5, 6, 7); // Abalone Cove State Marine Area
    g.addEdge(6, 7, 4); //Portuguese Bend Reserve
    g.addEdge(7, 8, 5); // Forrestal Nature Reserve
    g.addEdge(8, 9, 8); //Ocean Trails Reserve
    g.addEdge(9, 10, 6); //White Point Beach
    g.addEdge(10, 11, 3); // Cabrillo Marine Aquarium
    g.addEdge(11, 12, 4); //Korean Friendship Bell
    g.addEdge(12, 13, 5); //Ken Malloy Harbor Regional Park
    g.addEdge(13, 14, 2); //Roll Stop Sushi
    g.addEdge(14, 15, 6); //Northwest San Pedro (Intersection)
    g.addEdge(15, 16, 3); //Central San Pedro
    g.addEdge(16, 17, 7); //Fantastic Sams Hair Salon
    g.addEdge(17, 18, 5); //Lomita (Intersection)
    g.addEdge(18, 19, 4);// Rolling Hills Estates
    g.addEdge(19, 18, 4); //Malaga Cove
    // Add redundant edges to test connectivity and alternative paths
    g.addEdge(0, 5, 6);  // Add a new road between Point Vicente and Abalone Cove
    g.addEdge(4, 8, 7);  // Add a road between Trump National and Ocean Trails Reserve
    g.addEdge(2, 6, 5);  // Connect Terranea Resort and Portuguese Bend Reserve
    // Add cross connections for complex paths
    g.addEdge(9, 13, 4);  // White Point Beach ? Roll Stop Sushi
    g.addEdge(1, 17, 8);  // Los Verdes Golf Course ? Lomita
    g.addEdge(10, 15, 6); // Cabrillo Marine Aquarium ? Central San Pedro
    //Local Shortcuts
    g.addEdge(11, 19, 3); // Korean Friendship Bell ? Malaga Cove
    g.addEdge(3, 7, 5);   // Rancho Palos Verdes ? Forrestal Nature Reserve
    g.addEdge(6, 10, 6);
    g.addEdge(8, 14, 7);
    g.addEdge(12, 18, 4);
    g.addEdge(0, 9, 8);
    g.addEdge(7, 15, 6);
    g.addEdge(5, 11, 5);
    g.addEdge(13, 17, 3);
    g.addEdge(4, 19, 9);
    g.addEdge(2, 12, 7);
    g.addEdge(8, 16, 4);
    g.addEdge(1, 14, 5);
    g.addEdge(3, 10, 6);
    //gm
    // Repeat the above edges for Adjacency Matrix representation
    // Ensures consistency across different graph representations
    gm.addEdge(0, 1, 5); //Point Vicente State Marine Conservation Area
    gm.addEdge(1, 2, 4); // Los Verdes Golf Course
    gm.addEdge(2, 3, 6); //Terranea Resort
    gm.addEdge(3, 4, 3); //Rancho Palos Verdes (Central)
    gm.addEdge(4, 5, 2); //Trump National Golf Club
    gm.addEdge(5, 6, 7); // Abalone Cove State Marine Area
    gm.addEdge(6, 7, 4); //Portuguese Bend Reserve
    gm.addEdge(7, 8, 5); // Forrestal Nature Reserve
    gm.addEdge(8, 9, 8); //Ocean Trails Reserve
    gm.addEdge(9, 10, 6); //White Point Beach
    gm.addEdge(10, 11, 3); // Cabrillo Marine Aquarium
    gm.addEdge(11, 12, 4); //Korean Friendship Bell
    gm.addEdge(12, 13, 5); //Ken Malloy Harbor Regional Park
    gm.addEdge(13, 14, 2); //Roll Stop Sushi
    gm.addEdge(14, 15, 6); //Northwest San Pedro (Intersection)
    gm.addEdge(15, 16, 3); //Central San Pedro
    gm.addEdge(16, 17, 7); //Fantastic Sams Hair Salon
    gm.addEdge(17, 18, 5); //Lomita (Intersection)
    gm.addEdge(18, 19, 4);// Rolling Hills Estates
    gm.addEdge(19, 18, 4); //Malaga Cove
    //Redundancy
    gm.addEdge(0, 5, 6);  // Add a new road between Point Vicente and Abalone Cove
    gm.addEdge(4, 8, 7);  // Add a road between Trump National and Ocean Trails Reserve
    gm.addEdge(2, 6, 5);  // Connect Terranea Resort and Portuguese Bend Reserve
    //Cross Connections:
    gm.addEdge(9, 13, 4);  // White Point Beach ? Roll Stop Sushi
    gm.addEdge(1, 17, 8);  // Los Verdes Golf Course ? Lomita
    gm.addEdge(10, 15, 6); // Cabrillo Marine Aquarium ? Central San Pedro
    // Add local shortcuts
    gm.addEdge(11, 19, 3); // Korean Friendship Bell ? Malaga Cove
    gm.addEdge(3, 7, 5);   // Rancho Palos Verdes ? Forrestal Nature Reserve
    gm.addEdge(6, 10, 6);
    gm.addEdge(8, 14, 7);
    gm.addEdge(12, 18, 4);
    gm.addEdge(0, 9, 8);
    gm.addEdge(7, 15, 6);
    gm.addEdge(5, 11, 5);
    gm.addEdge(13, 17, 3);
    gm.addEdge(4, 19, 9);
    gm.addEdge(2, 12, 7);
    gm.addEdge(8, 16, 4);
    gm.addEdge(1, 14, 5);
    gm.addEdge(3, 10, 6);
    //ge
    // Repeat the edges for Edge List representation
    ge.addEdge(0, 1, 5); //Point Vicente State Marine Conservation Area
    ge.addEdge(1, 2, 4); // Los Verdes Golf Course
    ge.addEdge(2, 3, 6); //Terranea Resort
    ge.addEdge(3, 4, 3); //Rancho Palos Verdes (Central)
    ge.addEdge(4, 5, 2); //Trump National Golf Club
    ge.addEdge(5, 6, 7); // Abalone Cove State Marine Area
    ge.addEdge(6, 7, 4); //Portuguese Bend Reserve
    ge.addEdge(7, 8, 5); // Forrestal Nature Reserve
    ge.addEdge(8, 9, 8); //Ocean Trails Reserve
    ge.addEdge(9, 10, 6); //White Point Beach
    ge.addEdge(10, 11, 3); // Cabrillo Marine Aquarium
    ge.addEdge(11, 12, 4); //Korean Friendship Bell
    ge.addEdge(12, 13, 5); //Ken Malloy Harbor Regional Park
    ge.addEdge(13, 14, 2); //Roll Stop Sushi
    ge.addEdge(14, 15, 6); //Northwest San Pedro (Intersection)
    ge.addEdge(15, 16, 3); //Central San Pedro
    ge.addEdge(16, 17, 7); //Fantastic Sams Hair Salon
    ge.addEdge(17, 18, 5); //Lomita (Intersection)
    ge.addEdge(18, 19, 4);// Rolling Hills Estates
    ge.addEdge(19, 18, 4); //Malaga Cove
    // Add redundant edges to test connectivity and alternative paths
    ge.addEdge(0, 5, 6);  // Add a new road between Point Vicente and Abalone Cove
    ge.addEdge(4, 8, 7);  // Add a road between Trump National and Ocean Trails Reserve
    ge.addEdge(2, 6, 5);  // Connect Terranea Resort and Portuguese Bend Reserve
    // Add cross connections for complex paths
    ge.addEdge(9, 13, 4);  // White Point Beach ? Roll Stop Sushi
    ge.addEdge(1, 17, 8);  // Los Verdes Golf Course ? Lomita
    ge.addEdge(10, 15, 6); // Cabrillo Marine Aquarium ? Central San Pedro
    // Add local shortcuts
    ge.addEdge(11, 19, 3); // Korean Friendship Bell ? Malaga Cove
    ge.addEdge(3, 7, 5);   // Rancho Palos Verdes ? Forrestal Nature Reserve
    ge.addEdge(6, 10, 6);
    ge.addEdge(8, 14, 7);
    ge.addEdge(12, 18, 4);
    ge.addEdge(0, 9, 8);
    ge.addEdge(7, 15, 6);
    ge.addEdge(5, 11, 5);
    ge.addEdge(13, 17, 3);
    ge.addEdge(4, 19, 9);
    ge.addEdge(2, 12, 7);
    ge.addEdge(8, 16, 4);
    ge.addEdge(1, 14, 5);
    ge.addEdge(3, 10, 6);
    // Print graph representations
    cout << "Graph representation:\n";
    // Print Graph Representations
    g.printGraph();      // Adjacency List
    gm.printGraph();     // Adjacency Matrix
    ge.printGraph();     // Edge List

    // Run algorithms
    cout << "\nDijkstra's algorithm (starting from vertex 0):\n";
    auto start = chrono::high_resolution_clock::now();
    g.dijkstra(0);
    auto end = chrono::high_resolution_clock::now();
    cout << "Dijkstra's Execution Time: "
        << chrono::duration_cast<chrono::microseconds>(end - start).count()<< " microseconds" << endl;

    cout << "\nPrim's algorithm:\n";
     start = chrono::high_resolution_clock::now();
    g.prim();
     end = chrono::high_resolution_clock::now();
    cout << "Prim's Execution Time: "
        << chrono::duration_cast<chrono::microseconds>(end - start).count() << " microseconds" << endl;

    cout << "\nDepth First Search (starting from vertex 0):\n";
     start = chrono::high_resolution_clock::now();
    g.dfs(0);
     end = chrono::high_resolution_clock::now();
    cout << "Depth First Search's Execution Time: "
        << chrono::duration_cast<chrono::microseconds>(end - start).count() << " microseconds" << endl;
    
    // Repeat the above algorithms for Adjacency Matrix and Edge List representations
    cout << "\nDijkstra's algorithm (starting from vertex 0):\n";
    start = chrono::high_resolution_clock::now();
    gm.dijkstra(0);
    end = chrono::high_resolution_clock::now();
    cout << "Dijkstra's Execution Time: "
        << chrono::duration_cast<chrono::microseconds>(end - start).count() << " microseconds" << endl;

    cout << "\nPrim's algorithm:\n";

    gm.prim();
    end = chrono::high_resolution_clock::now();
    cout << "Prim's Execution Time: "
        << chrono::duration_cast<chrono::microseconds>(end - start).count() << " microseconds" << endl;

    cout << "\nDepth First Search (starting from vertex 0):\n";
    start = chrono::high_resolution_clock::now();
    gm.dfs(0);
    end = chrono::high_resolution_clock::now();
    cout << "Depth First Search's Execution Time: "
        << chrono::duration_cast<chrono::microseconds>(end - start).count() << " microseconds" << endl;



    // Repeat the above algorithms for Edge List representations

    cout << "\nDijkstra's algorithm (starting from vertex 0):\n";
    start = chrono::high_resolution_clock::now();
    ge.dijkstra(0);
    end = chrono::high_resolution_clock::now();
    cout << "Dijkstra's Execution Time: " << chrono::duration_cast<chrono::microseconds>(end - start).count() << " microseconds" << endl;

    cout << "\nPrim's algorithm:\n";
    ge.prim();
    end = chrono::high_resolution_clock::now();
    cout << "Prim's Execution Time: " << chrono::duration_cast<chrono::microseconds>(end - start).count() << " microseconds" << endl;

    cout << "\nDepth First Search (starting from vertex 0):\n";
    start = chrono::high_resolution_clock::now();
    ge.dfs(0);
    end = chrono::high_resolution_clock::now();
    cout << "Depth First Search's Execution Time: " << chrono::duration_cast<chrono::microseconds>(end - start).count() << " microseconds" << endl;


    return 0;
}