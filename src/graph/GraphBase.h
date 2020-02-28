#ifndef GRAPH_BASE_H
#define GRAPH_BASE_H

#include "GraphDefs.h"
#include <vector>
#include <unordered_map>

using namespace std;

class Edge {
 public:
  // Constructor and destructor
  Edge(int from, int to, int weight):
    _from(from), _to(to), _weight(weight) {}
  ~Edge() {}
  int getFromNode() const { return _from; }
  int getToNode() const { return _to; }
  int getOtherNode(int node) const { 
    if (_from == node) 
      return _to;
    else
      return _from;
  }
  void setWeight(int weight) {
    _weight = weight;
  }

  int getWeight() const { return _weight; }

 private:
  int _from;
  int _to;
  int _weight;
};

typedef vector<Edge> EdgeList;

class GraphBase
{
 public:
  
  // Constructor and destructor
  GraphBase();
  GraphBase(int n);
  ~GraphBase();

  // Add a node to a graph
  virtual void addNode(int u);
  
  // Add an edge between nodes u and v
  virtual void addEdge(int u, int v, int weight = 1);
  
  // Check if there exists an edge between nodes u and v
  virtual int hasEdge(int u, int v) const;

  // Get all the nodes of the Graph
  const EdgeList &getAllEdges() const;

  // Get the number of nodes in the Graph
  int getNumNodes() const;

  // Get the number of edges in the Graph
  int getNumEdges() const;

  // Get all edges connected to given node u with 
  // and without weights
  virtual nodeList getAdjacentNodes(int u) const;
  virtual nodeWeightList getAdjacentNodesWithWeights(int u) const;

 private:
  vector<EdgeList> _adjList;
  vector<unordered_map<int, int>> _adjNodes;
  EdgeList _edges;
};

#endif
