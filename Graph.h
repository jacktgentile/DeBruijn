#pragma once


#include <list>
#include <utility>
#include <string>
#include <unordered_map>
#include <set>
#include <vector>
#include <iostream>

using std::string;

typedef std::pair<string, string> edge_t;



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
    void insertEdge(edge_t e);

    void removeEdge(edge_t e);

    // Graph structure:
    std::list<edge_t> getIncomingEdges(const string & v) const;
    std::list<edge_t> getOutgoingEdges(const string & v) const;

    bool edgeExists(const string& source, const string& dest) const;

    string getSource() const;
    string getSink() const;

    string reconstructSequence();
    bool reconstructHelper(std::vector<string>& path, std::list<edge_t>& remaining, string& source, string& sink);
    bool remove_if_contains(std::list<edge_t>& paramList, edge_t target);

    string toString() const;

    std::list<edge_t> edgeList;
    std::set<string> vertexSet;
    std::unordered_map<string, std::list<edge_t>> incomingEdges;
    std::unordered_map<string, std::list<edge_t>> outgoingEdges;
};
