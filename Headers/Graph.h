// ********************************************************
// Name: Abdullah Nazir
// Date: July 10, 2024
//
// abstract class Graph
// This file contains implementation of data structure
// graph abstract class. This class will be extended to
// AdjencyListGraph and AdjencyMatrixStack.
// ********************************************************

#ifndef H_Graph
#define H_Graph

template <typename T>
class Graph
{
public:
    Graph(bool = 0, bool = 0);
    // Paramtereized constructor with default
    //  parameter.
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
    // It also initializes total number of vertices
    //  and edges to 0.

    virtual void insertVertex(const T &) = 0;
    // Pure virutal function to insert a vertex
    // in the graph.
    // It will be implemented in the concrete
    //  classes.

    virtual void insertEdge(const T &, const T &, double) = 0;
    // Pure virutal function to insert an edge
    // in the graph.
    // It takes two inputs, i.e vertices for
    //  which the edge will be added.
    // It will be implemented in the concrete
    //  classes.

    virtual void deleteVertex(const T &) = 0;
    // Pure virutal function to delete a vertex
    // from the graph.
    // If a vertex is deleted, its corresponding
    //  edges will also be deleted.
    // It will be implemented in the concrete
    //  classes.

    virtual void deleteEdge(const T &, const T &) = 0;
    // Pure virutal function to delete an edge
    // from the graph.
    // It takes two inputs, i.e vertices for
    //  which the edge will be deleted.
    // It will be implemented in the concrete
    //  classes.

    virtual void displayBFS(const T &) const = 0;
    // Pure virutal function to display the
    //  graph in BFS.
    // It takes a vertex as input,
    //  if the vertex is present, it starts
    //  traversing from that vertex.
    //  else it will print vertex not found.
    // It will be implemented in the concrete
    //  classes.

    virtual void displayDFS(const T &) const = 0;
    // Pure virutal function to display the
    //  graph in DFS.
    // It takes a vertex as input,
    //  if the vertex is present, it starts
    //  traversing from that vertex.
    //  else it will print vertex not found.
    // It will be implemented in the concrete
    //  classes.

    virtual bool checkVertex(const T &) const = 0;
    // Pure virutal function to check if a
    //  vertex is present in the graph.
    // It will return true, if it is present,
    //  and false otherwise.
    // It will be implemented in the concrete
    //  classes.

    virtual bool checkEdge(const T &, const T &) const = 0;
    // Pure virutal function to check if an
    //  edge is present in the graph.
    // It will return true, if it is present,
    //  and false otherwise.
    // It will be implemented in the concrete
    //  classes.

    virtual int findDegree(const T &) const = 0;
    // Pure virtual function to find the degree
    //  of a given vertex for a undirected graph.
    // It will check if a vertex is present, and
    //  return its degree if found,
    //  else it will return -1.
    // It will be implemented in the concrete
    //  classes.

    virtual int findInDegree(const T &) const = 0;
    // Pure virutal function to find the in-degree
    //  of a given vertex for a directed graph.
    // It will check if a vertex is present, and
    //  return its in-degree if found,
    //  else it will return -1.
    // It will be implemented in the concrete
    //  classes.

    virtual int findOutDegree(const T &) const = 0;
    // Pure virutal function to find the out-degree
    //  of a given vertex for a directed graph.
    // It will check if a vertex is present, and
    //  return its out-degree if found,
    //  else it will return -1.
    // It will be implemented in the concrete
    //  classes.

    virtual double getWeight(const T &, const T &) const = 0;
    // Pure virutal function to find the weight
    //  of a given edge between given two vertices.
    // It will check if the edge is present, and
    //  return its weight if found,
    //  else it will return -1.
    // It will be implemented in the concrete
    //  classes.

    bool isEmpty() const;
    // Function to check if the graph is empty.
    // It will return true for empty, and
    //  false for not empty.

    int getNumberOfVertices() const;
    // Function to return total number of
    //  vertices in the graph.

    int getNumberOfEdges() const;
    // Function to return total number of
    //  edges in the graph.

    virtual ~Graph();
    // Virtual Destructor function for
    //  abstract class Graph.

protected:
    const bool isDirected;
    const bool isWeighted;
    int numberOfVertices;
    int numberOfEdges;
};

#endif