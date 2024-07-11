// ********************************************************
// Name: Abdullah Nazir
// Date: July 11, 2024
//
// class AdjacencyMatrixGraph
// This file contains implementation of data structure
// graph implemented with adjacency matrix method by
// inheriting from abstract class Graph with extended
// features and functionalitites.
// ********************************************************

#ifndef H_AdjacencyMatrixGraph
#define H_AdjacencyMatrixGraph

#include "Graph.h"
#include <vector>
#include <unordered_map>

template <typename T>
class AdjacencyMatrixGraph : public Graph<T>
{
public:
    AdjacencyMatrixGraph(bool = false, bool = false);
    // Paramtereized constructor with default
    //  parameters.
    // This constructor takes two boolean parameters
    //  isDirected and isWeighted as input, with
    // default values as false.
    // If the isDirected is false, the graph will
    //  be undirected.
    // Else the graph will be directed.
    // Similarly,
    // If the isWeighted is false, the graph will
    //  be unweighted.
    // Else the graph will be weighted.
    // It also calls the constructor of the porent
    //  class Graph.

    void insertVertex(const T &) override;
    // Overriden function insertVertex to insert
    //  a given vertex in the graph.

    void insertEdge(const T &, const T &, double = 1.0) override;
    // Overriden function insertEdge to insert
    //  a given edge between two given vertices
    //  in the graph.

    void deleteVertex(const T &) override;
    // Overriden function deleteVertex to delete
    //  a given vertex in the graph.

    void deleteEdge(const T &, const T &) override;
    // Overriden function deleteEdge to delete
    //  a given edge between two given vertices
    //  in the graph.

    void displayBFS(const T &) const override;
    // Overriden function displayBFS to print
    //  the graph using Breadth First Search,
    //  starting from a given vertex.

    void displayDFS(const T &) const override;
    // Overriden function displayDFS to print
    //  the graph using Depth First Search,
    //  starting from a given vertex.

    bool checkVertex(const T &) const override;
    // Overriden function checkVertex to check if a
    //  given vertex is present in graph.

    bool checkEdge(const T &, const T &) const override;
    // Overriden function checkEdge to check if a
    //  given edge is present in graph, between
    //  given two vertices.

    int findDegree(const T &) const override;
    // Overriden function findDegree to find the
    //  degree of a given vertex in the graph.
    // Note: The graph should be undirected.

    int findInDegree(const T &) const override;
    // Overriden function findInDegree to find the
    //  in-degree of a given vertex in the graph.
    // Note: The graph should be directed.

    int findOutDegree(const T &) const override;
    // Overriden function findOutDegree to find the
    //  out-degree of a given vertex in the graph.
    // Note: The graph should be directed.

    double getWeight(const T &, const T &) const override;
    // Overriden function getWeight to find the
    //  weight of a given edge in the graph, from
    //  given two vertices.
    // Note: The graph should be weighted.

    ~AdjacencyMatrixGraph();
    // Destructor functions for AdjacencyMatrixGraph
    //  to delete dynamic resources if any.

    void debug() const;

private:
    std::vector<T> vertices;
    std::vector<std::vector<double>> matrix;
    std::unordered_map<T, size_t> vertexToIndex;

    size_t getIndex(const T &vertex) const;
};

#include "../Implementations/AdjacencyMatrixGraphImpl.cpp"

#endif