#include "../../main.h"

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
void point3::makePoint(point3 & setPoint) {
    point[0] = setPoint.getX();
    point[1] = setPoint.getY();
    point[2] = setPoint.getZ();
}

// will reutrn a copy of the point 
point3 point3::getPoint() {
    point3 returnPoint;
    returnPoint.makePoint(point[0], point[1], point[2]);
    return returnPoint; 
}

// will add two points and return
void point3::addPoint(point3 & addPoint1, point3 & addPoint2) {
    point[0] = addPoint1.getX() + addPoint2.getX();
    point[1] = addPoint1.getY() + addPoint2.getY();
    point[2] = addPoint1.getZ() + addPoint2.getZ();
}
void point3::addPoint(point3 & addPoint) {
    point[0] += addPoint.getX();
    point[1] += addPoint.getY();
    point[2] += addPoint.getZ();
}

// subtract points
void point3::subtractPoint(point3 & subPoint1, point3 & subPoint2) {
    point[0] += subPoint1.getX() - subPoint2.getX();
    point[1] += subPoint1.getY() - subPoint2.getY();
    point[2] += subPoint1.getZ() - subPoint2.getZ();
}
void point3::subtractPoint(point3 & subPoint) {
    point[0] = subPoint.getX();
    point[1] = subPoint.getY();
    point[2] = subPoint.getZ();
}

// will multiply point by t
void point3::scalarMultiply(double t) {
    point[0] *= t;
    point[1] *= t;
    point[2] *= t;
}

double point3::getX() const {
    return point[0];
}

double point3::getY() const {
    return point[1];
}

double point3::getZ() const {
    return point[2];
}