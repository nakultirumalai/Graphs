#include <GraphBase.h>
#include <iostream>

// Constructor and destructor
GraphBase::GraphBase()
{

}

GraphBase::GraphBase(int numNodes):
  _adjList(vector<EdgeList>()),
  _edges()
{

}

GraphBase::~GraphBase()
{
  
}

void
GraphBase::addNode(int nodeNum)
{
  if (_adjList.size() <= nodeNum) {
    for (int i = _adjList.size(); i <= nodeNum; i++) {
      _adjList.push_back(EdgeList());
      _adjNodes.push_back(unordered_map<int, int>());
    }
  }
}

void
GraphBase::addEdge(int u, int v, int weight)
{
  int maxNode = u;
  int numNodes = this->getNumNodes();

  if (v > u) {
    maxNode = v;
  }
  
  this->addNode(maxNode);

  if (!this->hasEdge(u, v)) {
    Edge e(u, v, weight);
    _edges.push_back(e);
    (_adjList[u]).push_back(e);
    (_adjList[v]).push_back(e);
    (_adjNodes[u]).insert(std::make_pair(v, _edges.size() - 1));
  } else {
    int edgeIdx = (_adjNodes[u])[v];
    EdgeList& eList = _adjList[u];
    Edge &e = eList[edgeIdx];
    e.setWeight(weight);
  }
}

int
GraphBase::hasEdge(int u, int v) const
{
  if (u >= _adjList.size()) {
    return 0;
  }

  const unordered_map<int, int> &tmp = _adjNodes[u];
  unordered_map<int, int>::const_iterator iter = tmp.find(v);
  if (iter == tmp.end()) {
    return 0;
  }

  return iter->second;
}

const EdgeList &
GraphBase::getAllEdges() const
{
  return _edges;
}

int
GraphBase::getNumNodes() const
{
  return _adjList.size();
}

int
GraphBase::getNumEdges() const
{
  return _edges.size();
}

void
GraphBase::show() const
{
  int numNodes = _adjList.size();
  for (int i = 0; i < numNodes; i++) {
    cout << "Node: " << i << "  ";
    cout << "Edges: ";
    const EdgeList &eList = _adjList[i];
    int numEdges = eList.size();
    for (int j = 0; j < numEdges; j++) {
      const Edge& e = eList[j];
      string edgeStr = e.getShowStr();
      cout << edgeStr << "  ";
    }
    cout << endl;
  }
}

nodeList 
GraphBase::getAdjacentNodes(int u) const
{
  nodeList nList;

  if (u >= _adjList.size())
    return nList;
  
  const EdgeList& edgeList = _adjList[u];
  for (auto eIter = edgeList.begin();
       eIter < edgeList.end(); ++eIter) {
    const Edge& e = *(eIter);
    int v = e.getOtherNode(u);
    nList.push_back(v);
  }

  return nList;
}

nodeWeightList 
GraphBase::getAdjacentNodesWithWeights(int u) const
{
  nodeWeightList nwList;

  if (u < _adjList.size())
    return nwList;
  
  const EdgeList& edgeList = _adjList[u];
  for (auto eIter = edgeList.begin();
       eIter < edgeList.end(); ++eIter) {
    const Edge &e = *(eIter);
    int v = e.getOtherNode(u);
    int weight = e.getWeight();
    nwList.push_back(std::make_pair(v, weight));
  }
  
  return nwList;
}

