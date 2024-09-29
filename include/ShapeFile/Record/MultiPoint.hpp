#include <cstdint>
#include <cstdio>
#include <vector>

#include <ShapeFile/Record/Point.hpp>
#include <ShapeFile/Record/Record.hpp>

#ifndef _POLYLINE_HPP_
#define _POLYLINE_HPP_

using namespace std;
namespace Records {
    class MultiPoint : public Record
    {
    private:
        int32_t shapeType;

        vector<double> boundingBoxMin;
        vector<double> boundingBoxMax;

        int32_t numPoints;

        vector<Point> points;

    public:
        MultiPoint(FILE* shapeFile);
        ~MultiPoint();

        vector<double> getBoundingBoxMin();
        vector<double> getBoundingBoxMax();

        int32_t getNumPoints();

        vector<Point> getPoints();
    };
} // namespace Records

#endif
