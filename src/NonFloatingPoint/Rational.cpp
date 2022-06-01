//
// Created by Noah Everett on 6/1/22.
//

#include "Rational.hpp"

rational::rational()
{
}

rational::rational( const int& t_int )
{
    m_int = t_int;
}

rational::rational( const int&& t_int )
{
    m_int = t_int;
}

rational::rational( const double& t_double )
{
    m_int = int( t_double );
    double dig = t_double - m_int;
    for( int i = 0; i < 10; i++ ) {
        dig *= 10;
        m_dec += int( dig ) * exp( 10, 9 - i );
    }
}

//rational::rational( const double&& t_double )
//{
//    m_int = int( t_double );
//    m_dec = int( t_double - int( t_double ) );
//}

rational::rational( const rational& t_rational )
{
    m_int = t_rational.m_int;
    m_dec = t_rational.m_dec;
}

rational::rational( const rational&& t_rational )
{
    m_int = t_rational.m_int;
    m_dec = t_rational.m_dec;
}

rational::~rational()
{
}

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

//rational& rational::opterator=( const double& t_double )
//{
//    m_int = int( t_double );
//    m_dec = t_double =
//}

ostream& operator<<( ostream& t_ostream, const rational& t_rational )
{
    t_ostream << t_rational.m_int << '.' << t_rational.m_dec;

    return t_ostream;
}