#include <iostream>
#include <cmath>

using namespace std;

// this class will hold any points we will need (very simaler to the vec3 class)
class point3 {
    public:
        point3();
        
        // will make the point (array) given the components
        void makePoint(double x, double y, double z);
        void makePoint(point3 & setPoint);

        // will return the point
        point3 getPoint();

        // will add 2 points and set the current point to the sum
        void addPoint(point3 & addPoint1, point3 & addPoint2);
        void addPoint(point3 & addPoint);

        // will subract point2 from point1
        void subtractPoint(point3 & subPoint1, point3 & subPoint2);
        void subtractPoint(point3 & subPoint);

        // will sacalar multiply point by t
        void scalarMultiply(double t);

        // will just retrun the points x, y, and z components 
        double getX() const;
        double getY() const;
        double getZ() const;

    private:
        // a vector that holds the x, y, and z components
        double point[3];
};

// this class will hold all of the data for any vectors
class vec3 {
    public:
        vec3();
        // will return a copy of the vector
        vec3 getVec();

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

// this class will store the data for a ray,
// REMINDER, a ray is just a point and a scalar multiple of a vector in the.
// it can be written in the for ray = point + t * vector, where t is any real #
class ray {
    public:
        ray();

        // will fill the data members with the point and vector
        void makeRay(point3 & getOrig, vec3 & getDir);

        // will first scalar multiply the vector, then add that to the point vector and return
        point3 at(double t);

        // returns the origin and direction
        point3 origin() const;
        vec3 direction() const;

    private:
        point3 orig;
        vec3 dir;
};


void writeColor(double r, double g, double b);


