#include "Matrix.h"

#ifndef RAY_TRACER_RAY_H
#define RAY_TRACER_RAY_H

class Ray {
    protected:
        Matrix mOrigin;
        Matrix mDirection;

    public:
        Ray (Matrix origin, Matrix direction) {
            mOrigin = origin;
            mDirection = direction;
        }

        Matrix getOrigin() {
            return mOrigin;
        }

        Matrix getDirection() {
            return mDirection;
        }

        Matrix position (float t) {
            return this->mOrigin.add( ( this->mDirection.multiplyScalar(t) ) );
        }

        Ray transform (Matrix m) {
            return Ray(m.multiply(this->mOrigin), m.multiply(this->mDirection));
        }
};

#endif