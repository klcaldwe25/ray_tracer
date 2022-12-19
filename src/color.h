#include "Tuple.h"

#ifndef RAY_TRACER_COLOR_H
#define RAY_TRACER_COLOR_H

class Color {
    protected:
        float _red;
        float _green;
        float _blue;
    
    public:
        Color(){}

        Color(float red, float green, float blue) {
            _red = red;
            _green = green;
            _blue = blue;
        }

        float getRed() {
            return _red;
        }

        float getGreen() {
            return _green;
        }

        float getBlue() {
            return _blue;
        }

        bool equal(float a, float b) {

            float EPSILON = 0.00001;

            if (std::abs(a - b) < EPSILON) {
                return true;
            } else {
                return false;
            }
        }

        Color add(Color a, Color b) {
            return Color ( 
                (a.getRed() + b.getRed()), 
                (a.getGreen() + b.getGreen()),
                (a.getBlue() + b.getBlue())
            );
        }

        Color subtract(Color a, Color b) {
            return Color ( 
                (a.getRed() - b.getRed()), 
                (a.getGreen() - b.getGreen()),
                (a.getBlue() - b.getBlue())
            );
        } 

        Color multiply(Color a, float b) {
            return Color ( 
                (a.getRed() * b), 
                (a.getGreen() * b),
                (a.getBlue() * b)
            );
        }

        Color hadamard_product (Color a, Color b) {
            return Color ( 
                (a.getRed() * b.getRed()), 
                (a.getGreen() * b.getGreen()),
                (a.getBlue() * b.getBlue())
            );            
        }           
};

#endif