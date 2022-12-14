#include "Tuple.h"
#include <cmath>

float EPSILON = 0.00001;

Tuple point(float x, float y, float z) {
    return Tuple(x, y, z, 1);
}

Tuple vector(float x, float y, float z) {
    return Tuple(x, y, z, 0);
}

bool equal(Tuple a, Tuple b) {
    if ( (std::abs(a.getX() - b.getX()) < EPSILON) &&
         (std::abs(a.getY() - b.getY()) < EPSILON) &&
         (std::abs(a.getZ() - b.getZ()) < EPSILON) &&
         (std::abs(a.getW() - b.getW()) < EPSILON) ) {
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
    return std::sqrt( std::pow(a.getX(), 2.0) + std::pow(a.getY(), 2.0) + std::pow(a.getZ(), 2.0) );
}