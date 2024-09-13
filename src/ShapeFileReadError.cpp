#include <iostream>

#include <ShapeFile/Exceptions/ShapeFileReadError.hpp>

using namespace ShapeFileExceptions;

ReadError::ReadError(const string& msg) : m_msg(msg) {
    // ....
}

ReadError::~ReadError() {
    //....
}

const char* ReadError::what() const throw() {
    return m_msg.c_str();
}