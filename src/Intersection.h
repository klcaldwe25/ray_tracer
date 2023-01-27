#include "Shape.h"

#ifndef RAY_TRACER_INTERSECTION_H
#define RAY_TRACER_INTERSECTION_H

class Intersection {
    protected:
        float mT;
        Sphere mObject;

    public:
        Intersection(){}

        Intersection(float t, Sphere object) {
            mT = t;
            mObject = object;
        }

        void setT(float t) {
            mT = t;
        }

        float getT () {
            return mT;
        }

        Sphere getObject() {
            return mObject;
        }

};

#endif