#pragma once

#include <cstdint>
#include <ostream>

class Chromosome
{
public:
    Chromosome(uint8_t bits) noexcept : m_bits{bits } { }

    void set(unsigned);
    void reset(unsigned);
    void flip(unsigned);

    uint8_t value() const noexcept { return m_bits; }
    friend std::ostream& operator<<(std::ostream&, const Chromosome&);
private:
    uint8_t m_bits;
};
