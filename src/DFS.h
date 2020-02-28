#ifndef DFS_H
#define DFS_H

#include <DFSBase.h>

class DFS : public DFSBase
{
 public:
  // Perform DFS of the entire graph by default
  // from the node 0
  DFS(int numNodes);
  ~DFS();

  // Visit a node
  void visit(int node);
};

#endif
