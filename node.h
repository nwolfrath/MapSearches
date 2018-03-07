#ifndef NODE_H
#define NODE_H

#include "globals.h"
#include <iostream>
#include <string>
#include <stack>

class Node {
public:
    //Node();
    Node(Node*, std::string, double, double);
    std::string getName() const;
	bool operator<(const Node&);
	void print() const;
	void traceBack();

    double ucost;	// unit cost:  distance to parent
    double pcost;	// total path cost: distance to root
    double hcost;   // heuristic cost
private:
    Node* parent;
    std::string name;   

};

#endif
