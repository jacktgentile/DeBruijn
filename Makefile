CC = clang++

CFLAGS = -c -Wall -std=c++11

main: main.o graph.o
			$(CC) main.o Graph.o -o main

main.o: main.cpp
			$(CC) $(CFLAGS) main.cpp

graph.o: Graph.cpp
			$(CC) $(CFLAGS) Graph.cpp

clean:
			rm main *.o
