#ifndef MESSENGER_HPP
#define MESSENGER_HPP

#include <iostream>
#include <string>
#include <thread>
#include <queue>
#include <utility>

#include "Rational.hpp"

using std::ostream;
using std::cout;
using std::string;
using std::thread;
using std::queue;
using std::pair;

using namespace Base::Rational;

namespace Base::Messenger {

#define LOCATION __FILE__, __FUNCTION__, __LINE__


class message
{
    public:
        message( const int& t_verbosity = 0 );
       ~message( void );

        bool add  ( char*& t_cstr );
        void clear( void          );

    protected:
        struct node {
            char* m_cstr;
            node* m_next;
        };
        node  m_first;
        node* cur; // also end of chain
        int  m_verbosity;
};

class messenger : message
{
    public:
        messenger( ostream& t_ostream = cout, const string& welcome = "",
                  const string& file = __FILE__, const string& function = __FUNCTION__, const int& line = __LINE__ );
       ~messenger();

        void       print     ( const string& priority, const string& message,
                               const string& file, const string& function, const int& line );
        messenger& operator()( const string& t_priority, const string& t_file,
                               const string& t_function, const int& t_line );
        template< class t_class >
        messenger& operator<<( const t_class            & t_message );
        messenger& operator<<( const char*              & t_message );
        messenger& operator<<( const int                & t_message );
        messenger& operator<<( const double             & t_message );
        messenger& operator<<( const pair< double, int >& t_message );
        messenger& operator<<( const rational           & t_message );
        messenger& operator<<( const bool               & t_message );
        void       end       ( bool t_end = true ) { m_end = t_end; };

    private:
        struct message {
            string m_priority;
            char** m_message = new char*[ 100 ];
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
