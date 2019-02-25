//
// Created by isaac on 2/17/19.
//

#ifndef COMPLEX_BOKEH_BLURS_IMAGEPROCESSOR_H
#define COMPLEX_BOKEH_BLURS_IMAGEPROCESSOR_H


#include "Image.h"

class ImageProcessor {
public:
    ImageProcessor(int argc, char* argv[]);
    Image blur(Image& i);

private:
    double** kernelX;
    double** kernelY;
    int kernelSize;
    string blurtype;
    void meanKernel();
    void gaussKernel(double sd);
    void sobelKernel();
    void processKernelX(Image& in, Image& out, int kernelNum);
    void processKernelY(Image& in, Image& out, int kernelNum);
    void grayscale(Image& in, Image& out);
    Image simpleBlur(Image& i, int kernelNum);
    Image complexBlur(Image& i);
    Image sobelBlur(Image& i);
};


#endif //COMPLEX_BOKEH_BLURS_IMAGEPROCESSOR_H
