# DeBruijn Graph and Eulerian Path

The purpose of this project is to construct the Debruijn graph given a set of sequences, and to determine the Eulerian path in said graph, if one exists.

DeBruijn graphs are common solution to de novo sequence assembly problems- where base-pair or amino acid sequences are assembled to reconstruct genomes or proteins.

## DeBruijn Graph Implementation

First, a random base-pair sequence of given length is generated, then divided into k-mers. Each k-mer has a left-side and right-side, as according to lecture. The sides of every k-mer are vertexes in the graph object, and edges are created to link each left-side to its corresponding right-side. Vertexes are stored as strings and edges are stored as pairs of strings. 

### Running the Code

The project is written in c++, and compiles using clang++. To build the object files and run the DrBruijn construction, execute `make && ./main`.
