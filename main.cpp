#include "Options.hpp"
#include "Application.hpp"
#include <iostream>
#include <boost/program_options.hpp>

int main(int argc, char * argv[])
{
    Options options;
    {
        namespace po = boost::program_options;
        boost::program_options::options_description desc(
            "This program searches for local minima x E [0;255] of function\n"
            "(a * sin(b * x) - c * cos(d * x) + a + c) / log(x + e)\n"
            "Allowed options");
        desc.add_options()
            ("help", "show this message")
            ("count", po::value<std::size_t>(&options.population)->default_value(20u), "number of individuals")
            ("pm", po::value<double>(&options.mutationProb)->default_value(0.1), "probability of mutation")
            ("pc", po::value<double>(&options.crossOverProb)->default_value(0.8), "probability of crossover")
            (",a", po::value<double>(&options.a)->default_value(38))
            (",b", po::value<double>(&options.b)->default_value(0.2))
            (",c", po::value<double>(&options.c)->default_value(2))
            (",d", po::value<double>(&options.d)->default_value(0.32))
            (",e", po::value<double>(&options.e)->default_value(20))
            ;

        try
        {
            po::variables_map vm;
            po::store(po::parse_command_line(argc, argv, desc), vm);
            po::notify(vm);

            if (vm.count("help"))
            {
                std::cout << desc << std::endl;
                return 1;
            }

            if (options.population == 0u)
                throw std::runtime_error("Population must be greater than 0");

            if (options.mutationProb < 0.0 || options.mutationProb > 1.0)
                throw std::runtime_error("Mutation probability must be in range [0;1], received: " + std::to_string(options.mutationProb));

            if (options.crossOverProb < 0.0 || options.crossOverProb > 1.0)
                throw std::runtime_error("Crossover probability must be in rande [0;1], received: " + std::to_string(options.crossOverProb));
        }
        catch(const std::exception& ex)
        {
            std::cerr << "Error: " <<ex.what() << std::endl;
            std::cerr << desc << std::endl;
            return -1;
        }
    }
    return startApplication(options);
}
