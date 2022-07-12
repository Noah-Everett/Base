#ifndef MESSENGER_HPP
#define MESSENGER_HPP

#include <iostream>
#include <string>
#include <thread>
#include <queue>
#include <utility>
#include <map>

#include "Rational.hpp"

using std::ostream;
using std::cout;
using std::string;
using std::thread;
using std::queue;
using std::pair;
using std::map;

using namespace Base::Rational;

namespace Base::Messenger {

#define LOCATION __FILE__, __FUNCTION__, __LINE__

const string k_pNull    = ""       ;
const string k_pDebug   = "DEBUG"  ;
const string k_pInfo    = "INFO"   ;
const string k_pNotice  = "NOTICE" ;
const string k_pWarning = "WARNING";
const string k_pError   = "ERROR"  ;
const string k_pFatal   = "FATAL"  ;

const map< int, string > verbosity_map = { { 0, k_pFatal   }, { 1, k_pError  }, 
                                           { 2, k_pWarning }, { 3, k_pNotice }, 
                                           { 4, k_pInfo    }, { 5, k_pDebug  }, 
                                           { 4, k_pNull    }                 };

class messenger {
    public:
        messenger( ostream& t_ostream = cout, const string& welcome = "",
                  const string& file = __FILE__, const string& function = __FUNCTION__, const int& line = __LINE__ );
       ~messenger();

        void       print     ( const string& priority, const string& message,
                               const string& file, const string& function, const int& line );
        messenger& operator()( const string& t_priority, const string& t_file,
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
            string m_priority;
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
        void output( const string& t_priority, const string& t_message,
                     const string& t_file, const string& t_function, const int& t_line );
};

template< class t_class >
messenger& messenger::operator<<( const t_class& t_message )
{
    m_message_incomplete.m_message += t_message;

    return *this;
}

extern messenger messenger_c;

}

#endif
