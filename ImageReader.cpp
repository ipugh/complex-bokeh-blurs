//
// Created by isaac on 2/17/19.
//

#include "ImageReader.h"
#include <iostream>

ImageReader::ImageReader(Image& image, ifstream &in) {
    // take in input from file and put it into image, here is where errors can be thrown for parsing
    // i.e. throw "invalid number of pixels"

    if (nextToken(in) != "P3") {
        throw ("Not prepared for file type");
    }

    int width = parseInteger(nextToken(in));
    int height = parseInteger(nextToken(in));
    int max_luminance = parseInteger(nextToken(in));

    image = Image(width, height, max_luminance);

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            int red = parseInteger(nextToken(in));
            int green = parseInteger(nextToken(in));
            int blue = parseInteger(nextToken(in));
            image.setPixel(j, i, red, green, blue);
        }
    }
}

int ImageReader::parseInteger(string s) {
        return stoi(s);
}

string ImageReader::nextToken(ifstream& is) {
    string token;
    while (is >> token) {
        if (token.at(0) != '#') {
            return token;
        } else {
            getline(is, token);
        }
    }
}