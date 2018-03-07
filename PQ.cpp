#include "PQ.h"

PQ::PQ() {}

// delete memory for nodes remaining in priority queue
PQ::~PQ() { 
    int i = 0;
    PriorityQueue::iterator pqi;
    for (pqi=pq.begin();pqi!=pq.end();pqi++) {
        delete *pqi;
    }
}

void 
PQ::add(Node* n) {
    pq.insert(n);
}

//When insterting a new node, we need to check if its already in the frontier
//and keep the one with lower cost
bool 
PQ::replace(Node* n) {
    PriorityQueue::iterator pqi;
    for (pqi = pq.begin(); pqi != pq.end(); pqi++) {
        if (((*pqi)->getName() == n->getName()) && ((*pqi)->ucost > n->ucost))
        {
            pq.erase(pqi);
            pq.insert(n);

        }
        return true;
    }
    return false;
}

//check()
bool
PQ::isInPQ(string s) {
    PriorityQueue::iterator pqi;
    for(pqi = pq.begin(); pqi != pq.end(); pqi++){
        if ((*pqi)->getName() == s) return true;
    }
    return false;
}

bool PQ::isThisEmpty(){
    return pq.empty();
}

Node*
PQ::pop() {
    Node* ret = NULL;
    if (!pq.empty()) {
        ret = *pq.begin();
        pq.erase(pq.begin());
    }
    return ret;
}

void PQ::print() const{
    std::cout << "PQ: ";
    //didn't need to debug with this
}