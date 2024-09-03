#include "include/Record/Record.hpp"
#include "include/Util.hpp"
#include <cstdint>
#include <stdint.h>
#include <string>
#include <vector>

#ifndef _SHAPEFILE_HPP_
#define _SHAPEFILE_HPP_

using namespace std;

class ShapeFile {
    private:
        // Header Information
        uint32_t fileCode;
        uint32_t fileLength;
        uint32_t version;

        ShapeType shapeType;

        vector<double> boundingBoxMax;
        vector<double> boundingBoxMin;

        vector<Record> records;
    public:
        // Constructors
        ShapeFile(string filePath);
        ShapeFile(
            ShapeType _shapeType,
            vector<vector<double>> boundingBox,
            vector<Record> _records
        );

        // Getters
        uint32_t getFileCode();
        uint32_t getLength(bool words);
        uint32_t getLength();
        uint32_t getVersion();
        ShapeType getShapeType();

        vector<double> getBoundingBoxMin();
        vector<double> getBoundingBoxMax();
        vector<Record> getRecords();
};

#endif
