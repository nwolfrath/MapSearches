#ifndef EXPLOREDSET_H
#define EXPLOREDSET_H

#include "node.h"
#include <vector>

typedef std::vector<Node*> NodeVector;

class ExploredSet {
public:
    //ExploredSet();
    //~ExploredSet();
	bool check(Node* n)
	{
		int max = exset.size(); for (int i = 0; i < max; i++) { if (n->getName() == exset[i]->getName()) { return true; } }
		return false;
		}
    void add(Node* n)
	{exset.push_back(n);}
    void print() const
	{std::cout << "explored set:" << std::endl; int max = exset.size(); for (int i = 0; i < max; i++) {exset[i]->print();}}
private:
    NodeVector exset;
};

#endif
