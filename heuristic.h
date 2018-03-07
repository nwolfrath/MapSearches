#include "Problem.h"

class heuristic{
public:

    bool init(std::string);

    double hdistance(std::string);

    private:
    CityLinks cmap;
};