#include "Rational.hpp"

using namespace Base::Rational;

ostream& operator<<( ostream& t_ostream, const rational& t_rational )
{
    t_ostream << t_rational.m_int << '.' << t_rational.m_dec;

    return t_ostream;
}