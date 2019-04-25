#include <string>

using std::string;

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
