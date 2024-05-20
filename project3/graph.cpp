#include "Graph.hpp"
#include <iostream>
#include <queue>

Graph::Graph(int vertices, bool isMatrix) {
    V = vertices;
    if (isMatrix) {
        adjacencyMatrix.resize(V, std::vector<int>(V, 0));
    } else {
        adjacencyList.resize(V);
    }
}

void Graph::addEdgeMatrix(int u, int v, int weight) {
    adjacencyMatrix[u][v] = weight;
    adjacencyMatrix[v][u] = weight;
}

void Graph::addEdgeList(int u, int v, int weight) {
    adjacencyList[u].push_back(std::make_pair(v, weight));
    adjacencyList[v].push_back(std::make_pair(u, weight));
}

void Graph::primMST() {
    std::vector<int> parent(V, -1); // Array to store parent for each vertex
    std::vector<int> key(V, INT_MAX); // Array to store keys (weights) for each vertex
    std::vector<bool> inMST(V, false); // Array to store whether a vertex is already in the MST

    // Priority queue storing pairs (key, vertex)
    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> pq;

    // Choosing the first vertex as the source
    key[0] = 0;
    parent[0] = -1; // Source has no parent
    pq.push({0, 0}); // Add the first vertex as the source

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        inMST[u] = true; // Mark the vertex as added to MST

        // Updating keys for neighbors of the chosen vertex
        if (adjacencyMatrix.size() > 0) {
            for (int v = 0; v < V; ++v) {
                if (adjacencyMatrix[u][v] && !inMST[v] && adjacencyMatrix[u][v] < key[v]) {
                    parent[v] = u;
                    key[v] = adjacencyMatrix[u][v];
                    pq.push({key[v], v}); // Add the vertex with updated key to priority queue
                }
            }
        } else {
            for (auto& neighbor : adjacencyList[u]) {
                int v = neighbor.first;
                int weight = neighbor.second;
                if (!inMST[v] && weight < key[v]) {
                    parent[v] = u;
                    key[v] = weight;
                    pq.push({key[v], v}); // Add the vertex with updated key to priority queue
                }
            }
        }
    }

}

int Graph::find(std::vector<int>& parent, int i) {
    if (parent[i] != i)
        parent[i] = find(parent, parent[i]); // Path compression
    return parent[i];
}

void Graph::kruskalMST() {
    std::vector<Edge> edges; // Vector of edges

    // Converting the graph to a list of edges
    if (adjacencyMatrix.size() > 0) {
        for (int u = 0; u < V; ++u) {
            for (int v = u + 1; v < V; ++v) {
                if (adjacencyMatrix[u][v] != 0) {
                    edges.push_back({u, v, adjacencyMatrix[u][v]});
                }
            }
        }
    } else {
        for (int u = 0; u < V; ++u) {
            for (auto& neighbor : adjacencyList[u]) {
                int v = neighbor.first;
                int weight = neighbor.second;
                edges.push_back({u, v, weight});
            }
        }
    }

    // Sorting edges by weight
    std::sort(edges.begin(), edges.end(), [](const Edge& a, const Edge& b) {
        return a.weight < b.weight;
    });

    std::vector<int> parent(V); // Array to store parent for each vertex
    for (int i = 0; i < V; ++i) {
        parent[i] = i; // Initially, each vertex is its own parent
    }

    //std::cout << "Minimum Spanning Tree (Kruskal's algorithm):" << std::endl;
    int mstWeight = 0; // Total weight of MST
    for (const auto& edge : edges) {
        int u = edge.src;
        int v = edge.dest;
        int weight = edge.weight;

        // Checking if adding the edge will create a cycle
        int setU = find(parent, u);
        int setV = find(parent, v);
        if (setU != setV) {
            //std::cout << "Edge " << u << " - " << v << " with weight " << weight << std::endl;
            mstWeight += weight;
            parent[setU] = setV; // Union of sets
        }
    }

    //std::cout << "Weight of minimum spanning tree: " << mstWeight << std::endl;
}


void Graph::addRandomEdgesToMatrix(double density) {
    int expected_edge_count = (int)(density * V * (V - 1) / 2);
    int added_edge_count = 0;
    while (added_edge_count < expected_edge_count) {
        int u = rand() % V;
        int v = rand() % V;
        int weight = rand() % 10 + 1; // Random weight between 1 and 10
        if (u != v && adjacencyMatrix[u][v] == 0) {
            addEdgeMatrix(u, v, weight);
            ++added_edge_count;
        }
    }
    //std::cout << "Added edges: " << added_edge_count << std::endl; // Add this line
}

void Graph::addRandomEdgesToList(double density) {
    int expected_edge_count = (int)(density * V * (V - 1) / 2);
    int added_edge_count = 0;
    while (added_edge_count < expected_edge_count) {
        int u = rand() % V;
        int v = rand() % V;
        int weight = rand() % 10 + 1; // Random weight between 1 and 10
        // Check if the edge already exists in the adjacency list
        bool edgeExists = false;
        for (const auto& neighbor : adjacencyList[u]) {
            if (neighbor.first == v) {
                edgeExists = true;
                break;
            }
        }
        if (!edgeExists && u != v) {
            addEdgeList(u, v, weight);
            ++added_edge_count;
        }
    }
    //std::cout << "Added edges: " << added_edge_count << std::endl; // Add this line
}
