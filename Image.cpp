//
// Created by isaac on 2/17/19.
//

#include <sstream>
#include "Image.h"

Image::Image(int width, int height, int max_luminance) : width(width), height(height), max_luminance(max_luminance) {
    pixels = new Pixel*[height];
    for (int i = 0; i < height; i++) {
        pixels[i] = new Pixel[width];
    }
}

void Image::setPixel(int width, int height, int red, int green, int blue) {
    pixels[height][width] = Pixel(red, green, blue);
}

Pixel Image::pixelAt(int width, int height) {
    return pixels[height][width];
}

string Image::toString() {
    stringstream ss;

    ss << "P3" << endl;
    ss << width << " " << height << endl;
    ss << max_luminance << endl;

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            ss << pixelAt(j, i).toString();
        }
    }

    return ss.str();
}
