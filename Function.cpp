#include "Function.hpp"
#include <cmath>

Function::Function(double a, double b, double c, double d, double e)
    : m_a{ a }, m_b{ b }, m_c{ c }, m_d{ d }, m_e{ e }
{
    if (e <= 0.0)
        throw std::runtime_error("Function: e coefficient must be greater than 0");
}

double Function::operator()(double x) const noexcept
{
    return (m_a * sin(m_b * x) - m_c * cos(m_d * x) + m_a + m_c) / log10(x + m_e);
}

std::ostream& operator<<(std::ostream& s, const Function& f) noexcept
{
    return s << "f(x) = (" << f.m_a << " * sin(" << f.m_b << " * x) - " << f.m_c << " * cos(" << f.m_d << " * x) + "
             << f.m_a << " + " << f.m_c <<") / log(x + "<< f.m_d << ")";
}
