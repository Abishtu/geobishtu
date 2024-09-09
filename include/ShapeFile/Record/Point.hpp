#include <cstdint>
#include <cstdio>
#include <vector>

#ifndef _POINT_HPP_
#define _POINT_HPP_

using namespace std;

namespace Records {
    class Point {
        private:
            double x;
            double y;
        public:
            Point(FILE *shapeFile);
            Point(double x, double y);

            vector<double> getPoint();
            double getX();
            double getY();
    };
}
#endif