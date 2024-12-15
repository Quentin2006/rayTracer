#include "../../main.h"

ray::ray() {
    orig.makePoint(0,0,0);
    dir.makeVector(0,0,0);
};

void ray::makeRay(point3 & getOrig, vec3 & getDir) {
    orig.makePoint(getOrig);
    dir.makeVector(getDir);

    return;
}

point3 ray::at(double t) {

    // makes a new temeray vector, then sets this new vector to the dir vector
    // then scalary multiplyes it by t
    vec3 scaledVec;
    scaledVec.makeVector(dir);
    scaledVec.scalarMultiply(t);

    point3 pointAtT;
    // adds the scaled dir vector
    pointAtT.makePoint(scaledVec.getX() + orig.getX(), scaledVec.getY() + orig.getY(), scaledVec.getZ() + orig.getZ()); 

    return pointAtT;
}

point3 ray::origin() const {
    return orig;
}
vec3 ray::direction() const {
    return dir;
}

