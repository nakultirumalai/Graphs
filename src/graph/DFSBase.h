#ifndef DFS_BASE_H
#define DFS_BASE_H

#include "GraphBase.h"

class DFSBase
{
 public:
  typedef enum {
    DFS_TRAVERSE_PRE_ORDER = 0,
    DFS_TRAVERSE_POST_ORDER
  } dfsTraverseType;

  typedef nodeList::const_iterator nodeListConstIter;
 public:
  // Constructor and destructor
  // Perform DFS of the entire graph by default
  // from the node 0
  DFSBase(const GraphBase &thisGraph);

  // Perform DFS of the entire graph by default
  // from the node 0
  DFSBase(const GraphBase &thisGraph, dfsTraverseType = dfsTraverseType::DFS_TRAVERSE_PRE_ORDER,
	  int beginNode = 0, bool traverseAll = true);

  ~DFSBase();
  
  // Get the DFS path
  const nodeList& getDFSPath();

  // Perform traversal of all nodes in a given graph
  // in the depth-first search manner
  virtual void traversePreOrder(const GraphBase &thisGraph, int nodeNum);
  virtual void traversePostOrder(const GraphBase &thisGraph, int nodeNum);

  virtual void traversePreOrderFull(const GraphBase &thisGraph, int nodeNum);
  virtual void traversePostOrderFull(const GraphBase &thisGraph, int nodeNum);

  // Visit a node
  virtual void visit(int node) { }

 protected:
  int getParentNode(int node);

 private:
  // Mark a node for search purposes
  void mark(int node);

  // Check if a node is Marked
  bool isMarked(int node);

  // Get the number of marked nodes
  int getNumMarkedNodes() { return _markedNodes.size(); }
  
  // DATA
  nodeList _nodeStack;
  nodeList _dfsPath;
  vector<bool> _markedNodes;
  nodeList _parentNodes;
};

#endif
