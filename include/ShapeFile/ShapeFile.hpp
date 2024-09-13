#include <cstdint>
#include <stdint.h>
#include <string>
#include <vector>
#include <memory>

#include <ShapeFile/Record/Record.hpp>
#include <Util.hpp>

#ifndef _SHAPEFILE_HPP_
#define _SHAPEFILE_HPP_

using namespace std;

enum ShapeType {
    NullShape = 0,
    Point = 1,
    PolyLine = 3,
    Polygon = 5,
    MultiPoint = 8,
    PointZ = 11,
    PolyLineZ = 13,
    PolygonZ = 15,
    MultiPointZ = 18,
    PointM = 21,
    PolyLineM = 23,
    PolygonM = 25,
    MultiPointM = 28,
    MultiPatch = 31,
};

class ShapeFile {
    private:
        // Header Information : 100 bytes
        int32_t fileCode;
        int32_t fileLength;
        int32_t version;

        ShapeType shapeType;

        vector<double> boundingBoxMax;
        vector<double> boundingBoxMin;

        // Content : len - 100
        vector<shared_ptr<Records::Record>> records{};
    public:
        // Constructors
        ShapeFile(string filePath);

        // Getters
        int32_t getFileCode();
        int32_t getLength(bool words);
        int32_t getLength();
        int32_t getVersion();
        ShapeType getShapeType();

        vector<double> getBoundingBoxMin();
        vector<double> getBoundingBoxMax();
        vector<shared_ptr<Records::Record>> getRecords();
};

#endif
