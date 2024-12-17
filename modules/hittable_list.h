
#ifndef HITTABLE_LIST_H
#define HITTABLE_LIST_H

#include "hittable.h"

#include <vector>

// stores a list of all hittable objects
class hittable_list : public hittable {
  public:

    // A vector to store shared pointers to hittable objects.
    std::vector<shared_ptr<hittable>> objects;

    hittable_list() {}

    // Constructor that initializes the list with a single hittable object.
    hittable_list(shared_ptr<hittable> object) { add(object); }

    // clears the list of all objects
    void clear() { objects.clear(); }

    // addd a hittable object to the list
    void add(shared_ptr<hittable> object) {
        objects.push_back(object);
    }

    // Check if the ray intersects with any object in the list.
    // Returns true if there is at least one intersection.
    bool hit(const ray& r, interval ray_t, hit_record& rec) const override {
        hit_record temp_rec;
        bool hit_anything = false;
        auto closest_so_far = ray_t.max;   // Initialize closest intersection distance to max of the interval.

        // Iterate over all hittable objects in the list.
        for (const auto& object : objects) {
            // Check if the current object intersects with the ray.
            if (object->hit(r, interval(ray_t.min, closest_so_far), temp_rec)) {
                hit_anything = true;        // an intersection was found
                closest_so_far = temp_rec.t;//updates the closest intersection distance
                rec = temp_rec;             // updates the hit record w/ the clsoest intersection
            }
        }

        return hit_anything;        // retunrns true if an object was hit
    }

};

#endif