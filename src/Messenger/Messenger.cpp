#include <chrono>
#include <math.h>

#include "Messenger.hpp"

using std::endl;

using namespace Base::Messenger;
using namespace Base::Messenger::Verbosity;

namespace Base::Messenger::Verbosity {
const string null_str    = ""       ; const int null_int    = 5;
const string debug_str   = "DEBUG"  ; const int debug_int   = 4;
const string info_str    = "INFO"   ; const int info_int    = 3;
const string warning_str = "WARNING"; const int warning_int = 2;
const string error_str   = "ERROR"  ; const int error_int   = 1;
const string fatal_str   = "FATAL"  ; const int fatal_int   = 0;
const string verbosity_map[ 6 ] = { fatal_str, error_str, warning_str, info_str, debug_str, null_str };

// const map< int, string > verbosity_map = { { fatal_int  , fatal_str   }, 
//                                            { error_int  , error_str   }, 
//                                            { warning_int, warning_str }, 
//                                            { info_int   , info_str    }, 
//                                            { debug_int  , debug_str   }, 
//                                            { null_int   , null_str    } };
// const map< int, string > verbosity_map = { { 0, "FATAL" }, 
//                                            { 1, "ERROR" }, 
//                                            { 2, "WARNING" }, 
//                                            { 3, "INFO" }, 
//                                            { 4, "DEBUG" }, 
//                                            { 5, "" } };
int    verbosity_int = 4;
string verbosity_str = verbosity_map[ verbosity_int ];
}

messenger::messenger( ostream& t_ostream, const string& t_welcome,
                      const string& t_file, const string& t_function, const int& t_line )
{
    m_ostream = &t_ostream;

    *m_ostream << t_welcome << endl;
    m_thread = new thread( &messenger::main, this );
    m_message_incomplete = { info_int, "Instance of \`messager\` class created.",
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

void messenger::print( const int& t_priority, const string& t_message,
                       const string& t_file, const string& t_function, const int& t_line )
{
    m_queue.push( { t_priority, t_message,
                    t_file, t_function, t_line } );
}

messenger& messenger::operator()( const int& t_priority,
                                  const string& t_file, const string& t_function, const int& t_line )
{
    if( verbosity_int >= t_priority ) {
        m_queue.push( m_message_incomplete );
        m_message_incomplete = { 0, "", "", "", 0 };

        m_message_incomplete.m_priority = t_priority;
        m_message_incomplete.m_file = t_file;
        m_message_incomplete.m_function = t_function;
        m_message_incomplete.m_line = t_line;
    }

    return *this;
}

void messenger::output( const int& t_priority, const string& t_message,
                        const string& t_file, const string& t_function, const int& t_line )
{
    *m_ostream << verbosity_map[ t_priority ] << " <" << t_file << "::" << t_function
               << " (" << t_line << ")> : " << t_message << endl;
}

void messenger::output( const message& t_message )
{
    *m_ostream << verbosity_map[ t_message.m_priority ] << " <" << t_message.m_file << "::" << t_message.m_function
               << " (" << t_message.m_line << ")> : " << t_message.m_message << endl;
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
