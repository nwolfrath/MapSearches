#ifndef AGENT_H
#define AGENT_H
#include "frontier.h"
#include "exploredset.h"
#include "Problem.h"


class Agent {
public:
    //Agent();
    Agent(Problem* , heuristic);
	
	Node* search(std::string,std::string);
    
	void printExploredSet() const
	{this->exset.print();}
	
    void printFrontier() const
	{this->f.print();}
private:
    ExploredSet exset;
    Frontier f;
    Problem* m;
	heuristic h;
};

#endif
