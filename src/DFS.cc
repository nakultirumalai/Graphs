# include <DFS.h>
# include <iostream>

// Constructor and destructor
DFS::DFS(int numNodes):
  DFSBase(numNodes)
{

}

DFS::~DFS()
{

}


void 
DFS::visit(int node)
{
  cout << "Visit node: " << node 
       << " Parent node: " << this->getParentNode(node) << "\n";
}
