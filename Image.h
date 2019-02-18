//
// Created by isaac on 2/17/19.
//

#ifndef COMPLEX_BOKEH_BLURS_IMAGE_H
#define COMPLEX_BOKEH_BLURS_IMAGE_H


#include "Pixel.h"
#include <iostream>

using namespace std;

class Image {
public:
    Image() {};
    Image(int width, int height, int max_luminance);
    void setPixel(int width, int height, int red, int green, int blue);
    Pixel pixelAt(int width, int height);
    string toString();
    int getWidth() const;
    int getHeight() const;
    int getMaxLuminance() const;

private:
    int width;
    int height;
    int max_luminance;
    Pixel** pixels;
};


#endif //COMPLEX_BOKEH_BLURS_IMAGE_H
