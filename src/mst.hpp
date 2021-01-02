#ifndef MSTHPP__
#define MSTHPP__

#include "graph.hpp"
#include <iomanip>

class Graph;
class Vertex;
class Edge;

class MST {

	friend ostream& operator<<(ostream& os, MST& mst);
	private:
		Graph* g;
		vector<Vertex*> closeSet;
		vector<Vertex*> openSet;
		vector<Edge*> mst;
		double mstCost;

	public:
		MST();
		MST(Graph* g);

		//getters
		vector<Vertex*> getCloseSet() const;
		vector<Vertex*> getOpenSet() const;
		vector<Edge*> getMst() const;
		double getMstCost() const;

		//setters
		void addVertexToCloseSet(int vN);
		void addVertexToCloseSet(Vertex* v);
		void removeVertexFromCloseSet(int vN);

		// minimum spanning tree functions
		vector<Edge*> find();
};

ostream& operator<<(ostream& os, MST& mst);

#endif // MSTHPP__