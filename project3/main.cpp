#include "Graph.hpp"
#include <iostream>
#include <chrono> // For measuring time

using namespace std;

// Function to run MST algorithms and measure time
void runMSTTest(Graph& graph, const string& representation) {
    double totalPrimTime = 0;
    double totalKruskalTime = 0;
    const int numIterations = 100;

    for (int i = 0; i < numIterations; ++i) {
        auto start = chrono::steady_clock::now();
        graph.primMST();
        auto end = chrono::steady_clock::now();
        auto diff = end - start;
        totalPrimTime += chrono::duration<double, milli>(diff).count();

        start = chrono::steady_clock::now();
        graph.kruskalMST();
        end = chrono::steady_clock::now();
        diff = end - start;
        totalKruskalTime += chrono::duration<double, milli>(diff).count();
    }

    cout << "Average time taken for Prim's algorithm with " << representation << ": "
        << (totalPrimTime / numIterations) << " ms" << endl;

    cout << "Average time taken for Kruskal's algorithm with " << representation << ": "
        << (totalKruskalTime / numIterations) << " ms" << endl;
}

int main() {
    // Different numbers of vertices
    vector<int> vertexCounts = { 100, 200, 300, 400, 500, 600, 700, 800, 900, 1000 };

    // Different densities
    vector<double> densities = { 0.25, 0.5, 0.75, 1 }; // 25%, 50%, 75%, 100%

    for (int vertices : vertexCounts) {
        for (double density : densities) {
            cout << "Testing for " << vertices << " vertices with density " << (density * 100) << "%" << endl;

            // Create graph with matrix representation
            Graph graphMatrix(vertices, true);
            graphMatrix.addRandomEdgesToMatrix(density);
            runMSTTest(graphMatrix, "adjacency matrix");

            // Create graph with list representation
            Graph graphList(vertices, false);
            graphList.addRandomEdgesToList(density);
            runMSTTest(graphList, "adjacency list");

            cout << "--------------------------------------------------" << endl << endl;
        }
    }

    return 0;
}
