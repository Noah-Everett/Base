#ifndef MESSENGER_HPP
#define MESSENGER_HPP

#include <iostream>
#include <string>
#include <thread>
#include <utility>

#include "Rational.hpp"
#include "Verbosity.hpp"
#include "Queue.hpp"
#include "Queue_NoShrink.hpp"

using std::ostream;
using std::cout;
using std::string;
using std::thread;
using std::pair;

using namespace Base::Rational;
using namespace Base::Queue::Queue;
using namespace Base::Queue::Queue_NoShrink;

namespace Base::Messenger {

const char* k_NUL = new char[ 1 ]{ '\0' };

#define LOCATION __FILE__, __FUNCTION__, __LINE__

class messenger
{
    public:
        messenger( ostream& t_ostream = cout, const char*& welcome = k_NUL,
                  const char*& file = k_NUL, const char*& function = k_NUL, const int& line = 0 );
       ~messenger();

        void       print     ( const char*& priority, const char*& message,
                               const char*&& file, const char*&& function, const int&& line );
        messenger& operator()( const char*& t_priority,
                               const char*&& t_file, const char*&& t_function, const int&& t_line );
        messenger& operator<<( const char*              & t_message );
        messenger& operator<<( const string             & t_message );
        messenger& operator<<( const int                & t_message );
        messenger& operator<<( const double             & t_message );
        messenger& operator<<( const pair< double, int >& t_message );
        messenger& operator<<( const rational           & t_message );
        messenger& operator<<( const bool               & t_message );
        void       end       ( bool t_end = true ) { m_end = t_end; };

    private:
        struct message {
            const char*&            m_verbosity;
            queue_noShrink< char* > m_string;
            const char*&            m_file;
            const char*&            m_function;
            const int  &            m_line;
        };
        ostream*         m_ostream;
        thread*          m_thread;
        queue< message > m_queue;
        message*         m_incompleteMessage;
        bool             m_end = false;

        void main();
        void output( message*& t_message );
        void output( const char*& t_priority, const char*& t_message,
                     const char*&& t_file, const char*&& t_function, const int&& t_line );
};

extern messenger messenger_c;

}

#endif
