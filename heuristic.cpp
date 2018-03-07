#include "heuristic.h"

bool heuristic::init(std::string file)     
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

double heuristic::hdistance(std::string s){
     
     std::string string1; std::string string2; double distance; int max = cmap.size();
	 for(int i = 0; i < max; i++){
		cmap[i].getVals(string1,string2,distance); 
        if (s == string1 || s==string2)
        {   
            return distance;
        }
    }
}