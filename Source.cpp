
#include "Problem.h"
#include "node.h"
#include "agent.h"
#include "frontier.h"
#include "exploredset.h"
#include "globals.h"
#include <fstream> 
#include <iostream>
using namespace std;


int main(int argc, char* argv[])
{   
	if(argc != ) {cout << "Unexpected number of arguments: cityFile, heuristicFile, start, end" << endl; return(1);}
	string filename, start, end, hfile;
	filename = argv[1];
	hfile = argv[2];
	start = argv [3];
	end = argv[4];
	Problem p;
	heuristic h;
	h.init(hfile);
	Problem* pptr = &p;
	pptr->init(filename);
	Agent a(pptr,h);
	a.search(start, end);
	return 0;
}
