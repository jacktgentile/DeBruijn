#pragma once

#include <string>
#include <iostream>

using std::string;

class Edge {

  public:
    Edge(const string & source, const string & dest, unsigned int weight) :
      source_(source), dest_(dest), weight_(weight) { }
    ~Edge() { }

    /**
     * Returns the source Vertex of the Edge.
     */
    const string & source() const { return source_; }

    /**
     * Returns the destination Vertex of the Edge.
     */
    const string & dest() const { return dest_; }

    /**
     * Returns the weight of the Edge.
     */
    unsigned int weight() const { return weight_; }

    bool operator==(const Edge & other) const {
      return this == &other;
    }

  private:
    const string & source_;
    const string & dest_;
    unsigned int weight_;
};
