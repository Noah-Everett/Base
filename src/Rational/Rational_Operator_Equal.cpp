#include "Rational.hpp"

using namespace Base::Rational;

rational& rational::operator=( const int& t_int )
{
    m_int = t_int;
    m_dec = 0;

    return *this;
}

rational& rational::operator=( const int&& t_int )
{
    m_int = t_int;
    m_dec = 0;

    return *this;
}

rational& rational::operator=( const double& t_double )
{
    m_int = int( t_double );
    m_dec = 0;
    double dec = t_double - m_int;
    for( int i = 0; i < 9; i++ ) {
        dec *= 10;
        m_dec += int( dec ) * exp( 10, 8 - i );
        dec -= int( dec );
    }

    return *this;
}

rational& rational::operator=( const double&& t_double )
{
    m_int = int( t_double );
    m_dec = 0;
    double dec = t_double - m_int;
    for( int i = 0; i < 9; i++ ) {
        dec *= 10;
        m_dec += int( dec ) * exp( 10, 8 - i );
        dec -= int( dec );
    }

    return *this;
}

rational& rational::operator=( const rational& t_rational )
{
    m_int = t_rational.m_int;
    m_dec = t_rational.m_dec;
}

rational& rational::operator=( const rational&& t_rational )
{
    m_int = t_rational.m_int;
    m_dec = t_rational.m_dec;
}
