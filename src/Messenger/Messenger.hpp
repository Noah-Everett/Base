#ifndef MESSENGER_HPP
#define MESSENGER_HPP

#include <iostream>
#include <string>
#include <thread>
#include <utility>

#include "Rational.hpp"
#include "Verbosity.hpp"

using std::ostream;
using std::cout;
using std::string;
using std::thread;
using std::pair;

using namespace Base::Rational;

namespace Base::Messenger {

const char* k_NUL = new char[ 1 ]{ '\0' };

#define LOCATION __FILE__, __FUNCTION__, __LINE__

class stringList
{
    public:
        stringList( const char*&& t_cstr ): m_first{ new node{ t_cstr } } {};
        stringList( const char*&  t_cstr ): m_first{ new node{ t_cstr } } {};
       ~stringList( void );

        void add      ( const char*& t_cstr );
        void operator=( const char*& t_cstr ); // Same as add()
        void clear    ( void                );
        friend ostream& operator<<( ostream& t_ostream, stringList& t_stringList );

    private:
        struct node {
            const char* m_cstr;
            node* m_next{ nullptr };
        };
        node* m_first;
        node* m_cur{ m_first };
        node* m_end{ m_first };
};

template< class t_class >
class queue // Uses variables passed in (doesn't allocate any new memory)
            //                          (hence the reason to reinvent the wheel, per se)
{
    public:
        queue( t_class*& t_obj ): m_first{ new node{ t_obj } } {};
        queue( void );
       ~queue( void );

        void     enqueue( t_class*& t_obj );
        t_class& dequeue( void            );
        bool&    isEmpty( void            );

    private:
        struct node {
            t_class m_class;
            t_class* m_next = nullptr;
        };
        node* m_first;
        node* m_cur{ m_first };
        node* m_end{ m_first };
};

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
            const char*& m_verbosity;
            stringList   m_stringList;
            const char*& m_file;
            const char*& m_function;
            const int  & m_line;
        };
        ostream*         m_ostream;
        thread*          m_thread;
        queue< message > m_queue;
        message*         m_incompleteMessage;
        bool             m_end = false;

        void main();
        void output( message& t_message );
        void output( const char*& t_priority, const char*& t_message,
                     const char*&& t_file, const char*&& t_function, const int&& t_line );
};

extern messenger messenger_c;

}

#endif
