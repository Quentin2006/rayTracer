#include "../../main.h"

// this class will hold any points we will need (very simaler to the vec3 class)

class point3 {
    public:
        point3();
        
        // will make the point (array) given the components
        void makePoint(double x, double y, double z);

        // will just retrun the points x, y, and z components 
        double getX();
        double getY();
        double getZ();

    private:
        // a vector that holds the x, y, and z components
        double point[3];
};
