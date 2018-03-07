#include "Problem.h"

    CityLink::CityLink(std::string x,std::string y,double len){
        this->a = x; this->b = y; this->cost = len;
        }

    //bool operator==(const CityLink&) const;
    
    void CityLink::getVals(std::string& x,std::string& y,double& len) const{
        x = this -> a; y = this-> b; len = this->cost;
        }
   
    void CityLink::print() const{
        std::cout << a << " " << b << " " << cost << std::endl;
        }


    bool Problem::init(std::string file)     
       {   
            std::string line;
            std::string c1, c2;
            double dist;
            std::ifstream fin(file.c_str());
            while(std::getline(fin,line)){
                if (line[0] != '#')
                { std::stringstream ss(line);
                ss >> c1 >> c2 >> dist;
                CityLink cl(c1,c2,dist);
                cmap.push_back(cl);
            }
				
			}return true;
        }
    void Problem::insert(CityLink cl)
	    {cmap.push_back(cl);}

    CityList Problem::findNeighbors(std::string loc) // expand()
	{CityList returnList; std::string string1; std::string string2; double distance; int max = cmap.size();
	 for(int i = 0; i < max; i++){
		cmap[i].getVals(string1,string2,distance); 
		Neighbor newNeighbor;
		if (string1 == loc) 
			{newNeighbor.name = string2; newNeighbor.dist = distance; returnList.push_back(newNeighbor);}
		else if (string2 == loc)
			{newNeighbor.name = string1; newNeighbor.dist = distance; returnList.push_back(newNeighbor);}
		}
	return returnList;
	}  
   
	
	void Problem::print() const
	{int max = cmap.size(); for(int i = 0; i < max; i++) {cmap[i].print();}}