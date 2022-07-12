#include "OS.hpp"

namespace Base::OS { 

const string path_exe = getenv( "PWD" ); 

string& getAbsPath( string path_rel )
{
    if( path_rel[ 0 ] == '.' && path_rel[ 1 ] == '.' && path_rel[ 2 ] == '/' ) {
        string path_exe_temp = path_exe + '/';
        while( path_rel[ 0 ] == '.' && path_rel[ 1 ] == '.' && path_rel[ 2 ] == '/' ) { // If path_rel is relative
            path_rel.erase( 0, 3 );
            path_exe_temp.pop_back();
            while( path_exe_temp.back() != '/' )
                path_exe_temp.pop_back();
        }
        path_rel = path_exe_temp + path_rel;
    } else if ( path_rel[ 0 ] == '.' &&  path_rel[ 1 ] == '/' ) {
        path_rel.erase( 0, 2 );
        path_rel = path_exe + '/' + path_rel;
    } else if ( path_rel[ 0 ] == '.' ) {
        path_rel = path_exe;
    }
    return path_rel;
}

}