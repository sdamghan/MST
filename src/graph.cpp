#include "graph.hpp"

//constructors and destructor
Graph::Graph(){
	V = vector<Vertex*>();
	E = vector<Edge*>(); 
}
Graph::Graph (int numOfVertexes, int numOfEdges) {
	this->V = vector<Vertex*>();
	for (int i=0; i<numOfVertexes; i++)
		this->V.push_back(new Vertex(i));
	this->E = vector<Edge*>(numOfEdges);
}
Graph::Graph(Graph &g) {
	V = vector<Vertex*> (g.V.size());
	for (Vertex* vertex : g.V)
		V.push_back(vertex);
	
	E = vector<Edge*> (g.E.size());
	for (Edge* edge : g.E)
		E.push_back(edge);
}
Graph::~Graph() {
	for (Vertex* v : this->V)
		delete v;
	for (Edge* e : this->E)
		delete e;
}

//getters
vector<Vertex*> Graph::getVertexes() const {
	return this->V;
}
int Graph::getNumOfVertexes() const {
	return this->V.size();
}
vector<Edge*> Graph::getEdges() const {
	return this->E;
}
int Graph::getNumOfEdges() const {
	return this->E.size();
}
bool Graph::haveAllVertexesBeenMet(int id) {
	for (Vertex* v : this->V)
		if (v->getTraversalId() != id)
			return false;
	return true;
}

//setters
bool Graph::addVertex(Vertex *v) {
	assert(v != NULL);

	try {
		V.push_back(v);
		return true;
	} catch (exception exp) {
		cout << "Failed to add vertex to a graph!" << endl;
	}
	return false;
}
Vertex* Graph::find(int vNum) {
	for (Vertex* v : this->V)
		if (v->getVertexNumber() == vNum)
			return v;
	return NULL;
}
void Graph::connect(int vN1, int vN2, double c) {
	Vertex* v1 = this->find(vN1);
	Vertex* v2 = this->find(vN2);

	assert(v1 != NULL);
	assert(v2 != NULL);
	assert(c >= 0);

	if (vN1 > vN2)
		swap(v1, v2);
		
	Edge* e = new Edge(v1, v2, c);
	v1->addEdge(e);
	v2->addEdge(e);
	this->E.push_back(e);
}
void Graph::connect(Vertex *v1, Vertex *v2, double c) {
	assert(v1 != NULL);
	assert(v2 != NULL);
	assert(c >= 0);

	if (v1->getVertexNumber() > v2->getVertexNumber())
		swap(v1, v2);
	
	Edge* e = new Edge(v1, v2, c);
	v1->addEdge(e);
	v2->addEdge(e);
	this->E.push_back(e);
}

// overloaded operators
ostream& operator<<(ostream& os, const Graph &g) {
	int vIndex = -1;
	for (Vertex* v : g.getVertexes()) {
		vIndex++;
		cout << "V(" << v->getVertexNumber() << "): ";
		for (Edge* e : g.getVertexes().at(vIndex)->getEdges()) {
			if(e->getV2()->getVertexNumber() != v->getVertexNumber())
				cout << "[" << e->getV2()->getVertexNumber() << "(" << e->getCost() << ")] ";
			else 
				cout << "[" << e->getV1()->getVertexNumber() << "(" << e->getCost() << ")] ";
		}	
		cout << endl;
	}
	
	return os;
}