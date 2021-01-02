#ifndef EDGEHPP__
#define EDGEHPP__

#include "vertex.hpp"

class Vertex;

class Edge {

	friend bool operator==(const Edge &e1, const Edge &e2);
	friend bool operator>(const Edge &e1, const Edge &e2);
	friend bool operator<(const Edge &e1, const Edge &e2);
	friend bool comparator(const Edge *e1, const Edge *e2);

	private:
		int traversalId;
		Vertex* v1;
		Vertex* v2;
		double cost;

	public:
		Edge();
		Edge(Vertex* v1, Vertex* v2, double c);
		~Edge();

		//getters
		int getTraversalId() const;
		double getCost() const;
		Vertex* getV1() const;
		Vertex* getV2() const;		

		//setters
		int incrementTraversalId();
		void setCost (double c);
		void setV1 (Vertex* v);
		void setV2 (Vertex* v);
		
	
};

// overloading operators
bool operator==(const Edge &e1, const Edge &e2);
bool operator!=(const Edge &e1, const Edge &e2);
bool operator>(const Edge &e1, const Edge &e2);
bool operator<(const Edge &e1, const Edge &e2);
bool comparator(const Edge *e1, const Edge *e2);

#endif // EDGEHPP__