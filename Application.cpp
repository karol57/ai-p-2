#include "Application.hpp"
#include <iostream>

// f(x)=a ln (x + 3) + b sin x^2 - ctg x
// x E <0, 255>
// liczba osobników 20
// pn, pk

int startApplication(const Options& o)
{
    std::cout << "=== Starting simulation ===" << std::endl;
    std::cout << "p_m: " << o.mutationProb << std::endl;
    std::cout << "p_c: " << o.crossOverProb << std::endl;
    std::cout << "Population: " << o.population << std::endl;

    return 0;
}
