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

    for (Records::Record record : records) {
        cout << "Record Number: " << record.getNumber() << "    Record Length: " << record.getLength() << endl << "\t";
    }
    cout << endl;

    for (size_t i = 0; i < records.size(); i++) {
        Records::Record object = records.at(i);
        
        Records::PolyLine polyLine = reinterpret_cast<Records::PolyLine&>(object);
        for (Records::Point point : polyLine.getPoints()) {
            cout << "\t" << point.getX() << ", " << point.getY() << endl;
        }
    }
    
    return 0;
}
