#include "node.h"

Node::Node(Node* p,std::string nm,double cost,double hcst)
	{
    this->parent = p; this->hcost = hcst; this->name = nm; this->ucost = cost; 
    if(p == NULL) this->pcost = 0;
    else this ->pcost = (cost + (p->pcost));
		}
    std::string Node::getName() const{return this->name;}

    
	void Node::print() const
	{std::cout << "Location:    " << name << "   total cost: " << pcost << " " << "\n";}
    
	void Node::traceBack()
    {Node* p = parent; std::stack<Node*> mystack; while(p != NULL)
    
        {   //we want to print in the right order
            
            mystack.push(p);
            p = p->parent;
        }
        while(!mystack.empty()){

            mystack.top()->print();
            mystack.pop();
        }
        this -> print();
    
    }