#include "Application.hpp"
#include "Chromosome.hpp"
#include "Function.hpp"
#include <random>
#include <iostream>
#include <vector>

// f(x)=a ln (x + 3) + b sin x^2 - ctg x
// x E <0, 255>
// liczba osobników 20
// pn, pk

int startApplication(const Options& o)
{
    Function func{ o.a, o.b, o.c, o.d, o.e };
    std::cout << "=== Starting simulation ===" << std::endl;
    std::cout << func << std::endl;
    std::cout << "p_m: " << o.mutationProb << std::endl;
    std::cout << "p_c: " << o.crossOverProb << std::endl;
    std::cout << "Population: " << o.population << std::endl;

    std::mt19937_64 rng{ std::random_device()() };

    std::vector<Chromosome> individuals;
    for (size_t i = 0u; i < o.population; ++i)
    {
        individuals.push_back(rng);
        std::cout << "Individual " << i << ": " << individuals.back()
                  << " phenotype " << static_cast<unsigned>(individuals.back().value())
                  << " fitness " << func(individuals.back().value()) <<  std::endl;
    }

    return 0;
}
