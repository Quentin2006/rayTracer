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
        for (double row {0}; row < imgWidth; ++row) {
            // these will be the value for one pixel represented as an int 0 - 255, will make a gree to red gradiant right to left,
            // with a blue to black gradiant from bottem to top
            int r {int(row / imgWidth * 255.999)};
            int g {int((imgWidth-row) / imgWidth * 255.999)};
            int b {int(col / imgHeight * 255.999)};

            cout << r  << ' ' << g << ' ' << b << '\n';
        }

    }

    return 0;
}