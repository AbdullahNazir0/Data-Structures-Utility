// ********************************************************
// Name: Abdullah Nazir
// Date: July 10, 2024
//
// Implementation file GraphImpl.cpp
// This file contains definitions of the functions declared
//  in the abstract class Graph .
// ********************************************************

#include "../Headers/Graph.h"

template <typename T>
Graph<T>::Graph(bool isDirected, bool isWeighted) : isDirected(isDirected), isWeighted(isWeighted)
{
    numberOfVertices = 0;
    numberOfEdges = 0;
}

template <typename T>
Graph<T>::~Graph() {}

template <typename T>
bool Graph<T>::isEmpty() const
{
    return (numberOfVertices == 0);
}

template <typename T>
int Graph<T>::getNumberOfVertices() const
{
    return (numberOfVertices);
}

template <typename T>
int Graph<T>::getNumberOfEdges() const
{
    return (numberOfEdges);
}