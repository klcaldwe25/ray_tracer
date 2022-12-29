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
            Ray a = *this;

            return a.mOrigin.add( ( a.mDirection.multiplyScalar(t) ) );
        }
};

#endif