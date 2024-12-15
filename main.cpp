#include "main.h"

void rayColor(vec3 & rayDir);

int main() {

    // IMAGE PROPERTIES
    int imgWidth {1920};        // img resulution
    int imgHeight {1080};
    double focalLength {1.0};   // distance from the camera to the veiwport
    double viewportHeight {2.25};   // world space height of veiwport
    double veiwportWidth {4.0};     // world space width of veiwportA
    point3 cameraPos;
    cameraPos.makePoint(0, 0, 0);

    // calulates the step sizes
    double horizontalStep {veiwportWidth/imgWidth};
    double verticalStep {viewportHeight/imgHeight};

    // calulates the top left corner of the veiwport
    point3 viewportCenter, viewport00;
    viewportCenter.makePoint(0, 0, focalLength);
    viewport00.makePoint(-veiwportWidth/2, -viewportHeight/2, focalLength);


    // were using a .ppm file for the image so the following are required
    cout << "P3" << endl
         << imgWidth << ' ' << imgHeight << endl
         << "255" << endl;

    // RENDER

    for (int j{0}; j < imgHeight; ++j) {

        for (int i{0}; i < imgWidth; ++i) {
                // calculates the location of the center of the pixel
                point3 pixelCenter, currPos;
                currPos.makePoint((double(i) + 0.5) * horizontalStep, (double(j) + 0.5) * verticalStep * -1, 0);
                pixelCenter.addPoint(viewport00, currPos);

                // calulated the normalized dir of the ray
                vec3 rayDir;
                rayDir.makeVector(pixelCenter.getX() - cameraPos.getX(), 
                                  pixelCenter.getY() - cameraPos.getY(),
                                  pixelCenter.getZ() - cameraPos.getZ());
                rayDir.normalize();

                ray curRay;
                curRay.makeRay(pixelCenter, rayDir);

                rayColor(rayDir);
        }
    }


    return 0;
}



void rayColor(vec3 & rayDir) {
    vec3 a;
    a.makeVector(rayDir);
    // this normaized ray dir is an double [-1, 1]
    // we want a double [0,1], to do this, we can first add 1 to the vector
    // to get a domain of [0, 2], then divide by 2 to get a domain of [0,1]
    a.addVector(1, 1, 1);
    a.scalarMultiply(0.5);

    // throwing these values to render a fun image
    writeColor(1 - a.getX() + a.getX() * 0.3, 
               1 - a.getY() + a.getY() * 0.5,
               1 - a.getZ() + a.getZ() * 1.0);

}