#include <string>

using std::string;

namespace Base::OS {

extern const string path_exe;

string& getAbsPath( string relPath );

}