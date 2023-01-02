#include "Ray.h"
#include "Matrix.h"
#include <cmath>

#ifndef RAY_TRACER_SPHERE_H
#define RAY_TRACER_SPHERE_H

class Shape {
    protected:
        Matrix mOrigin;
        Matrix mTransform = Matrix(4,4).identityMatrix();

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

        void setTransform(Matrix t) {
            mTransform = t;
        }

        Matrix getTransform() {
            return mTransform;
        }

 };

#endif