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
        cout << "Record Number: " << record->getNumber() << "    Record Length: " << record->getLength() << endl;

        vector<double> recordBbMin = record->getBoundingBoxMin();
        cout << "\tBounding Box Min: " << endl << "\t\t(";
        for (double bbPoint : recordBbMin)
        {
            cout << bbPoint << ", ";
        }
        cout << ")" << endl;

        vector<double> recordBbMax = record->getBoundingBoxMax();
        cout << "\tBounding Box Min: " << endl << "\t\t(";
        for (double bbPoint : recordBbMax)
        {
            cout << bbPoint << ", ";
        }
        cout << ")" << endl;

        vector<int32_t> parts = record->getParts();
        cout << "\tParts: " << endl;
        cout << "\t\t[";
        for (int32_t part : parts)
        {
            cout << part << ", ";
        }
        cout << "]" << endl;

        vector<Records::Point> points = record->getPoints();
        cout << "\tPoints: " << endl;
        for (Records::Point point : points)
        {
            cout << "\t\t(" << point.getX() << ", " << point.getY() << ")" << endl;
        }
    }
    cout << endl;

    return EXIT_SUCCESS;
}
