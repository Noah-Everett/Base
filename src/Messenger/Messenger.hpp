#ifndef MESSENGER_HPP
#define MESSENGER_HPP

// std
#include <iostream>
#include <string>
#include <thread>
#include <queue>
#include <utility>
// #include <map>
using std::ostream;
using std::cout;
using std::string;
using std::thread;
using std::queue;
using std::pair;
// using std::map;

// Base
#include "Rational.hpp"
using namespace Base::Rational;

namespace Base::Messenger::Verbosity {
extern const string null_str   ; extern const int null_int   ;
extern const string debug_str  ; extern const int debug_int  ;
extern const string info_str   ; extern const int info_int   ;
extern const string warning_str; extern const int warning_int;
extern const string error_str  ; extern const int error_int  ;
extern const string fatal_str  ; extern const int fatal_int  ;
extern const string verbosity_map[ 6 ];

// extern const map< int, string > verbosity_map;
extern int    verbosity_int;
extern string verbosity_str;
}

namespace Base::Messenger {

#define LOCATION __FILE__, __FUNCTION__, __LINE__

class messenger {
    public:
        messenger( ostream& t_ostream = cout, const string& welcome = "",
                   const string& file = __FILE__, const string& function = __FUNCTION__, const int& line = __LINE__ );
       ~messenger();

        void       print     ( const int   & priority, const string& message,
                               const string& file, const string& function, const int& line );
        messenger& operator()( const int   & t_priority, const string& t_file,
                               const string& t_function, const int& t_line );
        template< class t_class >
        messenger& operator<<( const t_class            &  t_message );
        messenger& operator<<( const int                &  t_message );
        messenger& operator<<( const double             &  t_message );
        messenger& operator<<( const pair< double, int >&  t_message );
        messenger& operator<<( const rational           &  t_message );
        messenger& operator<<( const bool               &  t_message );
        void       end       ( bool t_end = true ) { m_end = t_end; };

    private:
        struct message {
            int    m_priority;
            string m_message;
            string m_file;
            string m_function;
            int    m_line;
        };
        ostream*         m_ostream;
        thread*          m_thread;
        queue< message > m_queue;
        message          m_message_incomplete;
        int              m_verbosity;                //// IMPLEMENT
        bool             m_end = false;

        void main();
        void output( const message& t_message );
        void output( const int   & t_priority, const string& t_message,
                     const string& t_file, const string& t_function, const int& t_line );
};

template< class t_class >
messenger& messenger::operator<<( const t_class& t_message )
{
    m_message_incomplete.m_message += t_message;

    return *this;
}

// Messenger global variables (define in main file)
extern messenger messenger_c  ;

}

#endif
