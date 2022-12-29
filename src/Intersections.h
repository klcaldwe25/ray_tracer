#include "Intersection.h"
#include <algorithm>
#include <limits>

#ifndef RAY_TRACER_INTERSECTIONS_H
#define RAY_TRACER_INTERSECTIONS_H

class Intersections {
    protected:
        std::vector<Intersection> mIntersections;
    
    public:
        Intersections(){}

        void setIntersections(Intersection intersection) {
            mIntersections.push_back(intersection);
        }

        std::vector<Intersection> getIntersections() {
            return mIntersections;
        }

        Intersection hit() {

            Intersection intersection = Intersection(std::numeric_limits<float>::max(), Shape());

            for (auto i : mIntersections) {
                if (i.getT() > 0 && i.getT() < intersection.getT()) {
                    intersection.setT(i.getT());
                }
            }

            return intersection;
        }

        Intersections intersectSphere(Ray r, Shape s) {
            Intersections intersections = Intersections();

            Matrix sphere_to_ray = r.getOrigin().subtract(s.getOrigin());

            float a = r.getDirection().dot(r.getDirection());
            float b = 2 * r.getDirection().dot(sphere_to_ray);
            float c = sphere_to_ray.dot(sphere_to_ray) - 1;
            float discriminant =  std::pow(b, 2.0) - (4 * a * c);

            if (discriminant >= 0) {
                intersections.setIntersections( Intersection( (-b - std::sqrt(discriminant)) / (2 * a), s ) );
                intersections.setIntersections( Intersection( (-b + std::sqrt(discriminant)) / (2 * a), s ) );
            }

            return intersections;
        }
};

#endif