#ifndef PROBLEM_H
#define PROBLEM_H

#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>

struct Neighbor {
    std::string name;
    double dist;
};

typedef std::vector<Neighbor> CityList;


/* this maintains a list of city pairs with the distance between them.  The pairs can be in either order.   There is no sanity checking for duplicates of the form "a b N" and "b a N".   It is a helper class for this type of problem.
 */
class CityLink {
public:
    CityLink(std::string ,std::string ,double);
    //bool operator==(const CityLink&) const;
    void getVals(std::string& ,std::string& ,double& ) const;
    void print() const;
private:
    std::string a;
    std::string b;
    double cost;
};

typedef std::vector<CityLink> CityLinks;

class Problem {
public:
    //Problem();
    bool init(std::string);
    void insert(CityLink);
    CityList findNeighbors(std::string); //expand()
	
	void print() const;
private:
    CityLinks cmap;
};

#endif
