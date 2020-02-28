# ifndef BFSBASE_H
# define BFSBASE_H

# include <GraphDefs.h>
# include <GraphBase.h>
# include <vector>

class BFSBase {
 public:
  // Typedefs
  typedef vector<int>::const_iterator nodeListConstIter;

  // Constructor and destructor
  BFSBase(int numNodes);
  virtual ~BFSBase();
  
  // Get the BFS Path
  const nodeList& getBFSPath();
  
  // Traversal functions
  void traverse(const GraphBase &thisGraph, int beginNode);
  void traverseFull(const GraphBase &thisGraph, int beginNode);
  
  // Node visit function
  virtual void visit(int node) { }

  // Get the parent node of a given node
  int getParentNode(int node);
  
 private:
  void mark(int node);
  bool isMarked(int node);

  nodeList _parentNodes;
  vector<bool> _markedNodes;
  nodeList _bfsPath;
};
# endif
