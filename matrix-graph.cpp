#include <iostream>
#include "Headers/AdjacencyMatrixGraph.h"

using namespace std;

template <typename T>
using AMG = AdjacencyMatrixGraph<T>;

int main()
{

    AMG<char> graph;

    cout << "Test 1 passed.\n";

    graph.debug();
    cout << "---------------------------------------\n";

    graph.insertVertex('A');
    graph.insertVertex('B');
    graph.insertVertex('C');
    graph.insertVertex('D');
    graph.insertVertex('E');
    // graph.insertVertex('F');
    // graph.insertVertex('G');
    // graph.insertVertex('H');
    // graph.insertVertex('I');
    // graph.insertVertex('J');
    // graph.insertVertex('K');
    // graph.insertVertex('L');
    // graph.insertVertex('M');
    // graph.insertVertex('N');
    // graph.insertVertex('O');
    // graph.insertVertex('P');
    // graph.insertVertex('Q');
    // graph.insertVertex('R');
    // graph.insertVertex('S');
    // graph.insertVertex('T');
    // graph.insertVertex('U');
    // graph.insertVertex('V');
    // graph.insertVertex('W');
    // graph.insertVertex('X');
    // graph.insertVertex('Y');
    // graph.insertVertex('Z');
    // graph.insertVertex('Z');

    graph.debug();
    cout << "---------------------------------------\n";

    graph.insertEdge('A', 'B');
    graph.insertEdge('A', 'A');
    graph.insertEdge('C', 'D');

    graph.debug();
    cout << "---------------------------------------\n";

    graph.deleteEdge('C', 'D');
    graph.deleteEdge('C', 'D');
    graph.deleteEdge('C', 'Q');

    graph.debug();
    cout << "---------------------------------------\n";

    cout << "A degree: " << graph.findDegree('A') << "\n";
    cout << "Q degree: " << graph.findDegree('Q') << "\n";

    cout << "---------------------------------------\n";

    graph.deleteVertex('A');

    graph.debug();
    cout << "---------------------------------------\n";

    return (0);
}