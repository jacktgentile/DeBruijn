#pragma once

#include <list>               //std::list
#include <utility>            //std::pair
#include <string>             //std::string
#include <unordered_map>      //std::unordered_map
#include <set>                //std::set
#include <vector>             //std::vector

using std::string;
using std::vector;
using std::list;
using std::unordered_map;
using std::set;

typedef std::pair<string, string> edge_t;


class Graph {

  public:
    Graph(vector<string>& kmers);
    ~Graph();

    unsigned int size() const;
    unsigned int edges() const;
    unsigned int degree_in(const string & v) const;
    unsigned int degree_out(const string & v) const;

    bool edgeExists(const string& source, const string& dest) const;

    string getSource() const;
    string getSink() const;

    string reconstructSequence();

    string toString() const;

  private:
    list<edge_t> edgeList;
    set<string> vertexSet;
    unordered_map<string, list<edge_t>> incomingEdges;
    unordered_map<string, list<edge_t>> outgoingEdges;

    vector<string> generate_k_mers(const string & sequence, unsigned int k);

    void insertVertex(const string & key);
    void insertEdge(edge_t& e);

    bool reconstructHelper(vector<string>& path, list<edge_t>& remaining, string& source, string& sink);
    bool remove_if_contains(list<edge_t>& paramList, edge_t& target);
};
