#include <iostream>
#include <fstream>
#include "Image.h"
#include "ImageReader.h"

using namespace std;

int main(int argc, char* argv[]) {
    // argc should contain the input file, output file, and blur type
    // argv[1] is input file
    // the input file should be in a plain .ppm format (adding a parser for a raw .ppm would be nice and probably not too hard)
    // http://netpbm.sourceforge.net/doc/ppm.html
    ifstream input = ifstream(argv[1]);

    Image in;
    ImageReader r;
    try {
        r = ImageReader(in, input);
    } catch (string& s) {
        cout << s << endl;
        return 1;
    }

    ofstream output = ofstream(argv[2]);
    output << in.toString();
}