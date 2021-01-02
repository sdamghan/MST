#include "graph.hpp"
#include "mst.hpp"

int main (int argc, char ** argv) {

	cout << "\n\nWelcome to the C++ for C programmers course on Coursera\n" << endl;

	Graph g(6, 2);
	g.connect(0, 1, 2.25);
	g.connect(0, 2, 21.3);
	g.connect(1, 2, 14.53);
	g.connect(4, 3, 1.64);
	g.connect(4, 0, 5.64);
	g.connect(5, 3, 3.11);
	g.connect(5, 4, 3.29);
	
	
	cout << g << endl << endl;

	MST mst(&g);
	mst.find();

	cout << mst << endl;

	return 0;
}