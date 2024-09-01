#ifndef GRAPH_HPP
#define GRAPH_HPP

#include <vector>
#include <iostream>


//Shachar Achdut
//323856195

class Graph {

private:

  std::vector<std::vector<int>> adjMatrix;

  int numVertices;

  bool directed = false;

public:

  Graph(); //empty constructor;
  ~Graph(); //annihilator;
  void addEdge(int src, int dest);
  void loadGraph(const std::vector<std::vector<int>>& graph);
  void printGraph();
  int getNumVertices() const;
  std::vector<int> getNeighbors(int vertex) const;
  int getAdjMatrix(int current, int neighbor) const;
  std::vector<std::vector<int>> getAdjMatrix() const;
  bool getDirected() const;
  bool nXn(std::vector<std::vector<int>> Matrix) const;
  bool areMatrixEqual(const std::vector<std::vector<int>>& mat1, const std::vector<std::vector<int>>& mat2) const;

  Graph operator+(const Graph& other) const ;
  Graph& operator+=(const Graph& other);
  Graph operator+() const;
  Graph operator-(const Graph& other) const ;
  Graph& operator-=(const Graph& other);
  Graph operator-() const;
  Graph operator++() const;
  Graph operator--() const;
  Graph operator*(int k) const;
  Graph operator/(int k) const;
  Graph operator*(const Graph& other) const ;
  friend std::ostream& operator<<(std::ostream& os, const Graph& graph);
  bool operator==(const Graph& other) const;
  bool operator!=(const Graph& other) const;
  bool operator>=(const Graph& other) const;
  bool operator<=(const Graph& other) const;
  bool operator>(const Graph& other) const;
  bool operator<(const Graph& other) const;
};

#endif
