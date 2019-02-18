//
// Created by isaac on 2/17/19.
//

#include "ImageProcessor.h"
#include <cmath>

using namespace std;

ImageProcessor::ImageProcessor(int argc, char **argv) {
    // figure out arguments after index 3
    blurtype = argv[3];

    kernelSize = 21;
    if (argc > 4) {
        kernelSize = (stoi(argv[4]) * 2) + 1;
    }

    kernelX = new double[kernelSize];
    kernelY = new double[kernelSize];

    if (blurtype == "mean") {
        // Creates mean kernel
        meanKernel();
    } else if (blurtype == "gauss") {
        // Creates gaussian kernel
        gaussKernel(stod(argv[5]));
    }
}

void ImageProcessor::meanKernel() {
    for (int i = 0; i < kernelSize; i++) {
        kernelX[i] = 1;
        kernelY[i] = 1;
    }
}

void ImageProcessor::gaussKernel(double sd) {
    for (int i = 0; i < kernelSize/2; i++) {
        double kernelValue = (1/sqrt(2*M_PI*pow(sd,2)))*pow(M_E,-(pow(i, 2)/(2*pow(sd, 2))));
        if (i == 0) {
            kernelX[kernelSize/2] = kernelValue;
            kernelY[kernelSize/2] = kernelValue;
        } else {
            kernelX[kernelSize/2 + i] = kernelValue;
            kernelY[kernelSize/2 + i] = kernelValue;
            kernelX[kernelSize/2 - i] = kernelValue;
            kernelY[kernelSize/2 - i] = kernelValue;
        }
    }
}

Image ImageProcessor::blur(Image& i) {
    //first pass
    Image f = Image(i.getWidth(), i.getHeight(), i.getMaxLuminance());
    processKernelX(i, f);

    //second pass
    Image s = Image(i.getWidth(), i.getHeight(), i.getMaxLuminance());
    processKernelY(f, s);
    return s;
}

void ImageProcessor::processKernelX(Image& in, Image& out) {
    // run kernel X on image in to produce image out
    int width = in.getWidth();
    int height = in.getHeight();
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            double kernelSum = 0;
            int redSum = 0;
            int greenSum = 0;
            int blueSum = 0;
            for (int k = -(kernelSize/2); k <= (kernelSize/2); k++) {
                if (!(j + k < 0 || j + k > in.getWidth()-1)) {
                    double kernelValue = kernelX[k + (kernelSize/2)];
                    Pixel p = in.pixelAt(j + k, i);
                    redSum += (int)(p.getRed() * kernelValue);
                    greenSum += (int)(p.getGreen() * kernelValue);
                    blueSum += (int)(p.getBlue() * kernelValue);
                    kernelSum += kernelValue;
                }
            }
            out.setPixel(j, i, (int)(redSum/kernelSum), (int)(greenSum/kernelSum), (int)(blueSum/kernelSum));
        }
    }
}

void ImageProcessor::processKernelY(Image& in, Image& out) {
    // run kernel X on image in to produce image out
    int width = in.getWidth();
    int height = in.getHeight();
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            double kernelSum = 0;
            int redSum = 0;
            int greenSum = 0;
            int blueSum = 0;
            for (int k = -(kernelSize/2); k <= (kernelSize/2); k++) {
                if (!(i + k < 0 || i + k > in.getHeight()-1)) {
                    double kernelValue = kernelX[k + (kernelSize/2)];
                    Pixel p = in.pixelAt(j, i+k);
                    redSum += (int)(p.getRed() * kernelValue);
                    greenSum += (int)(p.getGreen() * kernelValue);
                    blueSum += (int)(p.getBlue() * kernelValue);
                    kernelSum += kernelValue;
                }
            }
            out.setPixel(j, i, (int)(redSum/kernelSum), (int)(greenSum/kernelSum), (int)(blueSum/kernelSum));
        }
    }
}
