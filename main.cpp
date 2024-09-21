#include <ShapeFile/Record/Point.hpp>
#include <ShapeFile/Record/PolyLine.hpp>
#include <ShapeFile/ShapeFile.hpp>
#include <cstdlib>
#include <iostream>

using namespace std;

int main(int argc, char** argv)
{
    if(argc < 2) {
        cerr << "Please provide file name" << endl;
        exit(EXIT_FAILURE);
    }

    string fileName = string(argv[1]);

    ShapeFile shapeFile = ShapeFile(fileName);

    vector<shared_ptr<Records::Record>> records = shapeFile.getRecords();

    for (shared_ptr<Records::Record> record : records)
    {
        vector<Records::Point> points = record->getPoints();
        for (Records::Point point : points)
        {
            cout << point.getX() << "," << point.getY() << endl;
        }
    }

    return EXIT_SUCCESS;
}
