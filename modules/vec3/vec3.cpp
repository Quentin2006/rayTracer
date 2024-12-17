#include "vec3.h"
#include "../point3/point3.h"
#include <cmath>

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
void vec3::makeVector(vec3 & setVec) {
    vector[0] = setVec.getX();
    vector[1] = setVec.getY();
    vector[2] = setVec.getZ();
}
// will reutrn a copy of the point 
vec3 vec3::getVec() {
    vec3 returnVec;
    returnVec.makeVector(vector[0], vector[1], vector[2]);
    return returnVec;
}

// will add two vectors and return
void vec3::addVector(vec3 & addVec1, vec3 & addVec2) {
    vector[0] = addVec1.getX() + addVec2.getX();
    vector[1] = addVec1.getY() + addVec2.getY();
    vector[2] = addVec1.getZ() + addVec2.getZ();
}
void vec3::addVector(vec3 & addVec) {
    vector[0] += addVec.getX();
    vector[1] += addVec.getY();
    vector[2] += addVec.getZ();
}
void vec3::addVector(double x, double y, double z) {
    vector[0] += x;
    vector[1] += y;
    vector[2] += z;
}

// subtract points
void vec3::subtractVector(vec3 & subVec1, vec3 & subVec2) {
    vector[0] = subVec1.getX() - subVec2.getX();
    vector[1] = subVec1.getY() - subVec2.getY();
    vector[2] = subVec1.getZ() - subVec2.getZ();
}
void vec3::subtractVector(vec3 & subVec) {
    vector[0] -= subVec.getX();
    vector[1] -= subVec.getY();
    vector[2] -= subVec.getZ();
}

// will scalar multiply vector
void vec3::scalarMultiply(double scalar) {
    vector[0] *= scalar;
    vector[1] *= scalar;
    vector[2] *= scalar;
}

// will normize the vectorA
void vec3::normalize() {
    double magnitude {sqrt(pow(vector[0], 2) + pow(vector[1], 2) + pow(vector[2], 2))};
    scalarMultiply(1/magnitude);
}

double vec3::getX() const {
    return vector[0];
}

double vec3::getY() const {
    return vector[1];
}

double vec3::getZ() const {
    return vector[2];
}

double vec3::dot(vec3 dotVector) {
    double dotProduct{0};
    dotProduct += vector[0] * dotVector.getX();
    dotProduct += vector[1] * dotVector.getY();
    dotProduct += vector[2] * dotVector.getZ();

    return dotProduct;
}
double vec3::dot(point3 dotVector) {
    double dotProduct{0};
    dotProduct += vector[0] * dotVector.getX();
    dotProduct += vector[1] * dotVector.getY();
    dotProduct += vector[2] * dotVector.getZ();

    return dotProduct;
}

double vec3::dot(double x, double y, double z) {
    double dotProduct{0};
    dotProduct += vector[0] * x;
    dotProduct += vector[1] * y;
    dotProduct += vector[2] * z;

    return dotProduct;
}