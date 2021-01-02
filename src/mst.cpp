#include "mst.hpp"

MST::MST() {
	closeSet = vector<Vertex*>();
	openSet = vector<Vertex*>();
	mst = vector<Edge*>();
	mstCost = 0.0;
}
MST::MST(Graph* g):g(g) {
	closeSet = vector<Vertex*>();
	openSet = vector<Vertex*>();
	for (Vertex* v : g->getVertexes())
		openSet.push_back(v);
	
	mst = vector<Edge*>();
	mstCost = 0.0;
}

//getters
vector<Vertex*> MST::getCloseSet() const {
	return this->closeSet;
}
vector<Vertex*> MST::getOpenSet() const {
	return this->openSet;
}
vector<Edge*> MST::getMst() const {
	return this->mst;
}
double MST::getMstCost() const {
	return this->mstCost;
}

//setters
void MST::addVertexToCloseSet(int vN) {
	assert(g != NULL);

	Vertex* v = this->g->find(vN);
	this->closeSet.push_back(v);
	this->openSet.erase(this->openSet.begin()+v->getVertexNumber());
}
void MST::addVertexToCloseSet(Vertex* v) {
	assert(v != NULL);
	this->closeSet.push_back(v);
}
void MST::removeVertexFromCloseSet (int vN) {
	assert(g != NULL);

	Vertex* v = this->g->find(vN);
	this->openSet.push_back(v);
	this->closeSet.erase(this->closeSet.begin()+v->getVertexNumber());
}

// minimum spanning tree functions
vector<Edge*> MST::find() {
	assert(g != NULL);
	vector<Edge*> edgePool = vector<Edge*>();

	Vertex* v = this->openSet.front();
	while (true) {

		this->closeSet.push_back(v);
		v->incrementTraversalId();

		if (g->haveAllVertexesBeenMet(FIRST_TRAVERSAL))
			break;

		for (Edge* e : v->getEdges())
			if ((e->getTraversalId() != FIRST_TRAVERSAL) && (std::find(edgePool.begin(), edgePool.end(), e) == edgePool.end())) 
				edgePool.push_back(e);

		sort(edgePool.begin(), edgePool.end(), comparator);
		
		Edge* e;
		while(true) {
			e = edgePool.front();
			edgePool.erase(edgePool.begin());
			if ((e->getTraversalId() == FIRST_TRAVERSAL) || (e->getV1()->getTraversalId() == e->getV2()->getTraversalId() == FIRST_TRAVERSAL)) 
				continue;
			else 
				break;
		}

		this->mst.push_back(e);
		this->mstCost += e->getCost();
		e->incrementTraversalId();

		if (v != e->getV1() && v != e->getV2()) {
			if (e->getV1()->getTraversalId() == FIRST_TRAVERSAL) 
				v = e->getV2();
			else if (e->getV2()->getTraversalId() == FIRST_TRAVERSAL)
				v = e->getV1();
		}
		else 
			v = (v == e->getV1())? e->getV2() : e->getV1();
	}

	return mst;
}

ostream& operator<<(ostream& os, MST& m) {
	if (m.mst.empty()){
		cout << "Minimum Spanning Tree has not been found yet, please use find() method!" << endl;
	} else {
		cout << "Minimum Spanning Tree Path:" << endl;
		for (Edge* e : m.mst) {
			cout << "(" << e->getV1()->getVertexNumber() << ")-[" << std::fixed << std::setprecision(2) << e->getCost() << "]-(" << e->getV2()->getVertexNumber() << ")" << endl;
		}
		cout << endl << "Total cost is: " << std::fixed << std::setprecision(2) << m.getMstCost() << endl;
	}
	return os;
}