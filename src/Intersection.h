#include "Shape.h"

#ifndef RAY_TRACER_INTERSECTION_H
#define RAY_TRACER_INTERSECTION_H

class Intersection {
    protected:
        float mT;
        Shape mObject;

    public:
        Intersection(){}

        Intersection(float t, Shape object) {
            mT = t;
            mObject = object;
        }

        float getT () {
            return mT;
        }

        Shape getObject() {
            return mObject;
        }
};

#endif