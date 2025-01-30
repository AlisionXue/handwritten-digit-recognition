#include "GraphType.h"
#include <iostream>
using namespace std;

// Corrected the method to be non-static and to access GraphType methods through an object
void allPairsShortestPaths(GraphType<string>& graph) {
    int numVertices = graph.getNumVertices();
    string** edg = graph.getEdges();
    for (int k = 0; k < numVertices; k++) {
        for (int i = 0; i < numVertices; i++) {
            for (int j = 0; j < numVertices; j++) {
                if (edg[i][k] != "-" && edg[k][j] != "-") {
                    string sum = graph.addWithInfinity(edg[i][k], edg[k][j]);
                    if (graph.isLessWithInfinity(sum, edg[i][j])) {
                        edg[i][j] = sum;
                    }
                }
            }
        }
    }
}

int main() {
    GraphType<string> myGraph(10);
    myGraph.AddVertex("A");
    myGraph.AddVertex("B");
    myGraph.AddVertex("C");
    myGraph.AddVertex("D");
    myGraph.AddVertex("E");
    myGraph.AddVertex("F");
    myGraph.AddVertex("G");

    myGraph.AddEdge("A", "B", 80);
    myGraph.AddEdge("B", "A", 80);
    myGraph.AddEdge("B", "C", 79);
    myGraph.AddEdge("B", "E", 153);
    myGraph.AddEdge("C", "B", 79);
    myGraph.AddEdge("C", "D", 78);
    myGraph.AddEdge("C", "F", 74);
    myGraph.AddEdge("D", "C", 78);
    myGraph.AddEdge("D", "E", 98);
    myGraph.AddEdge("D", "F", 89);
    myGraph.AddEdge("E", "B", 153);
    myGraph.AddEdge("E", "D", 98);
    myGraph.AddEdge("E", "F", 67);
    myGraph.AddEdge("F", "C", 74);
    myGraph.AddEdge("F", "D", 89);
    myGraph.AddEdge("F", "E", 67);
    myGraph.AddEdge("F", "G", 67);
    myGraph.AddEdge("G", "F", 67);

    cout << "Initial Graph:" << endl;
    cout << myGraph << endl;

    // Use the corrected allPairsShortestPaths function
    allPairsShortestPaths(myGraph);

    cout << "Graph after running Floyd's Algorithm:" << endl;
    cout << myGraph << endl;

    return 0;
}
