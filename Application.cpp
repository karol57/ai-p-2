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

    double fitnessSum = 0.0;
    std::vector<std::pair<Chromosome, double>> individuals;
    for (size_t i = 0u; i < o.population; ++i)
    {
        Chromosome ch{ std::uniform_int_distribution<uint8_t>()(rng) };
        const double fitness = func(ch.value());
        individuals.emplace_back(ch, fitness);
        fitnessSum += fitness;
    }

    const auto dumpIndividuals
        = [&fitnessSum](const std::vector<std::pair<Chromosome, double>>& individuals)
        {
            for (const auto& [individual, fitness] : individuals)
            {
                std::cout << individual << " phenotype " << static_cast<unsigned>(individual.value())
                        << " fitness " << fitness
                        << " probability " << fitness / fitnessSum <<  std::endl;
            }
        };

    std::cout << "--- Generated individuals ---" << std::endl;
    dumpIndividuals(individuals);

    for (std::size_t i = 0; i < 10; ++i)
    {
        std::cout << "=== Iteration " << i << " ===" << std::endl;

        std::vector<std::pair<Chromosome, double>> newGeneration;

        for (size_t i = 0u; i < individuals.size(); ++i)
        {
            std::uniform_real_distribution<double> fitnessDist{ 0.0, fitnessSum };
            const double rndFit = fitnessDist(rng);

            auto it = individuals.cbegin();
            double sum = it->second;
            while (sum < rndFit)
                sum += (++it)->second;
            newGeneration.emplace_back(*it);
        }
        dumpIndividuals(newGeneration);

        std::cout << "--- Crossing ---" << std::endl;

        std::cout << "--- Mutating ---" << std::endl;

        individuals = std::move(newGeneration);

        // fitnessSum = 0.0;
        // for (const auto& [_, fitness] : individuals)
        //     fitnessSum += fitness;
    }

    return 0;
}
