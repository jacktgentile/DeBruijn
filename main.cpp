#include <iostream>
#include <string>
#include <algorithm>

#include "Graph.h"

using std::cout;
using std::cin;


int main() {

  srand(time(NULL));
  cout << "\nType the original sequence, then press \'Enter\':    ";
  string sequence;
  cin >> sequence;
  cout << "Give a K value greater than 2, then press \'Enter\': ";
  unsigned int K;
  cin >> K;

  vector<string> kmers = vector<string>();
  for (int i = 0; i <= sequence.size() - K; i++) {
    kmers.push_back(sequence.substr(i, K));
  }
  std::random_shuffle(kmers.begin(), kmers.end());

  Graph g = Graph(kmers);
  cout << "\nOriginal sequence:\n" << sequence;
  cout << "\nReconstructed sequence:\n" << g.reconstructSequence() << "\n\n";

  return 0;
}
