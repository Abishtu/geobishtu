#include "include/Record/Record.hpp"
#include "include/Util.hpp"
#include <cstdint>
#include <stdint.h>
#include <string>
#include <vector>

#ifndef _SHAPEFILE_HPP_
#define _SHAPEFILE_HPP_

#define ESRI_INTEGER 4
#define ESRI_DOUBLE 8

using namespace std;


class ShapeFile {
    private:
        // Header Information
        int32_t fileCode;
        int32_t fileLength;
        int32_t version;

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
        int32_t getFileCode();
        int32_t getLength(bool words);
        int32_t getLength();
        int32_t getVersion();
        ShapeType getShapeType();

        vector<double> getBoundingBoxMin();
        vector<double> getBoundingBoxMax();
        vector<Record> getRecords();
};

#endif
