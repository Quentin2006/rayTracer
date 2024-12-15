#include "../../main.h"

// this class will hold all of the data for any vectors
class vec3 {
    public:
        vec3();
        
        // will make the vector (array) given the components
        void makeVector(double x, double y, double z);

        // will add passed vector to the current vector
        void vectorAdd(vec3 & addVec);

        // will scalar multiply the vector
        void scalarMultiply(double scalar);

        // will just retrun the vectors x, y, and z components 
        double getX();
        double getY();
        double getZ();

    private:
        // a vector that holds the x, y, and z components
        double vector[3];
};
