#include <iostream>
#include <string>

#include "utils.h"
#include "Graph.h"

using std::string;


int main() {
  const int K = 4;
  srand(time(NULL));

  string sequence = generate_bp_sequence(16);
  std::cout << sequence << std::endl;
  vector<string> kmers = generate_k_mers(sequence, K);
  // std::random_shuffle(kmers.begin(), kmers.end());

  Graph g = Graph();
  for (string str : kmers) {
    string source = str.substr(0,K-1);
    string dest = str.substr(1);
    g.insertVertex(source);
    g.insertVertex(dest);
    edge_t e(source, dest);
    g.insertEdge(e);
  }
  // std::cout << g.getSource() << std::endl << g.getSink() << std::endl << std::endl;
  std::cout << g.toString() << std::endl;
  // std::cout << g.edgeList.size() << std::endl;
  // for (Edge e : g.edgeList) {
  //   std::cout << e.source() << "\n";
  // }
  return 0;
}
