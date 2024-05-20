#ifndef GRAPH_HPP
#define GRAPH_HPP

#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <climits>

// Structure representing an edge in the graph
struct Edge {
    int src, dest, weight;
};

// Class representing a graph in either adjacency matrix or adjacency list representation
class Graph {
private:
    int V; // Number of vertices
    std::vector<std::vector<int>> adjacencyMatrix; // Adjacency matrix
    std::vector<std::list<std::pair<int, int>>> adjacencyList; // Adjacency list

public:
    // Constructor for adjacency matrix representation
    Graph(int vertices, bool isMatrix);

    // Adding an edge for adjacency matrix representation
    void addEdgeMatrix(int u, int v, int weight);

    // Adding an edge for adjacency list representation
    void addEdgeList(int u, int v, int weight);

    // Prim's algorithm
    void primMST();

    // Kruskal's algorithm
    void kruskalMST();

    // Add random
    void addRandomEdgesToMatrix(double density);
    void addRandomEdgesToList(double density);


private:
    // Helper function to find the vertex with the smallest key among those not yet in MST
    int minKey(const std::vector<int>& key, const std::vector<bool>& inMST);

    // Helper function to find the set to which a vertex belongs (union-find algorithm)
    int find(std::vector<int>& parent, int i);
};

#endif // GRAPH_HPP
