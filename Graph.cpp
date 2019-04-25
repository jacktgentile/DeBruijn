#include "Graph.h"
#include "Edge.h"

#include <string>
#include <list>

using std::string;

Graph::Graph() {
   edgeList = std::list<Edge>();
   vertexSet = std::set<string>();
   incomingEdges = std::unordered_map<string, std::list<Edge>>();
   outgoingEdges = std::unordered_map<string, std::list<Edge>>();
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
  vertexSet.insert(v);
  incomingEdges[v] = std::list<Edge>();
  outgoingEdges[v] = std::list<Edge>();
}

/* Inserts the edge e. */
void Graph::insertEdge(const string& source, const string& dest, unsigned int weight) {
  Edge* temp = new Edge(source, dest, weight);
  insertEdge(*temp);
}

/* Inserts the edge e. */
void Graph::insertEdge(const Edge & e) {
  const string & source = e.source();
  const string & dest = e.dest();
  edgeList.push_back(e);
  incomingEdges[dest].push_back(e);
  outgoingEdges[source].push_back(e);
}

/* Remove edge with given source and destination */
void Graph::removeEdge(const string& source, const string& dest) {

}

/* Remove the given edge. */
void Graph::removeEdge(const Edge & e) {
  edgeList.remove(e);
  incomingEdges[e.dest()].remove(e);
  outgoingEdges[e.source()].remove(e);
}

/*  */
const std::list<Edge>& Graph::getIncomingEdges(const string & v) const {
  return incomingEdges.at(v);
}

/*  */
const std::list<Edge>& Graph::getOutgoingEdges(const string & v) const {
  return outgoingEdges.at(v);
}

/*  */
bool Graph::edgeExists(const string& source, const string& dest) const {
  const std::list<Edge>& outList = outgoingEdges.at(source);
  const std::list<Edge>& inList = incomingEdges.at(dest);
  if (outList.size() < inList.size()) {
    for (Edge e : outList) {
      if (e.dest() == dest) {
        return true;
      }
    }
    return false;
  } else {
    for (Edge e : inList) {
      if (e.source() == source) {
        return true;
      }
    }
    return false;
  }
}
