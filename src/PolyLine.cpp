#include <iostream>

#include <ShapeFile/Exceptions/ShapeFileReadError.hpp>
#include <ShapeFile/Record/PolyLine.hpp>
#include <Util.hpp>

using namespace std;
using namespace Records;

PolyLine::~PolyLine() {

}

PolyLine::PolyLine(FILE *shapeFile) : Record(shapeFile) {
    // readHeader(shapeFile);
    int32_t _shapeType;
    size_t err = fread(&_shapeType, ESRI_INTEGER, 1, shapeFile);
    if (err != 1) {
        throw (ShapeFileExceptions::ReadError("File read error!"));
    }
    this->shapeType = _shapeType;

    vector<double> _boundingBoxMin;
    for (int bbMinCount = 0; bbMinCount < 2; bbMinCount++) {
        double boundingBox;
        err = fread(&boundingBox, ESRI_DOUBLE, 1, shapeFile);
        _boundingBoxMin.push_back(boundingBox);
    }
    this->boundingBoxMin = _boundingBoxMin;

    vector<double> _boundingBoxMax;
    for (int bbMinCount = 0; bbMinCount < 2; bbMinCount++) {
        double boundingBox;
        err = fread(&boundingBox, ESRI_DOUBLE, 1, shapeFile);
        _boundingBoxMax.push_back(boundingBox);
    }
    this->boundingBoxMax = _boundingBoxMax;

    int32_t _numParts;
    err = fread(&_numParts, ESRI_INTEGER, 1, shapeFile);
    if (err != 1) {
        throw (ShapeFileExceptions::ReadError("File read error!"));
    }
    this->numParts = _numParts;

    int32_t _numPoints;
    err = fread(&_numPoints, ESRI_INTEGER, 1, shapeFile);
    if (err != 1) {
        throw (ShapeFileExceptions::ReadError("File read error!"));
    }
    this->numPoints = _numPoints;

    for (int partCount = 0; partCount < this->numParts; partCount++) {
        int32_t part;
        err = fread(&part, ESRI_INTEGER, 1, shapeFile);
        if (err != 1) {
            throw (ShapeFileExceptions::ReadError("File read error!"));
        }
        this->parts.push_back(part);
    }

    for (int pointCount = 0; pointCount < this->numPoints; pointCount++) {
        Point point = Point(shapeFile);
        // cout << point.getX() << ", " << point.getY() << endl;
        this->points.push_back(point);
    }
}

vector<double> PolyLine::getBoundingBoxMin() {
    return this->boundingBoxMin;
}

vector<double> PolyLine::getBoundingBoxMax() {
    return this->boundingBoxMax;
}

int32_t PolyLine::getNumParts() {
    return this->numParts;
}

int32_t PolyLine::getNumPoints() {
    return this->numPoints;
}

vector<int32_t> PolyLine::getParts() {
    return this->parts;
}

vector<Point> PolyLine::getPoints() {
    return this->points;
}