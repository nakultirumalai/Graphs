#ifndef BFS_H
#define BFS_H

#include <BFSBase.h>

class BFS : public BFSBase
{
 public:
  // Perform BFS of the entire graph by default
  // from the node 0
  BFS(int numNodes);
  ~BFS();

  // Visit a node
  void visit(int node);
};

#endif
