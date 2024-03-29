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

            Intersection intersection = Intersection(std::numeric_limits<float>::max(), Sphere());

            for (auto i : this->mIntersections) {
                if (i.getT() > 0 && i.getT() < intersection.getT()) {
                    intersection.setT(i.getT());
                }
            }

            return intersection;
        }

        Intersections intersectSphere(Ray r, Sphere s) {
            Intersections intersections = Intersections();

            Ray r2 = r.transform(s.getTransform().inverse());

            Matrix sphere_to_ray = r2.getOrigin().subtract(s.getOrigin());

            float a = r2.getDirection().dot(r2.getDirection());
            float b = 2 * r2.getDirection().dot(sphere_to_ray);
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