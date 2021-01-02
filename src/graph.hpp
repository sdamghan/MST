#ifndef GRAPHHPP__
#define GRAPHHPP__

#include "vertex.hpp"
#include "edge.hpp"

class Graph {

	friend ostream& operator<<(ostream& os, const Graph &g);

	private:
		vector<Vertex*> V;
		vector<Edge*> E;

	public:
		Graph();
		Graph (int numOfVertexes, int numOfEdges);
		Graph(Graph &g);
		~Graph();

		//getters
		vector<Vertex*> getVertexes() const;
		int getNumOfVertexes() const;
		vector<Edge*> getEdges() const;
		int getNumOfEdges() const;
		bool haveAllVertexesBeenMet(int id);

		//setters
		bool addVertex (Vertex *v);
		Vertex* find(int vIndex);
		void connect(int vN1, int vN2, double c);
		void connect (Vertex *v1, Vertex *v2, double c);
};

// overloaded operators
ostream& operator<<(ostream& os, const Graph &g);
#endif // GRAPHHPP__