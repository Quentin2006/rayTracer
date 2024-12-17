#include "main.h"

// will give the ray color 
color rayColor(ray & r, const hittable& world) {
    // creates a hit record object
    hit_record rec;
    // if there was a hit, the world list will be updated with this hit and store 
    // the t value, point of intersection, normal vector, and weather the noraml 
    // vector is inside or outside the object all stored inside of a vector inside world
    if (world.hit(r, interval(0, infinity), rec)) {
        return 0.5 * (rec.normal + color(1, 1, 1));
    }

    // if there is no hit, we will draw the background as normal
    vec3 unitDir {unit_vector(r.direction())};
    double a {0.5*(unitDir.y() + 1)};
    return (1.0-a)*color(1.0,1.0,1.0) + a*color(0.5,0.7,1.0);
}

int main() {
    // WIDTH OF THE IMAGE, HEIGHT IS AUTO CALULATED VIA ASPECT RATIO
    double aspectRatio {16.0/9.0};
    int imgWidth {1280};
    int imgHeight {int(imgWidth / aspectRatio)};

    // World
    // makes an object to hold all of the info about each hit
    hittable_list world;

    // adds two spheres to the world
    world.add(make_shared<sphere>(point3(0,0,-1), 0.5));
    world.add(make_shared<sphere>(point3(0,-100.5,-1), 100));

    // Camera
    // calulates the viewport demention, the plane of which rays will be sent through
    double focalLength {1}; // how far away the veiwplane is in the z-axis
    double viewportHeight {2};
    double viewportWidth {viewportHeight * (double(imgWidth) / imgHeight)};
    point3 cameraLoc(0,0,0); // location of camera

    // calulates th evectors that go along the viewport
    vec3 viewport_horizantal{viewportWidth, 0, 0};
    vec3 viewport_vertical{0, -viewportHeight, 0};

    // calulates the spacing from pixel to pixle
    vec3 pixel_delta_horizantal {viewport_horizantal/imgWidth};
    vec3 pixel_delta_vertical {viewport_vertical/imgHeight};

    // calculates the top left of the viewport, aswell as where the pixel will lie of this plane
    point3 viewportTopLeft(cameraLoc 
                           - vec3(0, 0, focalLength) - viewport_horizantal/2 - viewport_vertical/2);
    // the 0.5 will cener the rau inside the pixel
    point3 pixelTopLeft(viewportTopLeft + 0.5 * (pixel_delta_horizantal + pixel_delta_vertical));

    // RENDER

    // were using a .ppm file for the image so the following are required
    cout << "P3" << endl
         << imgWidth << ' ' << imgHeight << endl
         << "255" << endl;

    for (int j{0}; j < imgHeight; ++j) {
        clog << "\rScanlines remaning: " << (imgHeight - j) << ' ' << flush;
        for (int i{0}; i < imgWidth; ++i) {
            // will find the point at which the current pixel is at
            point3 pixelCenter(pixelTopLeft + pixel_delta_horizantal * i + pixel_delta_vertical * j);
            // will find the direction from the cameras origin to the intersecion of the pixel
            vec3 rayDir(pixelCenter - cameraLoc);
            // constructs the ray
            ray r(cameraLoc, rayDir);
            // calculates the color the ray should be
            color pixelColor = rayColor(r, world);
            // will write this coulor it cout
            write_color(cout, pixelColor);
        }
    }

    clog << "\rDone.                    \n";

    return 0;
}

