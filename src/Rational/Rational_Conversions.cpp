#include "Rational.hpp"

using namespace Base::Rational;

char*& rational::cstr( void ) const
{
    int nDigits_int{ 0 };
    for( int f_int{ m_int }; f_int != 0; nDigits_int++, f_int /= 10 ) {}
    if( nDigits_int == 0 ) ++nDigits_int;

    unsigned int nDigits_dec{ 0 };
    for( unsigned int f_dec{ m_dec }; f_dec != 0; nDigits_dec++, f_dec /= 10 ) {}
    if( nDigits_dec == 0 ) ++nDigits_dec;

    const unsigned int strSize = nDigits_int + nDigits_dec + 2;
    char* str = new char[ strSize ];

    unsigned int pos{ 0 };
    for( int w_int{ m_int }, nDigit{ nDigits_int - 1 }, digit{ 0 }, curExp{ 0 };
         nDigit > -1;
         pos++, w_int -= digit * curExp, nDigit-- ) {
        curExp = exp( 10, nDigit );
        digit = w_int / curExp;
        str[ pos ] = digit + 48;
    }

    str[ pos++ ] = '.';

    for( int w_dec = m_dec, nDigit = nDigits_dec - 1, digit{ 0 }, curExp{ 0 };
         nDigit > -1;
         pos++, w_dec -= digit * curExp, nDigit-- ) {
        curExp = exp( 10, nDigit );
        digit = w_dec / curExp;
        str[ pos ] = digit + 48;
    }

    str[ pos ] = '\0';

    return str;
}