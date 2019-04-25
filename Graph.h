#pragma once

#include <list>
#include <string>
#include <unordered_map>
#include <set>
#include <iostream>

#include "Edge.h"

using std::string;

class Graph {

  public:
    Graph();
    ~Graph();
    // Graph properties:
    unsigned int size() const;
    unsigned int edges() const;
    unsigned int degree_in(const string & v) const;
    unsigned int degree_out(const string & v) const;

    // Vertex modification:
    void insertVertex(const string & key);

    // Edge modification:
    void insertEdge(const string& source, const string& dest, unsigned int weight);
    void insertEdge(const Edge & e);

    void removeEdge(const string& source, const string& dest);
    void removeEdge(const Edge & e);

    // Graph structure:
    const std::list<Edge>& getIncomingEdges(const string & v) const;
    const std::list<Edge>& getOutgoingEdges(const string & v) const;

    bool edgeExists(const string& source, const string& dest) const;

  private:
    std::list<Edge> edgeList;
    std::set<string> vertexSet;
    std::unordered_map<string, std::list<Edge>> incomingEdges;
    std::unordered_map<string, std::list<Edge>> outgoingEdges;
};
