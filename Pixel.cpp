//
// Created by isaac on 2/17/19.
//

#include <sstream>
#include "Pixel.h"

string Pixel::toString() {
    stringstream ss;

    ss << red << " " << green << " " << blue << endl;

    return ss.str();
}

int Pixel::getRed() const {
    return red;
}

int Pixel::getGreen() const {
    return green;
}

int Pixel::getBlue() const {
    return blue;
}
