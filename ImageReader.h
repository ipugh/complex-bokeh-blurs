//
// Created by isaac on 2/17/19.
//

#ifndef COMPLEX_BOKEH_BLURS_IMAGEREADER_H
#define COMPLEX_BOKEH_BLURS_IMAGEREADER_H


#include "Image.h"
#include <fstream>

using namespace std;
class ImageReader {
public:
    ImageReader() {};
    ImageReader(Image& image, ifstream& in);
private:
    int parseInteger(string s);
    string nextToken(ifstream& is);
};


#endif //COMPLEX_BOKEH_BLURS_IMAGEREADER_H
