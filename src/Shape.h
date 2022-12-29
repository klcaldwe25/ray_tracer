#include "Ray.h"
#include "Matrix.h"
//#include "Intersection.h"
#include <cmath>

#ifndef RAY_TRACER_SPHERE_H
#define RAY_TRACER_SPHERE_H

class Shape {
    protected:
        Matrix mOrigin;

    public:
        Shape(){}

        Shape sphereShape() {
            Shape s = *this;
            s.mOrigin = Matrix(4,1).pointMatrix(0, 0, 0);
            return s;
        }

        Matrix getOrigin() {
            return mOrigin;
        }
 };

#endif