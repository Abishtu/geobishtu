#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <iostream>

#include <ShapeFile/ShapeFile.hpp>
#include <ShapeFile/Record/Record.hpp>
#include <Util.hpp>

using namespace std;

ShapeFile::ShapeFile(string filePath) {
    FILE *shapeFile = fopen(filePath.c_str(), "rb");
    if (shapeFile == NULL) {
        cerr << "Failed to read file" << endl;
        exit(EXIT_FAILURE);
    }

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

    this->fileCode = BIG_TO_LITTLE(_fileCode);
    this->fileLength = BIG_TO_LITTLE(_fileLength);

    int32_t _version;
    err = fread(&_version, ESRI_INTEGER, 1, shapeFile);
    if (err != 1) {
        cerr << "Failed to read version" << endl;
        exit(EXIT_FAILURE);
    }
    this->version = _version;

    int32_t _shapeType;
    err = fread(&_shapeType, ESRI_INTEGER, 1, shapeFile);
    if (err != 1) {
        cerr << "Failed to read shape type" << endl;
        exit(EXIT_FAILURE);
    }
    this->shapeType = (ShapeType) _shapeType;

    double bbMinXY[2];
    err = fread(&bbMinXY, ESRI_DOUBLE, 2, shapeFile);
    this->boundingBoxMin.push_back(bbMinXY[0]);
    this->boundingBoxMin.push_back(bbMinXY[1]);

    double bbMaxXY[2];
    err = fread(&bbMaxXY, ESRI_DOUBLE, 2, shapeFile);
    this->boundingBoxMax.push_back(bbMaxXY[0]);
    this->boundingBoxMax.push_back(bbMaxXY[1]);

    double bbZmin;
    err = fread(&bbZmin, ESRI_DOUBLE, 1, shapeFile);
    this->boundingBoxMin.push_back(bbZmin);

    double bbZmax;
    err = fread(&bbZmax, ESRI_DOUBLE, 1, shapeFile);
    this->boundingBoxMax.push_back(bbZmax);

    double bbMmin;
    err = fread(&bbMmin, ESRI_DOUBLE, 1, shapeFile);
    this->boundingBoxMin.push_back(bbMmin);

    double bbMmax;
    err = fread(&bbMmax, ESRI_DOUBLE, 1, shapeFile);
    this->boundingBoxMax.push_back(bbMmax);
    
    // int32_t contentLength = this->getLength() - ((int32_t)100);

    this->records.push_back(Record(shapeFile));
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
