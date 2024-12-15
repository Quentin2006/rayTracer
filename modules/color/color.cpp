#include "../../main.h"

// function to let us write colors
// will take in a double [0-1] and translate that to and int 0-255 and cout info
void writeColor(double r, double g, double b) {

    int scaledR = int(255.999 * r);
    int scaledB = int(255.999 * g);
    int scaledG = int(255.999 * b);

    cout << scaledR  << ' ' << scaledG << ' ' << scaledB << '\n';
}
