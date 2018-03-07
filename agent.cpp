#include "agent.h"

Agent::Agent(Problem* prob, heuristic heu)
	{this -> m = prob; this -> h = heu;} 

Node* Agent::search(std::string start,std::string end){
		
		Node root(NULL, start, 0, 0);
		f.add(&root);
        if (root.getName() == end) return &root;
		int i = 0;
		do{
			i++;
            if (f.isEmpty()) break;
			Node* next = f.next();
			if (next->getName() == end) {next->traceBack(); break;}
			exset.add(next);
			CityList neighbors = m->findNeighbors(next->getName());
			for (int i = 0; i < neighbors.size(); i++){
				Node* newNode = new Node(next, neighbors[i].name, neighbors[i].dist, h.hdistance(neighbors[i].name));
				if ((!exset.check(newNode))){
					f.add(newNode);
				}
			}

        }while(1) ; //WE WILL FIND THE WAY (not production code)
		return NULL;
    }