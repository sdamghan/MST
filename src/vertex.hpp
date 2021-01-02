#ifndef VERTEXHPP__
#define VERTEXHPP__

#include "edge.hpp"
#include <assert.h>
#include <iostream>
#include <vector>
using namespace std;

const static int TRAVERSAL_INITIALIZER = 0;
const static int FIRST_TRAVERSAL = 1;

class Edge;

class Vertex {

	friend bool operator==(const Vertex &v1, const Vertex &v2);

	private:
		int traversalId;
		int vertexNumber;
		vector<Edge*> E;

	public:
		Vertex();
		Vertex(int vN);
		~Vertex();

		// getters
		int getTraversalId() const;
		int getVertexNumber() const;
		vector<Edge*> getEdges() const;
		int getNumOfEdges() const;
		Edge* getEdge(int edgeIndex) const;
	
		//setters
		int incrementTraversalId();
		bool addEdge(Edge *e);
		bool deleteEdge(Edge *e);
};

bool operator==(const Vertex &v1, const Vertex &v2);
bool operator!=(const Vertex &v1, const Vertex &v2);

#endif // VERTEXHPP__