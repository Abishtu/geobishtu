#include <cstdint>
#include <cstdio>

#ifndef _RECORD_HPP_
#define _RECORD_HPP_

class Record {
    protected:
        // Record Header
        int32_t number;
        int32_t length;

        long readHeader(FILE *shapeFile);
    public:
        Record(FILE *shapeFile);

        int32_t getNumber();
        int32_t getLength();
};

#endif
