#include <chrono>
#include <math.h>

#include "Messenger.hpp"

using std::endl;

using namespace Base::Messenger;

stringList::~stringList( void )
{
    if( m_first->m_next == nullptr ) { // If only one node exists
        delete m_first;
        return;
    }

    m_cur = m_first;
    m_end = m_cur->m_next;
    while( m_end->m_next != nullptr ) {
       delete m_cur;
       m_end = m_cur;
       m_end = m_end->m_next;
    }
    delete m_cur;
    delete m_end;
}

void stringList::add( char*& t_cstr )
{
    m_end->m_cstr = new char{ *t_cstr };
    m_end->m_next = new node;
    m_end = m_end->m_next;
}

void stringList::clear( void )
{
    m_end = m_first;
}

namespace Base::Messenger {
ostream& operator<<( ostream& t_ostream, stringList& t_stringList )
{
    t_stringList.m_cur = t_stringList.m_first;
    while( t_stringList.m_cur != t_stringList.m_end )
        t_ostream << t_stringList.m_cur->m_cstr;
    t_ostream << t_stringList.m_cur->m_cstr;
}
}

messenger::messenger( ostream& t_ostream, const string& t_welcome,
                      const string& t_file, const string& t_function, const int& t_line )
{
    m_ostream = &t_ostream;

    *m_ostream << t_welcome << endl;
    m_thread = new thread( &messenger::main, this );
    m_message_incomplete = { k_vInfo, "Instance of \`messager\` class created.",
                             t_file, t_function, t_line };
}

messenger::~messenger()
{
    m_queue.push( m_message_incomplete );
    std::this_thread::sleep_for( std::chrono::milliseconds( 200 ) );
    m_end = true;
    m_thread->join();
    delete m_thread;
}

void messenger::main()
{
    while( !m_end ) {
        if( !m_queue.empty() ) {
            output( m_queue.front() );
            m_queue.pop();
        }
    }
}

void messenger::print( const string& t_priority, const string& t_message,
                       const string& t_file, const string& t_function, const int& t_line )
{
    m_queue.push( { t_priority, t_message,
                    t_file, t_function, t_line } );
}

messenger& messenger::operator()( const string& t_priority,
                                  const string& t_file, const string& t_function, const int& t_line )
{
    m_queue.push( m_message_incomplete );
    m_message_incomplete = { "", "", "", "", 0 };

    m_message_incomplete.m_priority = t_priority;
    m_message_incomplete.m_file = t_file;
    m_message_incomplete.m_function = t_function;
    m_message_incomplete.m_line = t_line;

    return *this;
}

void messenger::output( const string& t_priority, const string& t_message,
                        const string& t_file, const string& t_function, const int& t_line )
{
    *m_ostream << t_priority << " <" << t_file << "::" << t_function
               << " (" << t_line << ")> : " << t_message << endl;
}

void messenger::output( const message& t_message )
{
    *m_ostream << t_message.m_priority << " <" << t_message.m_file << "::" << t_message.m_function
               << " (" << t_message.m_line << ")> : " << t_message.m_message << endl;
}

messenger& messenger::operator<<( const char*& t_message )
{

    m_message_incomplete.m_message += message_str;

    return *this;
}

messenger& messenger::operator<<( const int& t_message )
{
    int message_int = t_message;
    string message_str = "";

    int digits = 0;
    while( t_message / int( pow( 10, digits ) ) != 0 )
        ++digits;

    for( int i = digits - 1; i > -1 ; i-- ) {
        message_str += message_int / int( pow( 10, i ) ) + 48;
        message_int -= message_int / int( pow( 10, i ) ) * int( pow( 10, i ) );
    }

    m_message_incomplete.m_message += message_str;

    return *this;
}

messenger& messenger::operator<<( const double& t_message )
{
    // Integer
    int message_int = t_message;
    string message_str = "";

    int digits = 0;
    while( message_int / int( pow( 10, digits ) ) != 0 )
        ++digits;

    for( int i = digits - 1; i > -1 ; i-- ) {
        message_str += message_int / int( pow( 10, i ) ) + 48;
        message_int -= message_int / int( pow( 10, i ) ) * int( pow( 10, i ) );
    }

    // Decimal
    message_str += ".";
    double message_double = t_message - int( t_message );

    while( message_double > 0.1 ) {
        message_str += int( message_double * 10.0 ) + 48;
        message_double = message_double * 10.0 - floor( message_double * 10 );
    }

    m_message_incomplete.m_message += message_str;

    return *this;
}

messenger& messenger::operator<<( const pair< double, int >& t_message )
{
    // Integer
    int message_int = t_message.first;
    string message_str = "";

    int digits = 0;
    while( message_int / int( pow( 10, digits ) ) != 0 )
        ++digits;

    for( int i = digits - 1; i > -1 ; i-- ) {
        message_str += message_int / int( pow( 10, i ) ) + 48;
        message_int -= message_int / int( pow( 10, i ) ) * int( pow( 10, i ) );
    }

    // Decimal
    message_str += ".";
    double message_double = t_message.first - int( t_message.first );

    for( int i = 0; i < t_message.second && message_double > 0.1; i++ ) {
        message_str += int( message_double * 10.0 ) + 48;
        message_double = message_double * 10.0 - floor( message_double * 10 );
    }

    m_message_incomplete.m_message += message_str;

    return *this;
}

messenger& messenger::operator<<( const rational& t_message )
{
    char* message = t_message.cstr();
    for( char* i = &message[ 0 ]; *i != '\0'; i++ )
        m_message_incomplete.m_message += *i;

    return *this;
}

messenger& messenger::operator<<( const bool& t_message )
{
    if( t_message )
        m_message_incomplete.m_message += "1";
    else
        m_message_incomplete.m_message += "0";

    return *this;
}
