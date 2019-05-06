#include "Graph.h"
#include <queue>

using std::string;

Graph::Graph() {
   edgeList = std::list<edge_t>();
   vertexSet = std::set<string>();
   incomingEdges = std::unordered_map<string, std::list<edge_t>>();
   outgoingEdges = std::unordered_map<string, std::list<edge_t>>();
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
  std::pair<std::set<string>::iterator, bool> p = vertexSet.insert(v);
  if (p.second) {
    incomingEdges[v] = std::list<edge_t>();
    outgoingEdges[v] = std::list<edge_t>();
  }
}

/* Inserts the edge e. */
void Graph::insertEdge(edge_t e) {
  edgeList.push_back(e);
  incomingEdges[e.second].push_back(e);
  outgoingEdges[e.first].push_back(e);
}

/* Remove the given edge. */
void Graph::removeEdge(edge_t e) {
  edgeList.remove(e);
  incomingEdges[e.second].remove(e);
  outgoingEdges[e.first].remove(e);
}


std::list<edge_t> Graph::getIncomingEdges(const string & v) const {
  return incomingEdges.at(v);
}


std::list<edge_t> Graph::getOutgoingEdges(const string & v) const {
  return outgoingEdges.at(v);
}


bool Graph::edgeExists(const string& source, const string& dest) const {
  const std::list<edge_t>& outList = outgoingEdges.at(source);
  const std::list<edge_t>& inList = incomingEdges.at(dest);
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


string Graph::getSink() const {
  for (string v : vertexSet) {
    if (degree_in(v) > degree_out(v)) {
      return v;
    }
  }
  return "";
}


string Graph::getSource() const {
  for (string v : vertexSet) {
    if (degree_in(v) < degree_out(v)) {
      return v;
    }
  }
  return "";
}


string Graph::toString() const {
  string result;
  std::queue<string> frontier;
  std::unordered_map<string, bool> visited;
  for (string v : vertexSet) {
    visited[v] = false;
  }
  string v = getSource();
  if (v == "") {
    v = *vertexSet.begin();
  }
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
