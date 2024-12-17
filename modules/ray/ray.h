#ifndef RAY_H
#define RAY_H

#include "../point3/point3.h"
#include "../vec3/vec3.h"

// this class will store the data for a ray,
// REMINDER, a ray is just a point and a scalar multiple of a vector in the.
// it can be written in the for ray = point + t * vector, where t is any real #
class ray {
    public:
        ray();

        // will fill the data members with the point and vector
        void makeRay(point3 & getOrig, vec3 & getDir);

        // will first scalar multiply the vector, then add that to the point vector and return
        point3 at(double t);

        // returns the origin and direction
        point3 origin() const;
        vec3 direction() const;

    private:
        point3 orig;
        vec3 dir;
};


#endif