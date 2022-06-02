cmake_minimum_required( VERSION 3.21 )
project( Base )

set( CMAKE_CXX_STANDARD 20 )

add_compile_options( -v )

add_library( Base
             src/Input/CmdLnArgParser.hpp      src/Input/CmdLnArgParser.cpp
             src/Output/Messenger.hpp          src/Output/Messenger.cpp
             src/NonFloatingPoint/Rational.hpp src/NonFloatingPoint/Rational_constructors.cpp
                                               src/NonFloatingPoint/Rational_Operator_Equal.cpp
                                               src/NonFloatingPoint/Rational_Operator_Addition.cpp
                                               src/NonFloatingPoint/Rational_Output.cpp
                                               src/NonFloatingPoint/Rational_Conversions.cpp
                                               src/NonFloatingPoint/Rational_Math.cpp )
target_include_directories( Base BEFORE PUBLIC
                            src/Input/
                            src/Output/
                            src/NonFloatingPoint/ )
