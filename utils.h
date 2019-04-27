#include <string>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <vector>

using std::string;
using std::vector;

unsigned int best_overlap(const string & source, const string & dest) {
  unsigned int common_len = source.size() < dest.size() ? source.size() : dest.size();
  for (; common_len > 0; common_len--) {
    bool diff_flag = false;
    unsigned int src_offset = source.size() - common_len;
    for (unsigned int i = 0; i < common_len; i++) {
      if (source[src_offset + i] != dest[i]) {
        diff_flag = true;
        break;
      }
    }
    if (!diff_flag) {
      return common_len;
    }
  }
  return 0;
}

string generate_bp_sequence(unsigned int L) {
  char alphabet[4];
  alphabet[0] = 'A';
  alphabet[1] = 'G';
  alphabet[2] = 'T';
  alphabet[3] = 'C';
  string sequence = "";
  for (int i = 0; i < L; i++) {
    (sequence) += alphabet[rand() % 4];
  }
  return sequence;
}

vector<string> generate_k_mers(const string & sequence, unsigned int k) {
  vector<string> kmers = vector<string>();
  for (int i = 0; i <= sequence.size() - k; i++) {
    kmers.push_back(sequence.substr(i, k));
  }
  return kmers;
}
