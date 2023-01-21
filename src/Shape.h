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
            this->mOrigin = Matrix(4,1).pointMatrix(0, 0, 0);
            return *this;
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

        Matrix normal_at(Matrix world_point) {
 

            Matrix object_point = mTransform.inverse().multiply(world_point);
            Matrix object_normal = object_point.subtract(Matrix(4,1).pointMatrix(0,0,0));
            Matrix world_normal = mTransform.inverse().transpose().multiply(object_normal);

            world_normal.setCell(3,0,0);           

            return world_normal.normalize();
     
        }

 };

#endif