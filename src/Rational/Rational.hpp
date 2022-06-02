#ifndef BASE_RATIONAL_HPP
#define BASE_RATIONAL_HPP

#include <iostream>

using std::ostream;

namespace Base::Rational {

//const unsigned int kE0 = 1;
//const unsigned int kE1 = 10;
//const unsigned int kE2 = 100;
//const unsigned int kE3 = 1000;
//const unsigned int kE4 = 10000;
//const unsigned int kE5 = 100000;
//const unsigned int kE6 = 1000000;
//const unsigned int kE7 = 10000000;
//const unsigned int kE8 = 100000000;
//const unsigned int kE9 = 1000000000;

class rational
{
    public:
        rational( void ) {};
        rational( const int    & t_int    ): m_int{ t_int }, m_dec{ 0 } {};
        rational( const int   && t_int    ): m_int{ t_int }, m_dec{ 0 } {};
        rational( const double & t_double );
        rational( const double&& t_double );
        rational( const rational & t_rational ): m_int{ t_rational.m_int }, m_dec{ t_rational.m_dec } {};
        rational( const rational&& t_rational ): m_int{ t_rational.m_int }, m_dec{ t_rational.m_dec } {};
        rational( const int & t_int, const unsigned int & t_dec ): m_int{ t_int }, m_dec{ t_dec } {};
        rational( const int&& t_int, const unsigned int & t_dec ): m_int{ t_int }, m_dec{ t_dec } {};
        rational( const int & t_int, const unsigned int&& t_dec ): m_int{ t_int }, m_dec{ t_dec } {};
        rational( const int&& t_int, const unsigned int&& t_dec ): m_int{ t_int }, m_dec{ t_dec } {};
       ~rational( void ) {};

        rational& operator=( const int      & t_int      );
        rational& operator=( const int     && t_int      );
        rational& operator=( const double   & t_double   );
        rational& operator=( const double  && t_double   );
        rational& operator=( const rational & t_rational );
        rational& operator=( const rational&& t_rational );

        rational& operator+ ( const int      & t_int      ) const;
        rational& operator+ ( const int     && t_int      ) const;
        rational& operator+ ( const double   & t_double   ) const;
        rational& operator+ ( const double  && t_double   ) const;
        rational& operator+ ( const rational & t_rational ) const;
        rational& operator+ ( const rational&& t_rational ) const;
        rational& operator+=( const int      & t_int      );
        rational& operator+=( const int     && t_int      );
        rational& operator+=( const double   & t_double   );
        rational& operator+=( const double  && t_double   );
        rational& operator+=( const rational & t_rational );
        rational& operator+=( const rational&& t_rational );
        rational& operator++( void ); // pre
        rational& operator++( int );  // post

        rational& operator- ( const int      & t_int      ) const;
        rational& operator- ( const int     && t_int      ) const;
        rational& operator- ( const double   & t_double   ) const;
        rational& operator- ( const double  && t_double   ) const;
        rational& operator- ( const rational & t_rational ) const;
        rational& operator- ( const rational&& t_rational ) const;
        rational& operator-=( const int      & t_int      );
        rational& operator-=( const int     && t_int      );
        rational& operator-=( const double   & t_double   );
        rational& operator-=( const double  && t_double   );
        rational& operator-=( const rational & t_rational );
        rational& operator-=( const rational&& t_rational );
        rational& operator--( void ); // pre
        rational& operator--( int );  // post

        rational& operator* ( const int      & t_int      ) const;
        rational& operator* ( const int     && t_int      ) const;
        rational& operator* ( const double   & t_double   ) const;
        rational& operator* ( const double  && t_double   ) const;
        rational& operator* ( const rational & t_rational ) const;
        rational& operator* ( const rational&& t_rational ) const;
        rational& operator*=( const int      & t_int      );
        rational& operator*=( const int     && t_int      );
        rational& operator*=( const double   & t_double   );
        rational& operator*=( const double  && t_double   );
        rational& operator*=( const rational & t_rational );
        rational& operator*=( const rational&& t_rational );

        rational& operator/ ( const int      & t_int      ) const;
        rational& operator/ ( const int     && t_int      ) const;
        rational& operator/ ( const double   & t_double   ) const;
        rational& operator/ ( const double  && t_double   ) const;
        rational& operator/ ( const rational & t_rational ) const;
        rational& operator/ ( const rational&& t_rational ) const;
        rational& operator/=( const int      & t_int      );
        rational& operator/=( const int     && t_int      );
        rational& operator/=( const double   & t_double   );
        rational& operator/=( const double  && t_double   );
        rational& operator/=( const rational & t_rational );
        rational& operator/=( const rational&& t_rational );

        rational& operator==( const int      & t_int      ) const;
        rational& operator==( const int     && t_int      ) const;
        rational& operator==( const double   & t_double   ) const;
        rational& operator==( const double  && t_double   ) const;
        rational& operator==( const rational & t_rational ) const;
        rational& operator==( const rational&& t_rational ) const;
        rational& operator!=( const int      & t_int      ) const;
        rational& operator!=( const int     && t_int      ) const;
        rational& operator!=( const double   & t_double   ) const;
        rational& operator!=( const double  && t_double   ) const;
        rational& operator!=( const rational & t_rational ) const;
        rational& operator!=( const rational&& t_rational ) const;

        rational& operator> ( const int      & t_int      ) const;
        rational& operator> ( const int     && t_int      ) const;
        rational& operator> ( const double   & t_double   ) const;
        rational& operator> ( const double  && t_double   ) const;
        rational& operator> ( const rational & t_rational ) const;
        rational& operator> ( const rational&& t_rational ) const;
        rational& operator>=( const int      & t_int      ) const;
        rational& operator>=( const int     && t_int      ) const;
        rational& operator>=( const double   & t_double   ) const;
        rational& operator>=( const double  && t_double   ) const;
        rational& operator>=( const rational & t_rational ) const;
        rational& operator>=( const rational&& t_rational ) const;

        rational& operator< ( const int      & t_int      ) const;
        rational& operator< ( const int     && t_int      ) const;
        rational& operator< ( const double   & t_double   ) const;
        rational& operator< ( const double  && t_double   ) const;
        rational& operator< ( const rational & t_rational ) const;
        rational& operator< ( const rational&& t_rational ) const;
        rational& operator<=( const int      & t_int      ) const;
        rational& operator<=( const int     && t_int      ) const;
        rational& operator<=( const double   & t_double   ) const;
        rational& operator<=( const double  && t_double   ) const;
        rational& operator<=( const rational & t_rational ) const;
        rational& operator<=( const rational&& t_rational ) const;

        friend ostream& operator<<( ostream& t_ostream, const rational & t_rational );
        friend ostream& operator<<( ostream& t_ostream, const rational&& t_rational );
        friend ostream& operator>>( ostream& t_ostream, const rational & t_rational );
        friend ostream& operator>>( ostream& t_ostream, const rational&& t_rational );

        char*& cstr( void ) const;

        // Class data
                 int m_int = 0;
        unsigned int m_dec = 0; // NOTE: Unsigned ints can go up to 10 digits; however that doesn't mean they go to 9,999,999,999 (they don't).
                                // Thus, class members that walk through digits will only go up to 9 digits.
};

int& exp( const int& t_base, const int& t_exponent );

}

#endif //BASE_RATIONAL_HPP
