#include <iostream>
#include <ShapeFile/ShapeFile.hpp>

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

    vector<Record> records = shapeFile.getRecords();

    cout << "Records: " << endl << "\t";

    for (Record record : records) {
        cout << "Record Number: " << record.getNumber() << "    Record Length: " << record.getLength() << endl << "\t";
    }
    cout << endl;
    
    return 0;
}
