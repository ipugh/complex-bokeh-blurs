//
// Created by isaac on 2/17/19.
//

#ifndef COMPLEX_BOKEH_BLURS_PIXEL_H
#define COMPLEX_BOKEH_BLURS_PIXEL_H

#include <iostream>

using namespace std;

class Pixel {
public:
    Pixel() {};
    Pixel(int red, int green, int blue) : red(red), green(green), blue(blue) {};
    string toString();
    int getRed() const;
    int getGreen() const;
    int getBlue() const;

private:
    int red;
    int green;
    int blue;
};


#endif //COMPLEX_BOKEH_BLURS_PIXEL_H
