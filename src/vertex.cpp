#include "vertex.hpp"

//constructors and destructor
Vertex::Vertex() {
	traversalId = TRAVERSAL_INITIALIZER;
	E = vector<Edge*>();
}
Vertex::Vertex(int vN):vertexNumber(vN), traversalId(TRAVERSAL_INITIALIZER){
	E = vector<Edge*>();
}
Vertex::~Vertex() {
	for (Edge* e : this->E) {
		// if (e) delete e;
	}
}

// getters
int Vertex::getTraversalId() const{
	return traversalId;
}
int Vertex::getVertexNumber() const{
	return this->vertexNumber;
}
vector<Edge*> Vertex::getEdges() const{
	return this->E;
}
int Vertex::getNumOfEdges() const {
	return this->E.size();
}
Edge* Vertex::getEdge(int edgeIndex) const{
	assert(edgeIndex > -1);
	return this->E.at(edgeIndex);
}

//setters
int Vertex::incrementTraversalId() {
	return ++(this->traversalId);
}
bool Vertex::addEdge(Edge *e) {
	assert(e != NULL);

	try {
		this->E.push_back(e);
		return true;
	} catch (exception exp) {
		cout << "Failed to add new edge to a vertex" << endl; 
	}
	return false;
}
bool Vertex::deleteEdge(Edge *e) {
	assert(e != NULL);

	try {
		for (int i=0; i<this->E.size(); i++)
			if (*(this->E.at(i)) == *e) {
				this->E.erase(this->E.begin()+i);
				return true;
			}
	} catch (exception exp) {
		cout << "Failed to remove the edge from a vertex" << endl; 
	}
	return false;
}

// overloaded operators
bool operator==(const Vertex &v1, const Vertex &v2) {
	if (v1.vertexNumber == v2.vertexNumber && v1.getNumOfEdges() == v2.getNumOfEdges()) 
		return true;
	else 
		return false;
}

bool operator!=(const Vertex &v1, const Vertex &v2) {
	return !(v1 == v2);
}