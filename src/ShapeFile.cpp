#include "include/ShapeFile.hpp"
#include "include/Record/Record.hpp"
#include "include/Util.hpp"
#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <iostream>

using namespace std;

ShapeFile::ShapeFile(string filePath) {
    FILE *shapeFile = fopen(filePath, "rb");

    // TODO: Read as big endian.

    int32_t _fileCode;
    size_t err = fread(&_fileCode, ESRI_INTEGER, 1, shapeFile);
    if (err != 1) {
        cerr << "Failed to read file code" << endl;
        exit(EXIT_FAILURE);
    }

    // Skip to next position.
    fseek(shapeFile, 24L, SEEK_SET);

    int32_t _fileLength;
    err = fread(&_fileLength, ESRI_INTEGER, 1, shapeFile);
    if (err != 1) {
        cerr << "Failed to read file length" << endl;
        exit(EXIT_FAILURE);
    }

    int32_t _version;
    err = fread(&_version, ESRI_INTEGER, 1, shapeFile);
    if (err != 1) {
        cerr << "Failed to read version" << endl;
        exit(EXIT_FAILURE);
    }

    int32_t _shapeType;
    err = fread(&_shapeType, ESRI_INTEGER, 1, shapeFile);
    if (err != 1) {
        cerr << "Failed to read shape type" << endl;
        exit(EXIT_FAILURE);
    }
}

ShapeFile::ShapeFile(ShapeType _shapeType,
                     vector<vector<double>> boundingBox,
                     vector<Record> _records) {
    this->shapeType = _shapeType;
    this->boundingBoxMin = boundingBox[0];
    this->boundingBoxMax = boundingBox[1];
    this->records = _records;
}

int32_t ShapeFile::getFileCode() {
    return this->fileCode;
}

int32_t ShapeFile::getLength(bool words) {
    return words ? this->fileLength : this->fileLength*2;
}

int32_t ShapeFile::getLength() {
    return this->getLength(false);
}

int32_t ShapeFile::getVersion() {
    return this->version;
}

ShapeType ShapeFile::getShapeType() {
    return this->shapeType;
}

vector<double> ShapeFile::getBoundingBoxMin() {
    return this->boundingBoxMin;
}

vector<double> ShapeFile::getBoundingBoxMax() {
    return this->boundingBoxMax;
}

vector<Record> ShapeFile::getRecords() {
    return this->records;
}
