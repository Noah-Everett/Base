//
// Created by Noah Everett on 6/1/22.
//

#include "Rational.hpp"

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
    unsigned int curExp;
    for( int w_int{ m_int }, nDigit{ nDigits_int - 1 }; nDigit > -1; pos++, w_int -= w_int / curExp, nDigit-- ) {
        str[ pos ] = w_int / exp( 10, nDigit );
    }

    str[ ++pos ] = '.';

    for( unsigned int w_dec{ m_dec }, nDigit{ nDigits_dec - 1 }; nDigit > -1; pos++, w_dec -= w_dec / curExp, nDigit-- ) {
        str[ pos ] = w_dec / exp( 10, nDigit );
    }

    str[ ++pos ] = '\0';
}