# include <DFS.h>
# include <GraphBase.h>

class testGraphRun
{
public:
  testGraphRun(const string &fileName);
  ~testGraphRun();

  void runDFS(int nodeNum);
  void runDFSPostOrder(int nodeNum);
  void runBFS(int nodeNum);
  void runPrims(int nodeNum);
  void runKruskals(int nodeNum);
  void runShortestPath(int src, int dest);
  void runShortestPathAll();
  void runTopoSort();
  void runCheckCycle();
  void runBridges();
  void runAnchorPoints();
  void runCheckBipartite();

private:
  void readGraph(std::ifstream &inputFile);
  int  processOneLine(string &line);
  vector<string> tokenize(string &line);
  
private:
  GraphBase *_graphBase;
};
