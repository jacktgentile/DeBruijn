#include "Graph.h"

#include <queue>

using std::queue;


Graph::Graph(vector<string>& kmers) {
  unsigned int K = kmers[0].size();
    edgeList = list<edge_t>();
    vertexSet = set<string>();
    incomingEdges = unordered_map<string, list<edge_t>>();
    outgoingEdges = unordered_map<string, list<edge_t>>();
    for (string kmer : kmers) {
      string src = kmer.substr(0,K-1);
      string dest = kmer.substr(1);
      insertVertex(src);
      insertVertex(dest);
      edge_t edge = edge_t(src, dest);
      insertEdge(edge);
    }
}

Graph::~Graph() {
  edgeList.clear();
  vertexSet.clear();
  incomingEdges.clear();
  outgoingEdges.clear();
}

/* Returns the number of unique vertices in the graph. */
unsigned int Graph::size() const {
  return vertexSet.size();
}

/* Returns the number of edges in the graph. */
unsigned int Graph::edges() const {
  return edgeList.size();
}

/* Returns the number of incoming edges at the vertex v. */
unsigned int Graph::degree_in(const string & v) const {
  return incomingEdges.at(v).size();
}

/* Returns the number of outgoing edges at the vertex v. */
unsigned int Graph::degree_out(const string & v) const {
  return outgoingEdges.at(v).size();
}

/* Inserts the vertex v to the graph (if v isn't already present),
   with no incoming or outgoing edges. */
void Graph::insertVertex(const string & v) {
  std::pair<set<string>::iterator, bool> p = vertexSet.insert(v);
  if (p.second) {
    incomingEdges[v] = list<edge_t>();
    outgoingEdges[v] = list<edge_t>();
  }
}

/* Inserts the edge e. */
void Graph::insertEdge(edge_t& e) {
  edgeList.push_back(e);
  incomingEdges[e.second].push_back(e);
  outgoingEdges[e.first].push_back(e);
}

/* Erases target from paramList if present. If a value is erased, return true. */
bool Graph::remove_if_contains(list<edge_t>& paramList, edge_t& target){
  for (list<edge_t>::iterator it = paramList.begin(); it != paramList.end(); it++) {
    if (*it == target) {
      paramList.erase(it);
      return true;
    }
  }
  return false;
}

/* Returns true if the graph contains an edge from source to dest, false otherwise. */
bool Graph::edgeExists(const string& source, const string& dest) const {
  const list<edge_t>& outList = outgoingEdges.at(source);
  const list<edge_t>& inList = incomingEdges.at(dest);
  if (outList.size() < inList.size()) {
    for (edge_t e : outList) {
      if (e.second == dest) {
        return true;
      }
    }
  } else {
    for (edge_t e : inList) {
      if (e.first == source) {
        return true;
      }
    }
  }
  return false;
}

/* Returns the vertex with 1 more incoming edge than it has outgoing edges.
   If there is no distinct sink, return the first element of vertexSet. */
string Graph::getSink() const {
  for (string v : vertexSet) {
    if (degree_in(v) > degree_out(v)) {
      return v;
    }
  }
  return *vertexSet.begin();
}

/* Returns the vertex with 1 fewer incoming edge than it has outgoing edges.
   If there is no distinct source, return the first element of vertexSet. */
string Graph::getSource() const {
  for (string v : vertexSet) {
    if (degree_in(v) < degree_out(v)) {
      return v;
    }
  }
  return *vertexSet.begin();
}

/* Returns the sequence reconstructed by walking the Eulerian path. */
string Graph::reconstructSequence() {
    // deep copy edgeList
    list<edge_t> edgeListCopy = list<edge_t>();
    for (edge_t e : edgeList) {
      edgeListCopy.push_back(e);
    }
    string source = getSource();
    string sink = getSink();
    // path initially just constains the source node
    vector<string> path = vector<string>();
    path.push_back(source);

    reconstructHelper(path, edgeListCopy, source, sink);

    // output sequence from path
    unsigned k_minus_one = source.size();
    string result = path[0].substr(0,k_minus_one-1);
    for (string v : path) {
      result += v[k_minus_one-1];
    }
    return result;
}

/* Recursive function that determines the Eulerian walk using DFS / Hierholzer algorithm.
   Return true if a Eulerian path exists with path as a prefix, false otherwise.
   path is a reference to the vector of nodes visited so far,
   remaining is the list of edges not yet taken in path,
   source is the source node of the graph,
   sink is the sink node of the graph. */
bool Graph::reconstructHelper(vector<string>& path, list<edge_t>& remaining, string& source, string& sink) {
    // base case: path is Eulerian
    if (path.size() == edgeList.size() + 1 && path[0] == source && path[path.size()-1] == sink) {
      return true;
    }
    // arbitrarily choose an edge not yet taken, explore that new path
    string cur_vertex = path[path.size()-1];
    for (edge_t e : outgoingEdges[cur_vertex]) {
      if (remove_if_contains(remaining, e)) {
        path.push_back(e.second);
        if (reconstructHelper(path, remaining, source, sink)) {
          return true;
        }
        path.pop_back();                    // undo line 155
        remaining.push_back(e);             // undo line 154
      }
    }
    // if none of those edges worked, the path is not correct
    return false;
}

/* Return string that depicts the structure of the graph. Useful for debugging. */
string Graph::toString() const {
  string result;
  queue<string> frontier;
  unordered_map<string, bool> visited;
  for (string v : vertexSet) {
    visited[v] = false;
  }
  string v = getSource();
  frontier.push(v);
  while (!frontier.empty()) {
    v = frontier.front();
    frontier.pop();
    if (!visited[v]) {
      visited[v] = true;
      result.append(v);
      result.append("\n");
      for (edge_t e : outgoingEdges.at(v)) {
        result.append("-->");
        result.append(e.second);
        result.append("\n");
        frontier.push(e.second);
      }
    }
  }
  return result;
}
