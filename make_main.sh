main() {
  if [ -z ${1} ] || [ ${1} == "-h" ] || [ ${1} == "--help" ]; then
    usage
    return 1;
  else
    NAME=${1}
  fi

  make_file
}

usage() {
  echo "make_main.sh </dir/to/main/file.cpp> [-h|--help]"
}

make_file() {
cat <<EOF > $NAME
#include "Input/CmdLnArgParser.hpp"
#include "Output/Messenger.hpp"

using namespace std;

// Constant messages
const string k_welcome = "WELCOME MESSAGE HERE"
const string k_help    = "PROGRAM HELP/USAGE STATEMENT HERE

// Global console messenger
messenger messenger_c( cout, k_welcome, LOCATION );

// Possible arguments
vector< string > optsWArg_req = {};
vector< string > optsWArg_opt = {};
vector< string > optsNArg_req = {};
vector< string > optsNArg_opt = { "-h", "--help" };

int main( int argc, char** argv )
{
    ///////////////////////////////////////////////////////////////////////////////
    ///                         Command Line Arguments                          ///
    ///////////////////////////////////////////////////////////////////////////////
    parser parser( argc, argv, optsWArg_req, optsWArg_opt, optsNArg_req, optsNArg_opt );

    if( parser.hasOpt( "-h" ) || parser.hasOpt( "--help" ) ) {
        messenger_c( k_pFatal, LOCATION ) << '\n';// << k_help;
        return 0;
    }



    ///////////////////////////////////////////////////////////////////////////////
    ///                              Main Method                                ///
    ///////////////////////////////////////////////////////////////////////////////



    ///////////////////////////////////////////////////////////////////////////////
    ///                                End Program                              ///
    ///////////////////////////////////////////////////////////////////////////////
    return 0;
}
EOF
}

main "$@"