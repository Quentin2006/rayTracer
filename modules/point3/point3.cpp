#include "point3.h"

// initlzies point to origin 
point3::point3() {
    point[0] = 0;
    point[1] = 0;
    point[2] = 0;
}

// will create the vector and store in the x, y and z component
void point3::makePoint(double x, double y, double z) {
    point[0] = x;
    point[1] = y;
    point[2] = z;
}

double point3::getX() {
    return point[0];
}

double point3::getY() {
    return point[1];
}

double point3::getZ() {
    return point[2];
}