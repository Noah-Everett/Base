//
// Created by Noah Everett on 6/1/22.
//

#ifndef BASE_RATIONAL_HPP
#define BASE_RATIONAL_HPP

#include <iostream>

using std::ostream;

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
        rational();
        rational( const int    & t_int    );
        rational( const int   && t_int    );
        rational( const double & t_double );
        rational( const double&& t_double );
        rational( const rational & t_rational );
        rational( const rational&& t_rational );
       ~rational();

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

    private:
                 int m_int = 0;
        unsigned int m_dec = 0;
};

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

#endif //BASE_RATIONAL_HPP
