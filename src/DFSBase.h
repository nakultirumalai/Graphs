# ifndef DFSBASE_H
# define DFSBASE_H

# include <GraphDefs.h>
# include <GraphBase.h>
# include <vector>

class DFSBase {
 public:
  // Typedefs
  typedef vector<int>::const_iterator nodeListConstIter;

  // Constructor and destructor
  DFSBase(int numNodes);
  virtual ~DFSBase();
  
  // Get the DFS Path
  const nodeList& getDFSPath();
  
  // Traversal functions
  void traversePreOrder(const GraphBase &thisGraph, int beginNode);
  void traversePreOrderFull(const GraphBase &thisGraph, int beginNode);
  void traversePostOrder(const GraphBase &thisGraph, int beginNode);
  void traversePostOrderFull(const GraphBase &thisGraph, int beginNode);
  
  // Node visit function
  virtual void visit(int node) { }

  // Get the parent node of a given node
  int getParentNode(int node);
  
 private:
  void mark(int node);
  bool isMarked(int node);

  nodeList _parentNodes;
  vector<bool> _markedNodes;
  nodeList _dfsPath;
  nodeList _nodeStack;
};
# endif
