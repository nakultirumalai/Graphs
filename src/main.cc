# include <main.h>
# include <iostream>
# include <istream>
# include <fstream>
# include <sstream>
# include <Graph.h>
# include <DiGraph.h>
# include <DFS.h>
# include <BFS.h>

using namespace std;

//-------------------------- testDFS section -------------------------
testGraphRun::testGraphRun(const string &filename)
{
  ifstream inputFile;

  inputFile.open(filename, ifstream::in);
  
  if (inputFile.is_open()) {
    readGraph(inputFile);
  }
}

testGraphRun::~testGraphRun()
{

}

void
testGraphRun::runDFS(int nodeNum)
{
  DFS d(_graphBase->getNumNodes());
  
  d.traversePreOrderFull(*_graphBase, nodeNum);
}

void
testGraphRun::runDFSPostOrder(int nodeNum)
{
  DFS d(_graphBase->getNumNodes());
  
  d.traversePostOrderFull(*_graphBase, nodeNum);
}

void
testGraphRun::runBFS(int nodeNum)
{
  BFS b(_graphBase->getNumNodes());
  
  b.traverseFull(*_graphBase, nodeNum);
}

void
testGraphRun::runPrims(int nodeNum)
{
  // Prims p(_graphBase->getNumNodes());
  
  // p.minSpanningTree(*_graphBase, nodeNum);
}

void
testGraphRun::runKruskals(int nodeNum)
{
  // Kruskals k(_graphBase->getNumNodes());
  
  // k.minSpanningTree(*_graphBase, nodeNum);
}

void
testGraphRun::runShortestPath(int src, int dest)
{
  // Djikstra shortestPath(_graphBase->getNumNodes());
  
  // shortestPath.run(*_graphBase, src, dest);
}

void
testGraphRun::runShortestPathAll()
{
  // FloydWarshall fw(_graphBase->getNumNodes());
  
  // fw.run(*_graphBase);
}

void
testGraphRun::runTopoSort()
{
  // FloydWarshall fw(_graphBase->getNumNodes());
  
  // fw.run(*_graphBase);
}

void
testGraphRun::readGraph(ifstream &inputFile)
{
  string str;
  while (getline(inputFile, str)) {
    if (str == "directed") {
      DiGraph *dg = new DiGraph();
      _graphBase = dg;
      continue;
    } else if (str == "undirected") {
      Graph *g = new Graph();
      _graphBase = g;
      continue;
    }
    if (this->processOneLine(str) == 0) {
      break;
    }
  }

  cout << "Completed reading the graph:" << endl;
  if (_graphBase) {
    _graphBase->show();
  }
}

int
testGraphRun::processOneLine(string &line)
{
  int rtv = 1;

  if (line == "") {
    return rtv;
  }
  cout << "Processing input: " << line << endl;

  // tokenize with space
  vector<string> results = this->tokenize(line);
  int size = results.size();
  if (size == 0) {
    return 1;
  }

  int node1 = -1;
  int node2 = -1;
  int weight = -1;
  bool weightFound = false;
  if (size >= 2) {
    node1 = stoi(results[0]);
    node2 = stoi(results[1]);
    if (size == 3) {
      weight = stoi(results[2]);
      weightFound = true;
    } else if (size > 3) {
      cout << "Error in graph format";
      rtv = 0;
    }
  }
  
  if (rtv != 0) {
    if (weightFound) {
      _graphBase->addEdge(node1, node2, weight);
    } else {
      _graphBase->addEdge(node1, node2);
    }
  }

  return rtv;
}

vector<string>
testGraphRun::tokenize(string &line)
{
  stringstream ss(line);
  vector<string> result;
  string tmp;

  while (!ss.eof()) {
    ss >> tmp;

    result.push_back(tmp);
  }
  
  return result;
}

//-------------------------- testDFS section -------------------------

int
main(int argc, char **argv)
{
  if (argc == 1) {
    cout << "Error: Please enter graph filename" << endl;
    return 0;
  } else if (argc == 2) {
    cout << "Please enter a traversal command:" << endl;
    cout << "   DFS                           " << endl;
    cout << "   DFSPostOrder                  " << endl;
    cout << "   BFS                           " << endl;
    cout << "   Prims                         " << endl;
    cout << "   Kruskals                      " << endl;
    cout << "   ShortestPath                  " << endl;
    cout << "   ShortestPathAll               " << endl;
    cout << "   TopoSort                      " << endl;
    cout << "   Bridges                       " << endl;
    cout << "   AnchorPoints                  " << endl;
    cout << "   Cycles                        " << endl;
    cout << "   CheckBipartite                " << endl;
    cout << "   ColorGraph                    " << endl;
    cout << "   NodeReachability              " << endl;
    cout << "   ConnectedKosaraju             " << endl;
    return 0;
  }
  
  string filename = argv[1];
  string command = argv[2];
  int node = -1;
  if (command == "DFS" || command == "DFSPostOrder" ||
      command == "BFS" || command == "Prims" ||
      command == "Kruskals") {
    if (argc < 3) {
      cout << "Error: Please specify start node" << endl;
      return 0;
    } else {
      node = stoi(argv[3]);
    }
  }
  testGraphRun tgr(filename);
  if (command == "DFS") {
    tgr.runDFS(node);
    return 1;
  } else if (command == "DFSPostOrder") {
    tgr.runDFSPostOrder(node);
    return 1;
  } else if (command == "BFS") {
    tgr.runBFS(node);
    return 1;
  } else if (command == "Prims") {
    tgr.runPrims(node);
    return 1;
  } else if (command == "Kruskals") {
    tgr.runKruskals(node);
    return 1;
  } else if (command == "TopoSort") {
    tgr.runTopoSort();
    return 1;
  }

  if (command == "ShortestPath" && argc < 5) {
    cout << "Error: Please specify start and end nodes" << endl;
    int src = stoi(argv[3]);
    int dest = stoi(argv[4]);
    tgr.runShortestPath(src, dest);
  }
  
  return 1;
}
