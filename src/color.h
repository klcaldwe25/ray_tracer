#include "Tuple.h"

#ifndef RAY_TRACER_COLOR_H
#define RAY_TRACER_COLOR_H

class Color {
    protected:
        float mRed;
        float mGreen;
        float mBlue;
    
    public:
        Color(){}

        Color(float red, float green, float blue) {
            mRed = red;
            mGreen = green;
            mBlue = blue;
        }

        float getRed() {
            return mRed;
        }

        float getGreen() {
            return mGreen;
        }

        float getBlue() {
            return mBlue;
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