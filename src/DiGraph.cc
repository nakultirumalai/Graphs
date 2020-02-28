# include "DiGraph.h"

// Constructor and Destructor
DiGraph::DiGraph(int n):
  GraphBase(n)
{

}

DiGraph::DiGraph():
  GraphBase()
{

}

DiGraph::~DiGraph()
{
  
}

void
DiGraph::addEdge(int u, int v, int weight)
{
  int maxNode = u;
  int numNodes = GraphBase::getNumNodes();

  if (v > u) {
    maxNode = v;
  }
  
  GraphBase::addNode(maxNode);

  if (!GraphBase::hasEdge(u, v)) {
    Edge e(u, v, weight);
    _edges.push_back(e);
    (_adjList[u]).push_back(e);
    (_adjNodes[u]).insert(std::make_pair(v, _edges.size() - 1));
  } else {
    int edgeIdx = (_adjNodes[u])[v];
    EdgeList& eList = _adjList[u];
    Edge &e = eList[edgeIdx];
    e.setWeight(weight);
  }
}
