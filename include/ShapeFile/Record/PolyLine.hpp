#include <cstdio>
#include <cstdint>
#include <vector>

#include <ShapeFile/Record/Record.hpp>
#include <ShapeFile/Record/Point.hpp>

#ifndef _POLYLINE_HPP_
#define _POLYLINE_HPP_

using namespace std;
namespace Records {
    class PolyLine : public Record {
        private:
            int32_t shapeType;
            
            vector<double> boundingBoxMin;
            vector<double> boundingBoxMax;
            
            int32_t numParts;
            int32_t numPoints;

            vector<int32_t> parts;
            vector<Point> points;
        public:
            PolyLine(FILE *shapeFile);
            PolyLine(
                int32_t shapeType,
                vector<vector<double>> boundingBox,
                vector<int32_t> parts,
                vector<Point> points
            );

            vector<double> getBoundingBoxMin();
            vector<double> getBoundingBoxMax();

            int32_t getNumParts();
            int32_t getNumPoints();

            vector<int32_t> getParts();
            vector<Point> getPoints(); 
    };
}

#endif