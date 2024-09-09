#include <ShapeFile/Record/Point.hpp>
#include <Util.hpp>

using namespace std;
using namespace Records;
Point::Point(FILE *shapeFile) {
    double _x;
    fread(&_x, ESRI_DOUBLE, 1, shapeFile);

    double _y;
    fread(&_y, ESRI_DOUBLE, 1, shapeFile);

    this->x = _x;
    this->y = _y;
}

double Point::getX() {
    return this->x;
}

double Point::getY() {
    return this->y;
}

vector<double> Point::getPoint() {
    return vector<double>{this->x, this->y};
}