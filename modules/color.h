#ifndef COLOR_H
#define COLOR_H

#include "vec3.h"

// will store the color as a vector of doubles [0, 1],
// that vector is then passed into the write_color function
using color = vec3;

// this will then convert this double to a value [0, 255]
// then cout that new value
void write_color(std::ostream& out, const color& pixel_color) {
    auto r = pixel_color.x();
    auto g = pixel_color.y();
    auto b = pixel_color.z();

    // Translate the [0,1] component values to the byte range [0,255].
    int rbyte = int(255.999 * r);
    int gbyte = int(255.999 * g);
    int bbyte = int(255.999 * b);

    // Write out the pixel color components.
    out << rbyte << ' ' << gbyte << ' ' << bbyte << '\n';
}

#endif