#ifndef PQ_H
#define PQ_H
#include <iostream>
#include <string>
#include <vector>
#include <set>
#include "node.h"
#include "heuristic.h"
#include "globals.h"
using namespace std;
// forward declarations
class State;
class InsertCompare;

typedef std::multiset<Node*,InsertCompare> PriorityQueue; 

// we will order the queue based on State score.  The score is a crude
// estimate how far we are from the goal, so we sort from low to high
class InsertCompare {
public:
    std::string gMODE = "A";
    bool operator()(const Node* lhs, const Node* rhs) const {
        if ( gMODE == "G" || gMODE == "g") return lhs->hcost < rhs->hcost;
        else if (gMODE == "A" || gMODE == "a") return (lhs->hcost + lhs->pcost) < (rhs->hcost + rhs->pcost);
        else cout << "BAD MODE ARGUMENT" << endl;
        return false;}
};


class PQ {
public:
    PQ();
    ~PQ();
    bool isThisEmpty();
    void add(Node*);
    bool isInPQ(string);
    Node* pop();
    bool replace(Node*);
    void print() const;
private:
    PriorityQueue pq;
};




#endif