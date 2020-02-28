# include <BFSBase.h>

// Constructor and destructor
BFSBase::BFSBase(int numNodes)
{
  _markedNodes = vector<bool>(numNodes);
  _parentNodes = nodeList(numNodes);
  for (int i = 0; i < numNodes; i++) {
    _parentNodes[i] = -1;
  }
}

BFSBase::~BFSBase()
{

}

const nodeList&
BFSBase::getBFSPath()
{
  return _bfsPath;
}

void
BFSBase::traverse(const GraphBase &thisGraph, int beginNode)
{
  // Create a nodequeue
  nodeList nodeQueue;

  // Insert the first node onto the queue
  nodeQueue.push_back(beginNode);

  // Pop the queue and start traversing the adjacent nodes
  while (!nodeQueue.empty()) {
    int nodeOnQueue = nodeQueue.front();

    // Pop the top node on the queue
    nodeQueue.erase(nodeQueue.begin());
      
    // Mark the node
    this->mark(nodeOnQueue);

    // Visit the popped node
    this->visit(nodeOnQueue);

    // Get all the nodes from popped node
    const nodeList &adjNodes = 
      thisGraph.getAdjacentNodes(nodeOnQueue);
    nodeListConstIter iter = adjNodes.begin();
    for (; iter < adjNodes.end(); ++iter) {
      int adjNode = *(iter);

      // Skip marked nodes
      if (this->isMarked(adjNode))
	continue;

      // Mark the node
      this->mark(adjNode);

      // Add adjacent nodes to the queue
      nodeQueue.push_back(adjNode);
      
      // Assign parentNode 
      _parentNodes[adjNode] = nodeOnQueue;
    }
  }
}

void 
BFSBase::traverseFull(const GraphBase &thisGraph, int beginNode)
{
  // Traverse the begin node
  this->traverse(thisGraph, beginNode);
  
  // Work on traversing nodes which have not been 
  // traversed yet
  int numNodes = thisGraph.getNumNodes();
  for (int i = 0; i < numNodes; i++) {
    if (this->isMarked(i)) {
      continue;
    }
    this->traverse(thisGraph, i);
  }
}

int
BFSBase::getParentNode(int node)
{
  return _parentNodes[node];
}

void
BFSBase::mark(int node)
{
  _markedNodes[node] = true;
}

bool
BFSBase::isMarked(int node)
{
  return _markedNodes[node];
}
