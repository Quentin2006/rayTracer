#include "main.h"

int main() {
    // initlizes the world 
    // will hold t value of intersection, point of intersecion (p), normal vector, and weather 
    // that normal vector is facing outwards(true) or inwards(false)
    hittable_list world;

    // add two spheres at the spectified location and radius
    world.add(make_shared<sphere>(point3(0,0,-1), 0.5));
    world.add(make_shared<sphere>(point3(0,-100.5,-1), 100));

    // makes camrea object
    camera cam;
    // sets the aspect ratio and image width (rest are auto calulated)
    cam.aspect_ratio = 16.0 / 9.0;
    cam.image_width  = 1280;

    // renders the image given the world 
    cam.render(world);

    return 0;
}

