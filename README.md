# DeBruijn Graph and Eulerian Path

The purpose of this project is to construct the Debruijn graph given a set of sequences, and to determine the Eulerian path in said graph, if one exists.

DeBruijn graphs are common solutions to de novo sequence assembly problems--where base-pair or amino acid sequences are assembled to reconstruct genomes or proteins.

## DeBruijn Graph

First, a given base-pair sequence is divided into k-mers. Each k-mer has a left-side and right-side, as according to lecture. The sides of every k-mer are vertexes in the graph object, and edges are created to link each left-side to its corresponding right-side. Vertexes are stored as strings in a set and edges are stored as pairs of strings in lists. We use a set to store the vertices so that no two nodes have the same value.

## Eulerian Walk

The Eulerian path of a graph is determined by the function `reconstructSequence()`. This function calls a recursive DFS helper function that follows Hierholzer's algorithm. The algorithm pursues a path as far as it can go, while removing traversed edges from an unexplored list. If the path isn't Eulerian, it backtracks to the last node with different branches.

### Running the Code

The project is written in c++, and compiles using clang++. To build the object files and run the DrBruijn construction, execute `make && ./main`.
