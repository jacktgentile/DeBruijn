#include <iostream>
#include <string>

#include "utils.h"
#include "Graph.h"
#include "Edge.h"

using std::string;

int main() {
  const int K = 4;
  srand(time(NULL));

  string sequence = generate_bp_sequence(30);
  std::cout << sequence << std::endl;
  vector<string> kmers = generate_k_mers(sequence, K);
  std::random_shuffle(kmers.begin(), kmers.end());

  Graph g = Graph();
  for (string str : kmers) {
    string source = str.substr(0,K-1);
    string dest = str.substr(1);
    g.insertVertex(source);
    g.insertVertex(dest);
    g.insertEdge(source, dest);
  }
  std::cout << g.getSource() << std::endl << g.getSink() << std::endl;

  return 0;
}
