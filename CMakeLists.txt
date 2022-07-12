cmake_minimum_required( VERSION 3.21 )
project( Base )

set( CMAKE_CXX_STANDARD 20 )

add_compile_options( -v )

add_library( Base
             src/CmdLnArgParser/CmdLnArgParser.hpp src/CmdLnArgParser/CmdLnArgParser.cpp
             src/Messenger/Messenger.hpp src/Messenger/Messenger.cpp
             src/Rational/Rational.hpp src/Rational/Rational_constructors.cpp
             src/Rational/Rational_Operator_Equal.cpp
             src/Rational/Rational_Operator_Addition.cpp
             src/Rational/Rational_Output.cpp
             src/Rational/Rational_Conversions.cpp
             src/Rational/Rational_Math.cpp
             src/OS/OS.hpp src/OS/OS.cpp )
target_include_directories( Base BEFORE PUBLIC
                            src/CmdLnArgParser/
                            src/Messenger/
                            src/Rational/
                            src/OS )
