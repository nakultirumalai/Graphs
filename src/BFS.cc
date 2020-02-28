# include <BFS.h>
# include <iostream>

// Constructor and destructor
BFS::BFS(int numNodes):
  BFSBase(numNodes)
{

}

BFS::~BFS()
{

}


void 
BFS::visit(int node)
{
  cout << "Visit node: " << node 
       << " Parent node: " << this->getParentNode(node) << "\n";
}
