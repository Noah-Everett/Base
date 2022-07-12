#ifndef CMD_LN_ARG_PARSER_HPP
#define CMD_LN_ARG_PARSER_HPP

#include <vector>
#include <string>

using std::vector;
using std::string;
using std::tolower;

namespace Base::CmdLnArgParser {

class parser {
    public:
        parser( int t_argc, char** t_argv,
                const vector< string >& t_optsWArg_req, const vector< string >& t_optsWArg_opt,
                const vector< string >& t_optsNArg_req, const vector< string >& t_optsNArg_opt );
       ~parser();

        bool   hasOpt       ( const string& t_opt ) const;
        bool   getArg_bool  ( const string& t_opt ) const;
        int    getArg_int   ( const string& t_opt ) const;
        double getArg_double( const string& t_opt ) const;
        string getArg_string( const string& t_opt ) const;
        string getOptsArgs_string()                 const;

    private:
        struct optArg {
            string opt;
            string arg;
        };

        vector< optArg > m_optsArgs;
};

}

#endif

