cmake_minimum_required( VERSION 3.21 )
project( Base )

set( CMAKE_CXX_STANDARD 20 )
set( CMAKE_LIBRARY_OUTPUT_DIRECTORY $ENV{BASE_DIR}/lib )

add_library( Input
             Input/CmdLnArgParser.cpp
             Input/CmdLnArgParser.hpp )
add_library( Output
             Output/Messenger.hpp
             Output/Messenger.cpp )

add_compile_options( -v )