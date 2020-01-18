#pragma once

#include <ostream>

class Function
{
public:
    Function(double a, double b, double c, double d, double e);

    double operator()(double x) const noexcept;

    friend std::ostream& operator<<(std::ostream&, const Function&) noexcept;
private:
    double m_a, m_b, m_c, m_d, m_e;
};
