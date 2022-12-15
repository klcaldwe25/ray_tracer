#include <cmath>

#ifndef RAY_TRACER_TUPLE_H
#define RAY_TRACER_TUPLE_H

class Tuple {
    private:
        float _x;
        float _y;
        float _z;
        float _w;

    public:
        Tuple() {}

        Tuple (float x, float y, float z, float w) {
            _x = x;
            _y = y;
            _z = z;
            _w = w;
        }

        void setX (float x) {
            _x = x;
        }

        void setY (float y) {
            _y = y;
        }

        void setZ (float z) {
            _z = z;
        }

        void setW (float w) {
            _w = w;
        }

        float getX () {
            return _x;
        }

        float getY () {
            return _y;
        }

        float getZ () {
            return _z;
        }

        float getW () {
            return _w;
        }
};

float EPSILON = 0.00001;

bool equal(float a, float b) {
    if (std::abs(a - b) < EPSILON) {
        return true;
    } else {
        return false;
    }
}

Tuple point(float x, float y, float z) {
    return Tuple(x, y, z, 1);
}

Tuple vector(float x, float y, float z) {
    return Tuple(x, y, z, 0);
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

#endif