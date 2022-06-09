//
// Created by Noah Everett on 6/4/22.
//

#ifndef BASE_VERBOSITY_HPP
#define BASE_VERBOSITY_HPP

const char* k_vDebug   = "DEBUG";
const char* k_vInfo    = "INFO";
const char* k_vWarning = "WARNING";
const char* k_vError   = "ERROR";
const char* k_vFatal   = "FATAL";
const int  k_maxLenVerbosity = 8; // Length of longest verbosity option

const int k_vDebug_int   = 0;
const int k_vInfo_int    = 1;
const int k_vWarning_int = 3;
const int k_vError_int   = 4;
const int k_vFatal_int   = 5;

#endif //BASE_VERBOSITY_HPP
