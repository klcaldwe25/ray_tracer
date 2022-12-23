#include <cmath>

#ifndef RAY_TRACER_TUPLE_H
#define RAY_TRACER_TUPLE_H

class Tuple {
    protected:
        float mX;
        float mY;
        float mZ;
        float mW;

    public:
        Tuple() {}

        Tuple (float x, float y, float z, float w) {
            mX = x;
            mY = y;
            mZ = z;
            mW = w;
        }

        void setX (float x) {
            mX = x;
        }

        void setY (float y) {
            mY = y;
        }

        void setZ (float z) {
            mZ = z;
        }

        void setW (float w) {
            mW = w;
        }

        float getX () {
            return mX;
        }

        float getY () {
            return mY;
        }

        float getZ () {
            return mZ;
        }

        float getW () {
            return mW;
        }

        bool equal(float a, float b) {

            float EPSILON = 0.00001;

            if (std::abs(a - b) < EPSILON) {
                return true;
            } else {
                return false;
            }
        }

        Tuple add(Tuple a, Tuple b) {
            return Tuple ( 
                (a.getX() + b.getX()), 
                (a.getY() + b.getY()),
                (a.getZ() + b.getZ()),
                (a.getW() + b.getW())
            );
        }

        Tuple subtract(Tuple a, Tuple b) {
            return Tuple ( 
                (a.getX() - b.getX()), 
                (a.getY() - b.getY()),
                (a.getZ() - b.getZ()),
                (a.getW() - b.getW())
            );
        }

        Tuple negate(Tuple a) {
            return Tuple ( 
                (0 - a.getX()), 
                (0 - a.getY()),
                (0 - a.getZ()),
                (0 - a.getW())
            );
        }

        Tuple multiply(Tuple a, float b) {
            return Tuple ( 
                (a.getX() * b), 
                (a.getY() * b),
                (a.getZ() * b),
                (a.getW() * b)
            );    
        }

        Tuple divide(Tuple a, float b) {
            return Tuple ( 
                (a.getX() / b), 
                (a.getY() / b),
                (a.getZ() / b),
                (a.getW() / b)
            );    
        }

        float magnitude(Tuple a) {
            return std::sqrt( std::pow(a.getX(), 2.0) + 
                std::pow(a.getY(), 2.0) + 
                std::pow(a.getZ(), 2.0) 
            );
        }

        Tuple normalize (Tuple a) {
            return Tuple ( 
                (a.getX() / magnitude(a)), 
                (a.getY() / magnitude(a)),
                (a.getZ() / magnitude(a)),
                (a.getW() / magnitude(a))
            ); 
        }

        float dot(Tuple a, Tuple b) {
            return ( 
                (a.getX() * b.getX()) +
                (a.getY() * b.getY()) +
                (a.getZ() * b.getZ()) +
                (a.getW() * b.getW())
            );     
        }

        Tuple cross(Tuple a, Tuple b) {
            return Tuple ( 
                ((a.getY() * b.getZ()) - (a.getZ() * b.getY())),
                ((a.getZ() * b.getX()) - (a.getX() * b.getZ())), 
                ((a.getX() * b.getY()) - (a.getY() * b.getX())),
                (0)
            ); 
        }        
};

class Point : public Tuple {
    public:
        Point(float x, float y, float z) {
            mX = x;
            mY = y;
            mZ = z;
            mW = 1;
        }
};

class Vector : public Tuple {
    public:
        Vector(float x, float y, float z) {
            mX = x;
            mY = y;
            mZ = z;
            mW = 0;
        }
};

#endif