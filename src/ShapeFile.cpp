#include "include/ShapeFile.hpp"
#include "include/Record/Record.hpp"
#include "include/Util.hpp"
#include <cstdint>
#include <fstream>

using namespace std;

ShapeFile::ShapeFile(string filePath) {
    ifstream shapeFile{ filePath, ios::binary };
}

ShapeFile::ShapeFile(ShapeType _shapeType,
                     vector<vector<double>> boundingBox,
                     vector<Record> _records) {
    this->shapeType = _shapeType;
    this->boundingBoxMin = boundingBox[0];
    this->boundingBoxMax = boundingBox[1];
    this->records = _records;
}

uint32_t ShapeFile::getFileCode() {
    return this->fileCode;
}

uint32_t ShapeFile::getLength(bool words) {
    return words ? this->fileLength : this->fileLength*2;
}

uint32_t ShapeFile::getLength() {
    return this->getLength(false);
}

uint32_t ShapeFile::getVersion() {
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
