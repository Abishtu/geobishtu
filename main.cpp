#include <ShapeFile/Record/Point.hpp>
#include <ShapeFile/Record/PolyLine.hpp>
#include <ShapeFile/ShapeFile.hpp>
#include <cstdlib>
#include <iostream>

using namespace std;

int main(int argc, char** argv) {
    if(argc < 2) {
        cerr << "Please provide file name" << endl;
        exit(EXIT_FAILURE);
    }

    string fileName = string(argv[1]);
    int scale = atoi(argv[2]);

    ShapeFile shapeFile = ShapeFile(fileName);

    vector<double> boundingBoxMax = shapeFile.getBoundingBoxMax();
    vector<double> boundingBoxMin = shapeFile.getBoundingBoxMin();
    double horizonatalOffset = boundingBoxMax[0] - boundingBoxMin[0];
    double verticalOffset = boundingBoxMax[1] - boundingBoxMin[1];

    vector<shared_ptr<Records::Record>> records = shapeFile.getRecords();

    for (shared_ptr<Records::Record> record : records)
    {
        vector<Records::Point> points = record->getPoints();
        for (size_t i = 0; i < points.size()-1; i++) {
            Records::Point point1 = points[i];
            Records::Point point2 = points[++i];

            cout << "line:";
            cout << ((boundingBoxMax[0] - point1.getX()) - horizonatalOffset/2) * -scale << "," << ((boundingBoxMax[1] - point1.getY()) - verticalOffset/2) * -scale;
            cout << ";";
            cout << ((boundingBoxMax[0] - point2.getX()) - horizonatalOffset/2) * -scale << "," << ((boundingBoxMax[1] - point2.getY()) - verticalOffset/2) * -scale << endl;
        }
    }

    return EXIT_SUCCESS;
}
