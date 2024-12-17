#include "main.h"

// takes in a ray as an argument, will draw the color of the ray
void rayColor(ray & curRay);

// takes a ray, radius(double) of the sphere, x,y,z(point3) the sphere is at on the x,y,z-axis
// returns if it is hit(true) or not(false)
bool hitSphere(ray & curRay, double radius, point3 & center);

int main() {
    // WIDTH OF THE IMAGE, HEIGHT IS AUTO CALULATED VIA ASPECT RATIO
    int imgWidth {1920};
    double aspectRatio {16.0/9.0};
    int imgHeight {int(imgWidth / aspectRatio)};
    double focalLength {1}; // how far away the veiwplane is in the z-axis

    // location of camera
    point3 cameraLoc;
    cameraLoc.makePoint(0,0,0);

    // calulates the viewport demention, the plane of which rays will be sent through
    double viewportHeight {2};
    double viewportWidth {viewportHeight * (double(imgWidth) / imgHeight)};

    // calulates how spaced out each pixel will be
    double verticalDelta {viewportHeight/imgHeight};
    double horozantalDelta {viewportWidth/imgWidth};

    // calculates the top left of the viewport, aswell as where the pixel will lie of this plane
    point3 viewportTopLeft, pixelTopLeft;
    viewportTopLeft.makePoint(cameraLoc.getX() - viewportWidth/2, cameraLoc.getY() + viewportHeight/2, -focalLength);
    // the 0.5 will cener the rau inside the pixel
    pixelTopLeft.makePoint(viewportTopLeft.getX() + 0.5 * horozantalDelta, viewportTopLeft.getY() - 0.5 * verticalDelta, viewportTopLeft.getZ());

    // RENDER

    // were using a .ppm file for the image so the following are required
    cout << "P3" << endl
         << imgWidth << ' ' << imgHeight << endl
         << "255" << endl;

    for (int j{0}; j < imgHeight; ++j) {
        clog << "\rScanlines remaning: " << (imgHeight - j) << ' ' << flush;
        for (int i{0}; i < imgWidth; ++i) {
            // will find the point at which the current pixel is at
            point3 pixelCenter;
            pixelCenter.makePoint(pixelTopLeft.getX() + horozantalDelta * i, pixelTopLeft.getY() - verticalDelta * j, pixelTopLeft.getZ());

            // will find the direction from the cameras origin to the intersecion of the pixel
            vec3 rayDir;
            rayDir.makeVector(pixelCenter.getX() - cameraLoc.getX(), pixelCenter.getY() - cameraLoc.getY(), pixelCenter.getZ() - cameraLoc.getZ());

            // constructs the ray
            ray curRay;
            curRay.makeRay(cameraLoc, rayDir);

            rayColor(curRay);
        }
    }

    clog << "\rDone.                    \n";

    return 0;
}

// will detect if the ray interects with the sphere
// I did some math and found A, B, and C, then we just calculate
// the descrimanites, this will tell us the # of intersection
// if the # of intersection is >= 1, we can draw red
bool hitSphere(ray & curRay, double radius, point3 & center) {
    vec3 oc;

    oc.makeVector(
            -curRay.origin().getX() + center.getX(),
            -curRay.origin().getY() + center.getY(),
            -curRay.origin().getZ() + center.getZ()
    );

    double a {curRay.direction().dot(curRay.direction())};
    double b {-2.0 * (curRay.direction().dot(oc))};
    double c {oc.dot(oc) - radius*radius};

    double discriminant {b*b - 4*a*c};

    return discriminant >= 0;
}

// will draw the ray color given the passed ray
void rayColor(ray & curRay) {
    point3 center;
    center.makePoint(0, 0, 5);

    if (hitSphere(curRay, 0.5, center)) {
        writeColor(1,0,0);
        return;
    }

    vec3 a;
    a.makeVector(curRay.direction().getX(), curRay.direction().getY(), curRay.direction().getZ());
    a.normalize();
    // this normaized ray dir is an double [-1, 1]
    // we want a double [0,1], to do this, we can first add 1 to the vector
    // to get a domain of [0, 2], then divide by 2 to get a domain of [0,1]
    a.addVector(1, 1, 1);
    a.scalarMultiply(0.5);

    // throwing these values to render a fun image
    writeColor(1 - a.getX() + a.getX() * 0.5, 
               1 - a.getY() + a.getY() * 0.7,
               1 - a.getZ() + a.getZ() * 1.0);
}