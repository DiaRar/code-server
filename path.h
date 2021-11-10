#include <string>
#include <stdexcept>
#include <direct.h>
#pragma once
std::string get_working_path()
{
    char temp [ 60 ];

    if ( getcwd(temp, 60) != 0) {
        std::string s = temp;
        return s;
    }
    int error = errno;

    switch ( error ) {
        // EINVAL can't happen - size argument > 0

        // PATH_MAX includes the terminating nul, 
        // so ERANGE should not be returned

        case EACCES:
            throw std::runtime_error("Access denied");

        case ENOMEM:
            // I'm not sure whether this can happen or not 
            throw std::runtime_error("Insufficient storage");

        default: {
            throw std::runtime_error("Unknown Error");
        }
    }
}