#ifndef POINT3_H
#define POINT3_H

class vec3;

// this class will hold any points we will need (very simaler to the vec3 class)
class point3 {
    public:
        point3();

        double dot(vec3 vector);
        double dot(point3 point);
        double dot(double x, double y, double z);

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


#endif