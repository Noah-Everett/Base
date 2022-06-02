#include "Rational.hpp"

using namespace Base::Rational;

rational::rational( const double& t_double )
{
    m_int = int( t_double );
    double dec = t_double - m_int;
    for( int i = 0; i < 9; i++ ) {
        dec *= 10;
        m_dec += int( dec ) * exp( 10, 8 - i );
        dec -= int( dec );
    }
}

rational::rational( const double&& t_double )
{
    m_int = int( t_double );
    double dec = t_double - m_int;
    for( int i = 0; i < 9; i++ ) {
        dec *= 10;
        m_dec += int( dec ) * exp( 10, 8 - i );
        dec -= int( dec );
    }
}
