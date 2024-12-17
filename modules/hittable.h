#ifndef HITTABLE_H
#define HITTABLE_H

// stores point of intersection, the normal vector otwards from object, the value t at which
// the intersection occors and where in the circle the normal vector is at
class hit_record {
  public:
    point3 p;
    vec3 normal;
    double t; 
    // false if the ray is inside the object, true if its outisde the object
    bool front_face;

    void set_face_normal(const ray& r, const vec3& outward_normal) {
        // Sets the hit record normal vector.
        // NOTE: the parameter `outward_normal` is assumed to have unit length.

        front_face = dot(r.direction(), outward_normal) < 0;
        normal = front_face ? outward_normal : -outward_normal;
    }
};

class hittable {
  public:
    virtual ~hittable() = default;

    virtual bool hit(const ray& r, interval ray_t, hit_record& rec) const = 0;
};

#endif