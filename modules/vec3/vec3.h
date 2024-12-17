#ifndef VEC3_H
#define VEC3_H

class point3;

// this class will hold all of the data for any vectors
class vec3 {
    public:
        vec3();
        // will return a copy of the vector
        vec3 getVec();

        double dot(vec3 vector);
        double dot(point3 point);
        double dot(double x, double y, double z);

        // will make the vector (array) given the components
        void makeVector(double x, double y, double z);
        void makeVector(vec3 & setVec);

        // will add passed vector to the current vector
        void addVector(vec3 & addVec1, vec3 & addVec2);
        void addVector(vec3 & addVec);
        void addVector(double x, double y, double z);

        // will subract vec1 from point1
        void subtractVector(vec3 & subVec1, vec3 & subVec2);
        void subtractVector(vec3 & subVec);

        // will scalar multiply the vector
        void scalarMultiply(double scalar);

        // will normlize the vector
        void normalize();

        // will just retrun the vectors x, y, and z components 
        double getX() const;
        double getY() const;
        double getZ() const;

    private:
        // a vector that holds the x, y, and z components
        double vector[3];
};

#endif