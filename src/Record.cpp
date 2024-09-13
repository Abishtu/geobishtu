#include <cstdint>
#include <cstdlib>
#include <iostream>

#include <ShapeFile/Exceptions/ShapeFileReadError.hpp>
#include <ShapeFile/Record/Record.hpp>
#include <Util.hpp>

using namespace std;
using namespace Records;

Record::Record(FILE *shapeFile) {
    readHeader(shapeFile);
}

Record::~Record() {

}

long Record::readHeader(FILE *shapeFile) {
    int32_t _number;
    size_t err = fread(&_number, ESRI_INTEGER, 1, shapeFile);
    if (err != 1) {
        throw (ShapeFileExceptions::ReadError("File read error!"));
    }
    this->number = BIG_TO_LITTLE(_number);

    int32_t _length;
    err = fread(&_length, ESRI_INTEGER, 1, shapeFile);
    if (err != 1) {
        throw (ShapeFileExceptions::ReadError("File read error!"));
    }
    this->length = BIG_TO_LITTLE(_length);

    return ftell(shapeFile);
}

int32_t Record::getLength() {
    return this->length;
}

int32_t Record::getNumber() {
    return this->number;
}

vector<double> Record::getBoundingBoxMax() {
    return vector<double>{};
}

vector<double> Record::getBoundingBoxMin() {
    return vector<double>{};
}

int32_t Record::getNumParts() {
    return 0;
}

int32_t Record::getNumPoints() {
    return 0;
}

vector<int32_t> Record::getParts() {
    return vector<int32_t>{};
}

vector<Point> Record::getPoints() {
    return vector<Point>{};
}