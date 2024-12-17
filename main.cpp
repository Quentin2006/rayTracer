#include "main.h"

// takes in a ray as an argument, will draw the color of the ray
color rayColor(ray & curRay);

// takes a ray, radius(double) of the sphere, x,y,z(point3) the sphere is at on the x,y,z-axis
// returns if it is hit(true) or not(false)
bool hitSphere(const ray & curRay, double radius, const point3 & center);

int main() {
    // WIDTH OF THE IMAGE, HEIGHT IS AUTO CALULATED VIA ASPECT RATIO
    int imgWidth {1920};
    double aspectRatio {16.0/9.0};
    int imgHeight {int(imgWidth / aspectRatio)};
    double focalLength {1}; // how far away the veiwplane is in the z-axis

    // location of camera
    point3 cameraLoc(0,0,0);

    // calulates the viewport demention, the plane of which rays will be sent through
    double viewportHeight {2};
    double viewportWidth {viewportHeight * (double(imgWidth) / imgHeight)};

    // calulates how spaced out each pixel will be
    vec3 verticalDelta {0, viewportHeight/imgHeight, 0};
    vec3 horozantalDelta {viewportWidth/imgWidth, 0, 0};

    // calculates the top left of the viewport, aswell as where the pixel will lie of this plane
    point3 viewportTopLeft(cameraLoc + point3(-viewportWidth/2, viewportHeight/2, -focalLength));
    // the 0.5 will cener the rau inside the pixel
    point3 pixelTopLeft(viewportTopLeft + 0.5 * (verticalDelta - horozantalDelta));

    // RENDER

    // were using a .ppm file for the image so the following are required
    cout << "P3" << endl
         << imgWidth << ' ' << imgHeight << endl
         << "255" << endl;

    for (int j{0}; j < imgHeight; ++j) {
        clog << "\rScanlines remaning: " << (imgHeight - j) << ' ' << flush;
        for (int i{0}; i < imgWidth; ++i) {
            // will find the point at which the current pixel is at
            point3 pixelCenter(pixelTopLeft + horozantalDelta * i - verticalDelta * j);

            // will find the direction from the cameras origin to the intersecion of the pixel
            vec3 rayDir(pixelCenter - cameraLoc);

            // constructs the ray
            ray curRay(cameraLoc, rayDir);

            color pixelColor = rayColor(curRay);

            write_color(cout, pixelColor);

        }
    }

    clog << "\rDone.                    \n";

    return 0;
}

// will detect if the ray interects with the sphere
// I did some math and found A, B, and C, then we just calculate
// the descrimanites, this will tell us the # of intersection
// if the # of intersection is >= 1, we can draw red
bool hitSphere(const ray & curRay, double radius, const point3 & center) {
    vec3 oc(center - curRay.origin());

    double a {dot(curRay.direction(), curRay.direction())};
    double b {-2.0 * dot(curRay.direction(), oc)};
    double c {dot(oc, oc) - radius*radius};

    double discriminant {b*b - 4*a*c};

    return discriminant >= 0;
}

// will draw the ray color given the passed ray
color rayColor(ray & curRay) {

    if (hitSphere(curRay, 0.5, point3(0, 0, 1))) {
        return color(1,0,0);
    }

    // this normaized ray dir is an double [-1, 1]
    // we want a double [0,1], to do this, we can first add 1 to the vector
    // to get a domain of [0, 2], then divide by 2 to get a domain of [0,1]
    vec3 unitDir {unit_vector(curRay.direction())};
    double a {(0.5*unitDir.y() + 1)};

    // throwing these values to render a fun image
    return (1.0-a)*color(1.0,1.0,1.0) + a*color(0.5,0.7,1.0);
}