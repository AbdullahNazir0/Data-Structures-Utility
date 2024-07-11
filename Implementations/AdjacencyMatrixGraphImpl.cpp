// ********************************************************
// Name: Abdullah Nazir
// Date: March 27, 2024
//
// Implementation file AdjacencyMatrixGraphImpl.cpp
// This file contains definitions of the functions declared
//  in the class AdjacencyMatrixGraph .
// ********************************************************

#include "../Headers/AdjacencyMatrixGraph.h"

#include <iostream>

template <typename T>
AdjacencyMatrixGraph<T>::AdjacencyMatrixGraph(bool isDirected, bool isWeighted) : Graph<T>(isDirected, isWeighted)
{
}

template <typename T>
void AdjacencyMatrixGraph<T>::insertVertex(const T &vertex)
{
    if (checkVertex(vertex))
    {
        std::cout << "Insertion failed, given vertex already exists in the graph.\n";
        return;
    }

    vertices.push_back(vertex);
    std::vector<double> temp;
    temp.insert(temp.end(), this->numberOfVertices + 1, this->isWeighted ? -1 : 0);
    for (auto &iter : matrix)
        iter.push_back(this->isWeighted ? -1 : 0);
    matrix.push_back(temp);
    vertexToIndex.insert({vertex, vertices.size() - 1});
    // vertexToIndex[vertex] = this->numberOfVertices;
    this->numberOfVertices++;
}

template <typename T>
void AdjacencyMatrixGraph<T>::insertEdge(const T &vertexFrom, const T &vertexTo, double weight)
{
    if (!checkVertex(vertexFrom))
    {
        std::cout << "Insertion failed, given from vertex doesnot exists.\n";
        return;
    }

    if (!checkVertex(vertexTo))
    {
        std::cout << "Insertion failed, given to vertex doesnot exists.\n";
        return;
    }

    matrix[getIndex(vertexFrom)][getIndex(vertexTo)] = (this->isWeighted ? weight : 1);
    if (!this->isDirected)
        matrix[getIndex(vertexTo)][getIndex(vertexFrom)] = (this->isWeighted ? weight : 1);
    this->numberOfEdges++;
}

template <typename T>
void AdjacencyMatrixGraph<T>::deleteVertex(const T &vertex)
{
    if (!checkVertex(vertex))
    {
        std::cout << "Deletion failed, given vertex dont exist.\n";
        return;
    }

    int index = getIndex(vertex);
    vertices.erase(vertices.begin() + index);
    vertexToIndex.erase(vertex);
    matrix.erase(matrix.begin() + index);
    for (auto &row : matrix)
    {
        row.erase(row.begin() + index);
    }
    this->numberOfVertices--;
}

template <typename T>
void AdjacencyMatrixGraph<T>::deleteEdge(const T &vertexFrom, const T &vertexTo)
{
    if (!checkVertex(vertexFrom))
    {
        std::cout << "Deletion failed, from vertex dont exists.\n";
        return;
    }

    if (!checkVertex(vertexTo))
    {
        std::cout << "Deletion failed, to vertex dont exists.\n";
        return;
    }

    if (matrix[getIndex(vertexFrom)][getIndex(vertexTo)] == (this->isWeighted ? -1 : 0))
    {
        std::cout << "Deletion failed, given edge dont exists.\n";
        return;
    }

    matrix[getIndex(vertexFrom)][getIndex(vertexTo)] = (this->isWeighted ? -1 : 0);
    if (!this->isDirected)
        matrix[getIndex(vertexTo)][getIndex(vertexFrom)] = (this->isWeighted ? -1 : 0);
    this->numberOfEdges--;
}

template <typename T>
void AdjacencyMatrixGraph<T>::displayBFS(const T &vertex) const
{
}

template <typename T>
void AdjacencyMatrixGraph<T>::displayDFS(const T &vertex) const
{
}

template <typename T>
bool AdjacencyMatrixGraph<T>::checkVertex(const T &vertex) const
{
    return (vertexToIndex.find(vertex) != vertexToIndex.end());
}

template <typename T>
bool AdjacencyMatrixGraph<T>::checkEdge(const T &vertexFrom, const T &vertexTo) const
{
    if (!checkVertex(vertexFrom) || !checkVertex(vertexTo))
        return (false);

    return (matrix[getIndex(vertexFrom)][getIndex(vertexTo)] != (this->isWeighted ? -1 : 0));
}

template <typename T>
int AdjacencyMatrixGraph<T>::findDegree(const T &vertex) const
{
    if (!checkVertex(vertex))
    {
        std::cout << "Cannot find degree, vertex dont exist.\n";
        return (-1);
    }

    int degree = 0;
    for (auto it = matrix[getIndex(vertex)].begin(); it != matrix[getIndex(vertex)].end(); it++)
    {
        if (*it != (this->isWeighted ? -1 : 0))
            degree++;
    }

    return (degree);
}

template <typename T>
int AdjacencyMatrixGraph<T>::findInDegree(const T &vertex) const
{
    if (!this->isDirected)
    {
        std::cout << "Cannot find out-degree, the graph is not directed.\n";
        return (-1);
    }

    if (!checkVertex(vertex))
    {
        std::cout << "Cannot find in-degree, vertex dont exist.\n";
        return (-1);
    }

    int degree = 0;
    int index = getIndex(vertex);
    for (const auto &row : matrix)
    {
        if (row[index] != (this->isWeighted ? -1 : 0))
            degree++;
    }

    return (degree);
}

template <typename T>
int AdjacencyMatrixGraph<T>::findOutDegree(const T &vertex) const
{
    if (!this->isDirected)
    {
        std::cout << "Cannot find out-degree, the graph is not directed.\n";
        return (-1);
    }

    if (!checkVertex(vertex))
    {
        std::cout << "Cannot find out-degree, vertex dont exist.\n";
        return (-1);
    }

    int degree = 0;
    for (auto it = matrix[getIndex(vertex)].begin(); it != matrix[getIndex(vertex)].end(); it++)
    {
        if (*it != (this->isWeighted ? -1 : 0))
            degree++;
    }

    return (degree);
}

template <typename T>
double AdjacencyMatrixGraph<T>::getWeight(const T &vertexFrom, const T &vertexTo) const
{
    if (!this->isWeighted)
    {
        std::cout << "Cannot get weight, graph is unweighted.\n";
        return (-1);
    }

    if (!checkVertex(vertexFrom))
    {
        std::cout << "Cannot get weight, from vertex doesnot exist.\n";
        return (-1);
    }

    if (checkVertex(vertexTo))
    {
        std::cout << "Cannot get weight, to vertex doesnot exist.\n";
        return (-1);
    }

    return (matrix[getIndex(vertexFrom)][getIndex(vertexTo)]);
}

template <typename T>
AdjacencyMatrixGraph<T>::~AdjacencyMatrixGraph() {}

template <typename T>
void AdjacencyMatrixGraph<T>::debug() const
{
    std::cout << "numberOfVertices: " << this->numberOfVertices << "\n";
    std::cout << "numberOfEdges: " << this->numberOfEdges << "\n";
    std::cout << "vertices: ";
    for (const auto &vertex : vertices)
        std::cout << vertex << " ";
    std::cout << "\n";
    std::cout << "matrix: \n";
    for (const auto &value : matrix)
    {
        for (auto subValue : value)
            std::cout << subValue << " ";
        std::cout << "\n";
    }
    std::cout << "vertexToIndex: \n";
    for (auto it = vertexToIndex.begin(); it != vertexToIndex.end(); it++)
        std::cout << it->first << " " << it->second << "\n";
}

// private function
template <typename T>
size_t AdjacencyMatrixGraph<T>::getIndex(const T &vertex) const
{
    auto it = vertexToIndex.find(vertex);
    return (it != vertexToIndex.end() ? it->second : SIZE_MAX);
}