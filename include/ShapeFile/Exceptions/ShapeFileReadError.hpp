#include <iostream>

#ifndef _SHAPEFILEREADERROR_HPP_
#define _SHAPEFILEREADERROR_HPP_

using namespace std;

namespace ShapeFileExceptions {
    class ReadError : public exception {
        public:
            const string m_msg;

            ReadError(const string& msg);

            ~ReadError();
            
            virtual const char* what() const throw();
    };
}

#endif