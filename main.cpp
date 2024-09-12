#include <iostream>
#include <ShapeFile/ShapeFile.hpp>
#include <ShapeFile/Record/Point.hpp>
#include <ShapeFile/Record/PolyLine.hpp>

using namespace std;

int main()
{    
    ShapeFile shapeFile = ShapeFile("data/hotosm_aus_railways_lines_shp.shp");

    cout << "File Code: " << shapeFile.getFileCode() << "    File Length: " << shapeFile.getLength(true) << endl;
    cout << "Version: " << shapeFile.getVersion() << "    Shape Type: " << shapeFile.getShapeType() << endl;
    
    vector<double> bbMin = shapeFile.getBoundingBoxMin();

    cout << "Bounding Box Min: " << endl << "\t(";

    for (double bbPoint : bbMin) {
        cout << bbPoint << ", ";
    }

    cout << ")" << endl;

    vector<double> bbMax = shapeFile.getBoundingBoxMax();

    cout << "Bounding Box Max: " << endl << "\t(";

    for (double bbPoint : bbMax) {
        cout << bbPoint << ", ";
    }

    cout << ")" << endl;

    auto records = shapeFile.getRecords();

    cout << "Records: " << endl << "\t";

    for (shared_ptr<Records::Record> record : records) {
        cout << "Record Number: " << record->getNumber() << "    Record Length: " << record->getLength() << endl;
        
        vector<double> recordBbMin = record->getBoundingBoxMin();
        cout << "\tBounding Box Min: " << endl << "\t\t(";
        for (double bbPoint : recordBbMin) {
            cout << bbPoint << ", ";
        }
        cout << ")" << endl;

        vector<double> recordBbMax = record->getBoundingBoxMax();
        cout << "\tBounding Box Min: " << endl << "\t\t(";
        for (double bbPoint : recordBbMax) {
            cout << bbPoint << ", ";
        }
        cout << ")" << endl;

        vector<Records::Point> points = record->getPoints();
        cout << "\tPoints: " << endl;
        for(Records::Point point : points) {
            cout << "\t\t(" << point.getX() << ", " << point.getY() << ")" << endl;
        }
    }
    cout << endl;
    
    return 0;
}
