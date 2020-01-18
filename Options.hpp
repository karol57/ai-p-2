#pragma once
#include <cstdlib>

struct Options
{
    std::size_t population;
    double mutationProb;
    double crossOverProb;
    double a, b, c, d, e;
};
