#include <cstdint>
#include <cstdio>

#include <ShapeFile/Record/Point.hpp>

#ifndef _RECORD_HPP_
#define _RECORD_HPP_
namespace Records {
    class Record {
    protected:
        // Record Header
        int32_t number;
        int32_t length;

        long readHeader(FILE *shapeFile);
    public:
        Record(FILE *shapefile);
        virtual ~Record();

        int32_t getNumber();
        int32_t getLength();

        // Sub class methods;
        virtual vector<double> getBoundingBoxMin();
        virtual vector<double> getBoundingBoxMax();

        virtual int32_t getNumParts();
        virtual int32_t getNumPoints();

        virtual vector<int32_t> getParts();
        virtual vector<Point> getPoints();
    };
}

#endif
