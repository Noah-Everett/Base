cmake_minimum_required( VERSION 3.21 )
project( Base )

set( CMAKE_CXX_STANDARD 20 )

add_compile_options( -v )

add_library( Base
             src/Input/CmdLnArgParser.hpp      src/Input/CmdLnArgParser.cpp
             src/Output/Messenger.hpp          src/Output/Messenger.cpp
             src/NonFloatingPoint/Rational.hpp src/NonFloatingPoint/Rational.cpp )
target_include_directories( ${PROJECT_NAME} BEFORE PUBLIC
                            src/Input/
                            src/Output/
                            src/NonFloatingPoint/ )
