main() {
  for i in "$@"; do
    case $i in
      -o=*         ) export OUTDIR="${i#*=}"      shift    ;;
      -h*|--help*  ) usage;                       return 1 ;;
      -*           ) echo "Unknown option \"$i\"" return 1 ;;
      *            ) export PROJECT_NAME="$i"     shift    ;;
    esac
  done

  if [ -z "${PROJECT_NAME}" ]; then
    usage
    return 1;
  fi
  if [ -n "${OUTDIR}" ]; then
    mkdir ${OUTDIR} >> /dev/null
    cd ${OUTDIR}
  fi

  make_main
  make_CMakeLists

  cd - >> /dev/null
}

usage() {
  echo "make_main.sh [-o=</project/output/directory>] [-h|--help] <project name>"
}

make_main() {
cat <<EOF > ${PROJECT_NAME}.cpp
#include <string>
#include <iostream>
#include <vector>

#include "CmdLnArgParser.hpp"
#include "Messenger.hpp"

using std::cout;
using std::string;
using std::vector;

// Constant messages
const string k_welcome = "WELCOME MESSAGE HERE";
const string k_help    = "PROGRAM HELP/USAGE STATEMENT HERE";

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

make_CMakeLists() {
cat <<EOF > CMakeLists.txt
cmake_minimum_required( VERSION 3.21 )
project( ${PROJECT_NAME} )

if( NOT DEFINED ENV{BASE_DIR} )
    message( FATAL_ERROR "\`ENV\\\${BASE_DIR}\` is not set. Make sure to source \`setup_base.sh\`, which is in \`Base/\`." )
else()
    message( STATUS "\`\$ENV{BASE_DIR}\` is set to \`$ENV{BASE_DIR}\`." )
endif()

set( CMAKE_CXX_STANDARD 20 )

add_subdirectory( \$ENV{BASE_DIR} \$ENV{BASE_DIR}/build )

add_executable( \${PROJECT_NAME} ${PROJECT_NAME}.cpp )

target_link_libraries( ${PROJECT_NAME} Base )

add_compile_options( -v )
EOF
}

main "$@"