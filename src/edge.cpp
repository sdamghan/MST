#include "edge.hpp"

//constructors and destructors
Edge::Edge() {}
Edge::Edge(Vertex* v1, Vertex* v2, double c): v1(v1), v2(v2), cost(c), traversalId(TRAVERSAL_INITIALIZER) {}
Edge::~Edge() {
	// delete v1;
	// delete v2;
}

//getters
int Edge::getTraversalId() const{
	return traversalId;
}
double Edge::getCost() const {
	return this->cost;
}
Vertex* Edge::getV1() const {
	return this->v1;
}
Vertex* Edge::getV2() const {
	return this->v2;
}		

//setters
int Edge::incrementTraversalId() {
	return ++(this->traversalId);
}
void Edge::setCost (double c) {
	assert(c >= 0);
	this->cost = c;
}
void Edge::setV1 (Vertex* v) {
	assert(v != NULL);
	this->v1 = v;
}
void Edge::setV2 (Vertex* v) {
	assert(v != NULL);
	this->v2 = v;
}

// overloading operators
bool operator==(const Edge &e1, const Edge &e2) {
	assert((e1.getV1() != NULL) && (e1.getV2() != NULL));
	assert((e2.getV1() != NULL) && (e2.getV2() != NULL));

	return ( ( (e1.getV1() == e2.getV1()) && (e1.getV2() == e2.getV2()) ) || 
		     ( (e1.getV1() == e2.getV2()) && (e1.getV2() == e2.getV1()) ) ) 
		   && (e1.getCost() == e2.getCost());
}

bool operator!=(const Edge &e1, const Edge &e2) {
	return !(e1 == e2);
}

bool operator>(const Edge &e1, const Edge &e2) {
	return (e1.getCost() > e2.getCost());
}
bool operator<(const Edge &e1, const Edge &e2) {
	return (e1.getCost() < e2.getCost());
}
bool comparator(const Edge *e1, const Edge *e2) {
	return (e1->getCost() < e2->getCost());
}