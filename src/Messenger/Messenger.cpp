#include <chrono>

#include "Messenger.hpp"

using std::endl;

using namespace Base::Messenger;

queue_string::queue_string( const char*&& t_cstr ): m_first{ new node{ t_cstr } }
{
};

queue_string::queue_string( const char*&  t_cstr ): m_first{ new node{ t_cstr } }
{
};

queue_string::~queue_string( void )
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

void queue_string::add( const char*& t_cstr )
{
    m_end->m_cstr = new char{ *t_cstr };
    m_end->m_next = new node;
    m_end = m_end->m_next;
}

void queue_string::operator=( const char*& t_cstr )
{
    m_end->m_cstr = new char{ *t_cstr };
    m_end->m_next = new node;
    m_end = m_end->m_next;
}

void queue_string::clear( void )
{
    m_end = m_first;
}

queue::queue( t_class*&  t_obj ): m_first{ new node{ t_obj } }
{

};

template< class t_class >
queue::queue< t_class >( t_class*&& t_obj ): m_first{ new node{ t_obj } }
{

};

namespace Base::Messenger {
ostream& operator<<( ostream& t_ostream, queue_string& t_queue_string )
{
    t_queue_string.m_cur = t_queue_string.m_first;
    while( t_queue_string.m_cur != t_queue_string.m_end )
        t_ostream << t_queue_string.m_cur->m_cstr;
    t_ostream << t_queue_string.m_cur->m_cstr;
}
}

messenger::messenger( ostream& t_ostream, const char*& t_welcome,
                      const char*& t_file, const char*& t_function, const int& t_line ):
                      m_incompleteMessage{ new message{ k_vInfo, "Instance of \`messager\` class created.",
                                                        t_file, t_function, t_line } }
{
    m_ostream = &t_ostream;

    *m_ostream << t_welcome << endl;
    m_thread = new thread( &messenger::main, this );
}

messenger::~messenger()
{
    m_queue.enqueue( m_incompleteMessage );
    std::this_thread::sleep_for( std::chrono::milliseconds( 200 ) );
    m_end = true;
    m_thread->join();
    delete m_thread;
}

void messenger::main()
{
    while( !m_end )
        if( !m_queue.isEmpty() )
            output( m_queue.dequeue() );
}

void messenger::print( const char*& t_priority, const char*& t_message,
                       const char*&& t_file, const char*&& t_function, const int&& t_line )
{
    m_queue.enqueue( m_incompleteMessage );
    m_incompleteMessage = new message{ t_priority, t_message,
                                       t_file, t_function, t_line };
}

messenger& messenger::operator()( const char*& t_priority,
                                  const char*&& t_file, const char*&& t_function, const int&& t_line )
{
    m_queue.enqueue( m_incompleteMessage );
    m_incompleteMessage = new message{ t_priority, "", t_file, t_function, t_line };

    return *this;
}

void messenger::output( const char*& t_priority, const char*& t_message,
                        const char*&& t_file, const char*&& t_function, const int&& t_line )
{
    *m_ostream << t_priority << " <" << t_file << "::" << t_function
               << " (" << t_line << ")> : " << t_message << endl;
}

void messenger::output( message& t_message )
{
    *m_ostream << t_message.m_verbosity << " <" << t_message.m_file << "::" << t_message.m_function
               << " (" << t_message.m_line << ")> : " << t_message.m_stringList << endl;
}

messenger& messenger::operator<<( const char*& t_message )
{

    m_incompleteMessage->m_stringList.add( t_message );

    return *this;
}

messenger& messenger::operator<<( const int& t_message )
{
    int message_int = t_message;

    int digits = 0;
    while( t_message / exp( 10, digits ) != 0 )
        ++digits;
    char* message_str = new char[ digits + 1 ];
    message_str[ digits ] = '\0';

    for( int pow = digits - 1, i = 0; pow > -1 ; pow--, i++ ) {
        message_str[ i ] = message_int / exp( 10, pow ) + 48;
        message_int -= message_int / exp( 10, pow ) * exp( 10, pow );
    }

    const char* message_str_const{ message_str }; // To my knowledge there is no way around this.
    m_incompleteMessage->m_stringList.add( message_str_const );

    return *this;
}

messenger& messenger::operator<<( const double& t_message )
{
    // Integer
    int message_int = t_message;

    int digits = 0;
    while( message_int / exp( 10, digits ) != 0 )
        ++digits;
    char* message_str = new char[ digits + 10 + 1 ];

    for( int i = digits - 1; i > -1 ; i-- ) {
        message_str += message_int / exp( 10, i ) + 48;
        message_int -= message_int / exp( 10, i ) * exp( 10, i );
    }

    // Decimal
    message_str += ".";
    double message_double = t_message - int( t_message );

    while( message_double > 0.1 ) {
        message_str += int( message_double * 10.0 ) + 48;
        message_double = message_double * 10.0 - floor( message_double * 10 );
    }

    m_incompleteMessage->m_stringList.add( message_str );

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

    m_incompleteMessage.m_message += message_str;

    return *this;
}

messenger& messenger::operator<<( const rational& t_message )
{
    char* message = t_message.cstr();
    for( char* i = &message[ 0 ]; *i != '\0'; i++ )
        m_incompleteMessage.m_message += *i;

    return *this;
}

messenger& messenger::operator<<( const bool& t_message )
{
    if( t_message )
        m_incompleteMessage.m_message += "1";
    else
        m_incompleteMessage.m_message += "0";

    return *this;
}
