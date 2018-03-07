#include "frontier.h"

void Frontier::add(Node* newNode){
	fnodes.add(newNode);
	}

bool Frontier::check(Node* n){
		fnodes.isInPQ(n->getName());
	}
    
bool Frontier::isEmpty(){
    return fnodes.isThisEmpty();
    }

Node* Frontier::next(){ 
	 return fnodes.pop();
	}

void Frontier::replaceNode(Node* n){
		fnodes.replace(n);
	}

void Frontier::print() const{
    std::cout << "frontier: " << std::endl; fnodes.print();
    }
