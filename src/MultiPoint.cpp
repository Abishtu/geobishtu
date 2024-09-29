#include <iostream>

#include <ShapeFile/Exceptions/ShapeFileReadError.hpp>
#include <ShapeFile/Record/MultiPoint.hpp>
#include <Util.hpp>

using namespace std;
using namespace Records;

MultiPoint::~MultiPoint() {

}

MultiPoint::MultiPoint(FILE *shapeFile) : Record(shapeFile) {
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

    int32_t _numPoints;
    err = fread(&_numPoints, ESRI_INTEGER, 1, shapeFile);
    if (err != 1) {
        throw (ShapeFileExceptions::ReadError("File read error!"));
    }
    this->numPoints = _numPoints;

    for (int pointCount = 0; pointCount < this->numPoints; pointCount++) {
        Point point = Point(shapeFile);
        // cout << point.getX() << ", " << point.getY() << endl;
        this->points.push_back(point);
    }
}

vector<double> MultiPoint::getBoundingBoxMin() {
    return this->boundingBoxMin;
}

vector<double> MultiPoint::getBoundingBoxMax() {
    return this->boundingBoxMax;
}

int32_t MultiPoint::getNumPoints() {
    return this->numPoints;
}

vector<Point> MultiPoint::getPoints() {
    return this->points;
}