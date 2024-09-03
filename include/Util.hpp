#ifndef _UTIL_HPP_
#define _UTIL_HPP_

enum ShapeType {
    NullShape = 0,
    Point = 1,
    PolyLine = 3,
    Polygon = 8,
    MultiPoint = 11,
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

#endif
