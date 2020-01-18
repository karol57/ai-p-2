#pragma once

#include <cstdint>
#include <random>
#include <ostream>

class Chromosome
{
public:
    template<class RNG>
    Chromosome(RNG&& rng) : m_bits{ std::uniform_int_distribution<uint8_t>()(rng) } { }

    void set(unsigned);
    void reset(unsigned);
    void flip(unsigned);

    uint8_t value() const noexcept { return m_bits; }
    friend std::ostream& operator<<(std::ostream&, const Chromosome&);
private:
    uint8_t m_bits;
};
