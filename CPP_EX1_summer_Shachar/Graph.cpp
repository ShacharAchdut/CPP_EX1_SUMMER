#include <iostream>
#include <vector>
#include <stdexcept>
#include <algorithm>
#include "Graph.hpp"


//Shachar Achdut
//323856195

using namespace std;


Graph::Graph() {
}


Graph::~Graph() {}


void Graph::addEdge(int src, int dest) {
    if (src < 0 || src >= numVertices || dest < 0 || dest >= numVertices) {
        throw std::invalid_argument("Invalid node");
    }
    if ((adjMatrix[static_cast<size_t>(src)][static_cast<size_t>(dest)] == 0) && 
        (adjMatrix[static_cast<size_t>(dest)][static_cast<size_t>(src)] == 0)) {
        adjMatrix[static_cast<size_t>(src)][static_cast<size_t>(dest)] = 1;
        adjMatrix[static_cast<size_t>(dest)][static_cast<size_t>(src)] = 1;
    } else {
        cout << "Existing edge" << endl;
    }
}



void Graph::loadGraph(const vector<vector<int>>& graph) {
    for (const auto& row : graph) {
        if (row.size() != graph.size()) {
            throw std::invalid_argument("All rows must be of equal length");
        }
    }

    numVertices = graph.size();
    adjMatrix.resize(graph.size(), vector<int>(graph.size()));

    for (std::vector<int>::size_type i = 0; i < graph.size(); i++) {
        for (std::vector<int>::size_type j = 0; j < graph[i].size(); j++) {
            adjMatrix[i][j] = graph[i][j];
            if(graph[i][j] != graph[j][i]){
                directed = true;
            }
        }
    }
}



void Graph::printGraph(){
    for (std::vector<int>::size_type i = 0; i < adjMatrix.size(); i++) {
        for (std::vector<int>::size_type j = 0; j < adjMatrix[i].size(); j++) {
            cout << adjMatrix[i][j] << " ";
        }
        cout << endl;
    }
}



int Graph::getNumVertices() const {
    return numVertices;
}



std::vector<int> Graph::getNeighbors(int vertex) const {
    if (vertex < 0 || vertex >= numVertices) {
        throw std::invalid_argument("Invalid vertex");
    }
    return adjMatrix[static_cast<std::vector<int>::size_type>(vertex)];
}



int Graph::getAdjMatrix(int current, int neighbor) const {
    if (current < 0 || current >= numVertices || neighbor < 0 || neighbor >= numVertices) {
        return -1; //invalid V;
    }
    return adjMatrix[static_cast<std::vector<int>::size_type>(current)][static_cast<std::vector<int>::size_type>(neighbor)];
}



std::vector<std::vector<int>> Graph::getAdjMatrix() const{
    return adjMatrix;
}



bool Graph::getDirected() const {
    return directed;
}



bool Graph::nXn(std::vector<std::vector<int>> Matrix) const {
    if (Matrix.size() == Matrix[0].size()) {
    return true;
  }
  return false;
}



bool Graph::areMatrixEqual(const std::vector<std::vector<int>>& mat1, const std::vector<std::vector<int>>& mat2) const {
    for (std::size_t i = 0; i < mat1.size(); ++i) {
        for (size_t j = 0; j < mat1.size(); j++) {
            if (mat1[i][j] != mat2[i][j]) {
                return false;
            }
        }
    }
    return true;
}



Graph Graph::operator+(const Graph& other) const {
    if (adjMatrix.size() != other.adjMatrix.size() || adjMatrix[0].size() != other.adjMatrix[0].size()) {
        throw std::invalid_argument("Graph dimensions do not match!");
    }

    Graph temp;
    temp.numVertices = other.adjMatrix.size();
    temp.adjMatrix.resize(static_cast<std::size_t>(temp.numVertices), vector<int>(static_cast<std::size_t>(temp.numVertices)));

    for (std::size_t i = 0; i < temp.adjMatrix.size(); ++i) {
        for (std::size_t j = 0; j < temp.adjMatrix[0].size(); ++j) {
            temp.adjMatrix[i][j] = adjMatrix[i][j] + other.adjMatrix[i][j];
        }
    }

    return temp;
}



Graph& Graph::operator+=(const Graph& other) {
    if (adjMatrix.size() != other.adjMatrix.size() || adjMatrix[0].size() != other.adjMatrix[0].size()) {
        throw std::invalid_argument("Graph dimensions do not match!");
    }

    for (std::size_t i = 0; i < adjMatrix.size(); ++i) {
        for (std::size_t j = 0; j < adjMatrix[0].size(); ++j) {
            adjMatrix[i][j] += other.adjMatrix[i][j];
        }
    }

    return *this;
}



Graph Graph::operator+() const {
    Graph temp(*this); // Create a copy of the original matrix

    // Iterate over each element and apply unary plus operator
    for (std::size_t i = 0; i < temp.adjMatrix.size(); ++i) {
        for (std::size_t j = 0; j < temp.adjMatrix[i].size(); ++j) {
            temp.adjMatrix[i][j] = abs(temp.adjMatrix[i][j]);
        }
    }

    return temp;
}



Graph Graph::operator-(const Graph& other) const {
    if (adjMatrix.size() != other.adjMatrix.size() || adjMatrix[0].size() != other.adjMatrix[0].size()) {
        throw std::invalid_argument("Graph dimensions do not match!");
    }

    Graph temp;
    temp.numVertices = other.adjMatrix.size();
    temp.adjMatrix.resize(static_cast<std::size_t>(temp.numVertices), vector<int>(static_cast<std::size_t>(temp.numVertices)));

    for (std::size_t i = 0; i < temp.adjMatrix.size(); ++i) {
        for (std::size_t j = 0; j < temp.adjMatrix[0].size(); ++j) {
            temp.adjMatrix[i][j] = adjMatrix[i][j] - other.adjMatrix[i][j];
        }
    }

    return temp;
}



Graph& Graph::operator-=(const Graph& other) {
    if (adjMatrix.size() != other.adjMatrix.size() || adjMatrix[0].size() != other.adjMatrix[0].size()) {
        throw std::invalid_argument("Graph dimensions do not match!");
    }

    for (std::size_t i = 0; i < adjMatrix.size(); ++i) {
        for (std::size_t j = 0; j < adjMatrix[0].size(); ++j) {
            adjMatrix[i][j] -= other.adjMatrix[i][j];
        }
    }

    return *this;
}



Graph Graph::operator-() const {
    Graph temp(*this); // Create a copy of the original matrix

    // Iterate over each element and apply unary plus operator
    for (std::size_t i = 0; i < temp.adjMatrix.size(); ++i) {
        for (std::size_t j = 0; j < temp.adjMatrix[i].size(); ++j) {
            temp.adjMatrix[i][j] = -abs(temp.adjMatrix[i][j]);
        }
    }

    return temp;
}



Graph Graph::operator++() const {
    Graph temp(*this); // Create a copy of the original matrix

    // Iterate over each element and apply unary plus operator
    for (std::size_t i = 0; i < temp.adjMatrix.size(); ++i) {
        for (std::size_t j = 0; j < temp.adjMatrix[i].size(); ++j) {
            ++temp.adjMatrix[i][j];
        }
    }

    return temp;
}



Graph Graph::operator--() const {
    Graph temp(*this); // Create a copy of the original matrix

    // Iterate over each element and apply unary plus operator
    for (std::size_t i = 0; i < temp.adjMatrix.size(); ++i) {
        for (std::size_t j = 0; j < temp.adjMatrix[i].size(); ++j) {
            --temp.adjMatrix[i][j];
        }
    }

    return temp;
}



Graph Graph::operator*(int k) const {
    Graph temp(*this); // Create a copy of the original matrix

    // Iterate over each element and apply unary plus operator
    for (std::size_t i = 0; i < temp.adjMatrix.size(); ++i) {
        for (std::size_t j = 0; j < temp.adjMatrix[i].size(); ++j) {
            temp.adjMatrix[i][j] *= k;
        }
    }

    return temp;
}



Graph Graph::operator/(int k) const {
    Graph temp(*this); // Create a copy of the original matrix

    // Iterate over each element and apply unary plus operator
    for (std::size_t i = 0; i < temp.adjMatrix.size(); ++i) {
        for (std::size_t j = 0; j < temp.adjMatrix[i].size(); ++j) {
            temp.adjMatrix[i][j] /= k;
        }
    }

    return temp;
}



Graph Graph::operator*(const Graph& other) const {
    if (adjMatrix.size() != other.adjMatrix.size() || adjMatrix[0].size() != other.adjMatrix[0].size()) {
        throw std::invalid_argument("Graph dimensions do not match!");
    }

    Graph temp;
    temp.numVertices = other.adjMatrix.size();
    temp.adjMatrix.resize(static_cast<std::size_t>(temp.numVertices), vector<int>(static_cast<std::size_t>(temp.numVertices)));

    for (std::size_t i = 0; i < temp.adjMatrix.size(); ++i) {
        for (std::size_t j = 0; j < temp.adjMatrix[0].size(); ++j) {
            temp.adjMatrix[i][j] = adjMatrix[i][j] * other.adjMatrix[i][j];
        }
    }

    return temp;
}



std::ostream& operator<<(std::ostream& os, const Graph& graph) {
    for (std::size_t i = 0; i < graph.adjMatrix.size(); ++i) {
        for (std::size_t j = 0; j < graph.adjMatrix[0].size(); ++j) {
            os << graph.adjMatrix[i][j] << " ";
        }
        os << "\n";
    }
    return os;
}



bool Graph::operator==(const Graph& other) const {
    if (adjMatrix.size() != other.adjMatrix.size() || adjMatrix[0].size() != other.adjMatrix[0].size()) {
        throw std::invalid_argument("Graph dimensions do not match!");
    }

    for (std::size_t i = 0; i < adjMatrix.size(); ++i) {
        for (std::size_t j = 0; j < adjMatrix[0].size(); ++j) {
            if (adjMatrix[i][j] != other.adjMatrix[i][j])
            {
                return false;
            }
        }
    }
    return true;
}



bool Graph::operator!=(const Graph& other) const {
    return !(*this == other);
}



bool Graph::operator>(const Graph& other) const {

  if (adjMatrix.size() != adjMatrix[0].size() || other.adjMatrix.size() != other.adjMatrix[0].size()) {
    return false;
  }
  
  if (adjMatrix.size() < other.adjMatrix.size() || adjMatrix[0].size() < other.adjMatrix[0].size()) {
    return false;
  }
  Graph temp;
    temp.numVertices = other.adjMatrix.size();
    temp.adjMatrix.resize(static_cast<std::size_t>(other.numVertices), vector<int>(static_cast<std::size_t>(other.numVertices)));

  int Matrixsize = adjMatrix.size() - 1;
  int Matrixsizel = adjMatrix[0].size() - 1;
  int max = other.numVertices - 1;
  int max2 = other.numVertices - 2;
  int k = 0;
  int l = 0;
  int flag = 1;
  

  while (flag){
    for (int i = 0; i < other.adjMatrix.size(); ++i) {
        for (int j = 0; j < other.adjMatrix.size(); ++j) {
           temp.adjMatrix[static_cast<std::size_t>(i)][static_cast<std::size_t>(j)] = adjMatrix[static_cast<std::size_t>(i + l)][static_cast<std::size_t>(j + k)];
        }
    }

    bool areEqual = areMatrixEqual(temp.adjMatrix,other.adjMatrix);
    if (areEqual){
        return true;
    }
    else {
        if ((k + max) <= Matrixsize){
            k++;
        }
        if ((k + max2) == Matrixsize && (l + max) <= Matrixsizel){
            l++;
            if ((l + max2) != Matrixsizel){
                k = 0;
            }
        }
    }
    if ((k + other.numVertices) > Matrixsize && (l + max) > Matrixsizel){
        return false;
    }
  }
  return true;
}


bool Graph::operator>=(const Graph& other) const {
    
  if (adjMatrix.size() != adjMatrix[0].size() || other.adjMatrix.size() != other.adjMatrix[0].size()) {
    return false;
  }
  
  if (adjMatrix.size() < other.adjMatrix.size() || adjMatrix[0].size() < other.adjMatrix[0].size()) {
    return false;
  }
  Graph temp;
    temp.numVertices = other.adjMatrix.size();
    temp.adjMatrix.resize(static_cast<std::size_t>(other.numVertices), vector<int>(static_cast<std::size_t>(other.numVertices)));

  int Matrixsize = adjMatrix.size() - 1;
  int Matrixsizel = adjMatrix[0].size() - 1;
  int max = other.numVertices - 1;
  int max2 = other.numVertices - 2;
  int k = 0;
  int l = 0;
  int flag = 1;
  

  while (flag){
    for (int i = 0; i < other.adjMatrix.size(); ++i) {
        for (int j = 0; j < other.adjMatrix.size(); ++j) {
           temp.adjMatrix[static_cast<std::size_t>(i)][static_cast<std::size_t>(j)] = adjMatrix[static_cast<std::size_t>(i + l)][static_cast<std::size_t>(j + k)];
        }
    }

    bool areEqual = areMatrixEqual(temp.adjMatrix,other.adjMatrix);
    if (areEqual){
        return true;
    }
    else {
        if ((k + max) <= Matrixsize){
            k++;
        }
        if ((k + max2) == Matrixsize && (l + max) <= Matrixsizel){
            l++;
            if ((l + max2) != Matrixsizel){
                k = 0;
            }
        }
    }
    if ((k + other.numVertices) > Matrixsize && (l + max) > Matrixsizel){
        return false;
    }
  }
  return true;
}

bool Graph::operator<(const Graph& other) const {
    return adjMatrix.size() < other.adjMatrix.size();
}

bool Graph::operator<=(const Graph& other) const {
    return adjMatrix.size() <= other.adjMatrix.size();
}
