#include "main.h"

int main() {

    // IMAGE PROPERTIES

    // calculates image width and height using a 16:9 aspect ratio
    double aspectRatio {16.0/9.0};
    int imgWidth {400};
    int imgHeight {int(imgWidth/aspectRatio)};
    

    // were using a .ppm file for the image so the following are required
    cout << "P3" << endl
         << imgWidth << ' ' << imgHeight << endl
         << "255" << endl;

    // RENDER
    for (double col {0}; col < imgHeight; ++col) {
        clog << '\r' << 100 - (col / imgHeight * 100) << "% remaning" << flush;
        for (double row {0}; row < imgWidth; ++row) {
            double r {row / imgWidth};
            double g {(imgWidth-row) / imgWidth};
            double b {col / imgHeight};
            writeColor(r, g, b);
        }
    }

    clog << "\rDone.                     \n";

    return 0;
}