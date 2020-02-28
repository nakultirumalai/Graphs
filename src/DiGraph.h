#ifndef DIRECTED_GRAPH_H
#define DIRECTED_GRAPH_H

#include <GraphBase.h>

using namespace std;

class DiGraph : public GraphBase
{
 public:
  DiGraph(int n);
  DiGraph();
  virtual ~DiGraph();
  
  virtual void addEdge(int u, int v, int weight = 1);
};

#endif
