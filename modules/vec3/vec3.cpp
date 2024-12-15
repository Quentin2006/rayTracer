#include "vec3.h"

// initlzies vector to zero vector
vec3::vec3() {
    vector[0] = 0;
    vector[1] = 0;
    vector[2] = 0;
}

// will create the vector and store in the x, y and z component
void vec3::makeVector(double x, double y, double z) {
    vector[0] = x;
    vector[1] = y;
    vector[2] = z;
}

void vec3::vectorAdd(vec3 & addVec) {
    vector[0] += addVec.vector[0];
    vector[1] += addVec.vector[1];
    vector[2] += addVec.vector[2];
}

void vec3::scalarMultiply(double scalar) {
    vector[0] *= scalar;
    vector[1] *= scalar;
    vector[2] *= scalar;
}

double vec3::getX() {
    return vector[0];
}

double vec3::getY() {
    return vector[1];
}

double vec3::getZ() {
    return vector[2];
}