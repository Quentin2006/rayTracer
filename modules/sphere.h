
#ifndef SPHERE_H
#define SPHERE_H

#include "hittable.h"

// this class will spawn a sphere into the world
class sphere : public hittable {
  public:
    // this fucntion will spawn the sphere at the specfied location with a specified radius
    // this will initlize the center value to the specified center, and ensure the radius is > 0
    sphere(const point3& center, double radius) : center(center), radius(std::fmax(0,radius)) {}

    // this fucntion will return a true if hit, and a false otherwise
    // this fucntion takes a ray, interval for t, and the hit record
    bool hit(const ray& r, interval ray_t, hit_record & rec) const override{
        // calulated all needed values for discriminant
        vec3 oc = center - r.origin();
        auto a = r.direction().length_squared();
        auto h = dot(r.direction(), oc);
        auto c = oc.length_squared() - radius*radius;

        // if there is an itersection(t>0) we will proseed, else return false 
        auto discriminant = h*h - a*c;
        if (discriminant < 0)
            return false;

        // now we solve the enire quad formula, aka (h+-sqrt(discriminant))/a
        auto sqrtd = std::sqrt(discriminant);

        // Find the nearest root that lies in the acceptable range.
        // root calulates the neg part of the quad formula
        auto root = (h - sqrtd) / a;
        // if this value t (root) isnt in the valid range, then we can check for positive terms
        if (!ray_t.surrounds(root)) {
            // root is then set to the pos part of the quad formula
            root = (h + sqrtd) / a;
            // if this new value t (root) isnt in a interval, we know there was no intersection
            if (!ray_t.surrounds(root))
                return false;
        }

        // if there was an intersection in the interval, we will store the value t, the position at t, the 
        rec.t = root;
        rec.p = r.at(rec.t);
        // this will then calulate the normal vector that goes outward from the surface
        vec3 outward_normal = (rec.p - center) / radius;
        // stores that normal vector in the record
        rec.set_face_normal(r, outward_normal);

        return true;
    }

  private:
    point3 center;
    double radius;
};

#endif