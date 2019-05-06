#include <iostream>
#include <string>

#include "utils.h"
#include "Graph.h"

using std::string;


int main() {
  const int K = 3;
  srand(time(NULL));

  string sequence = generate_bp_sequence(5);
  std::cout << sequence << std::endl;
  vector<string> kmers = generate_k_mers(sequence, K);
  std::random_shuffle(kmers.begin(), kmers.end());

  // Build DeBruijn graph g
  Graph g = Graph();
  for (string str : kmers) {
    string source = str.substr(0,K-1);
    string dest = str.substr(1);
    g.insertVertex(source);
    g.insertVertex(dest);
    edge_t e(source, dest);
    g.insertEdge(e);
  }

  std::cout << g.toString() << std::endl;
  return 0;
}
