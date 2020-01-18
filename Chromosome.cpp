#include "Chromosome.hpp"
#include <iomanip>
std::ostream& operator<<(std::ostream& s, const Chromosome& c)
{
    for (uint8_t selectedBit = static_cast<uint8_t>(1u << 7u); selectedBit != 0u; selectedBit >>= 1u)
    {
        s << (c.m_bits & selectedBit ? 1 : 0);
    }
    return s;
}
