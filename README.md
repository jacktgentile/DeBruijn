# DeBruijn Graph and Eulerian Path

The purpose of this project is to construct the De Bruijn graph given a sequence and K-value, and to determine the Eulerian path in said graph, if one exists.

DeBruijn graphs are common solutions to de novo sequence assembly problems--where base-pair or amino acid sequences are assembled to reconstruct genomes or proteins.

## De Bruijn Graph

First, a given base-pair sequence is divided into k-mers. Each k-mer has a left-side and right-side, as according to lecture. The sides of every k-mer are vertexes in the graph object, and edges are created to link each left-side to its corresponding right-side. Vertexes are stored as strings in a set and edges are stored as pairs of strings in lists. We use a set to store the vertices so that no two nodes have the same value.

## Eulerian Walk

The Eulerian path of a graph is determined by the function `reconstructSequence()`. This function calls a recursive DFS helper function that follows Hierholzer's algorithm. The algorithm pursues a path as far as it can go, while removing traversed edges from an unexplored list. If the path isn't Eulerian (i.e. doesn't contain all edges), it backtracks to the last node with multiple branches.

### Running the Code

The project is written in c++, and compiles using clang++. To build the object files and run the De Bruijn construction, execute `make && ./main`.

The user is then prompted to enter an original sequence, followed by a K-value greater than 2. Input is not checked for correctness. It is assumed the user follows the prompts. The program then constructs a De Bruijn graph, with the K-mers in a random order. Finally, it prints the reconstructed sequence.
