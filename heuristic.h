#include "Problem.h"
//This is used for informed searching
class heuristic{
public:

    bool init(std::string);

    double hdistance(std::string);

    private:
    CityLinks cmap;
};
