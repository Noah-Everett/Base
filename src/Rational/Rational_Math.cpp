#include "Rational.hpp"

namespace Base::Rational {
int& exp( const int& t_base, const int& t_exponent )
{
    int out = 1;

    if( t_exponent < 0 ) {
        std::cout << "ERROR: exp does not currently support t_exponent < 0" << std::endl;
        return out;
    }

    for( int i = 0; i < t_exponent; i++ )
        out *= t_base;

    return out;
}

}