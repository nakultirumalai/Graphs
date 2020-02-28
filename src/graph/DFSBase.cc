# include "DFSBase.h"

// Constructor and destructor
DFSBase::DFSBase(const GraphBase &thisGraph, 
		 DFSBase::dfsTraverseType type,
		 int beginNode, bool traverseAll)
{
  int numNodes = thisGraph.getNumNodes();

  _markedNodes = vector<bool>(numNodes);
  _parentNodes = nodeList(numNodes);
  
  if (type == dfsTraverseType::DFS_TRAVERSE_PRE_ORDER) {
    if (traverseAll) 
      this->traversePreOrderFull(thisGraph, beginNode);
    else
      this->traversePreOrder(thisGraph, beginNode);
  } else if (type == dfsTraverseType::DFS_TRAVERSE_POST_ORDER) {
    if (traverseAll)
      this->traversePostOrderFull(thisGraph, beginNode);
    else
      this->traversePostOrder(thisGraph, beginNode);
  }
}

DFSBase::~DFSBase()
{

}

const nodeList&
DFSBase::getDFSPath()
{
  return _dfsPath;
}

void
DFSBase::traversePreOrder(const GraphBase &thisGraph, int beginNode)
{
  // Mark the node
  this->mark(beginNode);
  
  // Visit the node
  this->visit(beginNode);

  // Get all the nodes from begin node
  const nodeList &adjNodes = thisGraph.getAdjacentNodes(beginNode);
  
  // Iterate over the adjacent nodes and recursively call DFS on them
  nodeListConstIter iter = adjNodes.begin();
  for (; iter < adjNodes.end(); ++iter) {
    int adjNode = *(iter);

    // Skip marked nodes
    if (this->isMarked(adjNode))
      continue;

    // Push the node onto the stack
    _nodeStack.push_back(beginNode);
    
    // Recurse
    this->traversePreOrder(thisGraph, adjNode);
  }
  
  _nodeStack.pop_back();
}

void 
DFSBase::traversePreOrderFull(const GraphBase &thisGraph, int beginNode)
{
  // Traverse all the nodes reachable from "beginNode" recursively
  this->traversePreOrder(thisGraph, beginNode);

  // Check if the number of marked 
  if (thisGraph.getNumNodes() == this->getNumMarkedNodes()) {
    return;
  }

  // Iterate over the other nodes
  int numNodes = thisGraph.getNumNodes();
  for (int node = 0; node < numNodes; ++node) {
    // Skip marked nodes
    if (this->isMarked(node))
      continue;

    // Recurse
    this->traversePreOrder(thisGraph, node);
  }
}

void
DFSBase::traversePostOrder(const GraphBase &thisGraph, int beginNode)
{
  // Mark the node
  this->mark(beginNode);
  
  // Get all the nodes from begin node
  const nodeList &adjNodes = thisGraph.getAdjacentNodes(beginNode);
  
  // Iterate over the adjacent nodes and recursively call DFS on them
  nodeListConstIter iter = adjNodes.begin();
  for (; iter < adjNodes.end(); ++iter) {
    int adjNode = *(iter);

    // Skip marked nodes
    if (this->isMarked(adjNode))
      continue;

    // Push the node onto the stack
    _nodeStack.push_back(beginNode);
    
    // Recurse
    this->traversePreOrder(thisGraph, adjNode);
  }

  // Visit the node
  this->visit(beginNode);

  _nodeStack.pop_back();
}

void 
DFSBase::traversePostOrderFull(const GraphBase &thisGraph, int beginNode)
{
  // Traverse all the nodes reachable from "beginNode" recursively
  this->traversePostOrder(thisGraph, beginNode);

  // Check if the number of marked 
  if (thisGraph.getNumNodes() == this->getNumMarkedNodes()) {
    return;
  }

  // Iterate over the other nodes
  int numNodes = thisGraph.getNumNodes();
  for (int node = 0; node < numNodes; ++node) {
    // Skip marked nodes
    if (this->isMarked(node))
      continue;

    // Recurse
    this->traversePostOrderFull(thisGraph, node);
  }
}

int
DFSBase::getParentNode(int node)
{
  return _parentNodes[node];
}

void
DFSBase::mark(int node)
{
  _markedNodes[node] = true;
  _dfsPath.push_back(node);
  _parentNodes[node] = _nodeStack.back();
}

bool
DFSBase::isMarked(int node)
{
  return _markedNodes[node];
}
