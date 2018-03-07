#ifndef FRONTIER_H
#define FRONTIER_H

#include "PQ.h"
#include "node.h"
#include <deque>


//Not using this anymore, can be used for different search types
enum FrontierType { LIFO, FIFO };

typedef std::deque<Node*> FrontierList;

class Frontier {
public:
	//Frontier();
	//~Frontier()
	//Priority Queue destrutor will handle this    
	void add(Node*);
	bool check(Node*);
	bool isEmpty();
	Node* next();
	void replaceNode(Node* n);
    void print() const;


private:
    
    PQ fnodes;
};

#endif
