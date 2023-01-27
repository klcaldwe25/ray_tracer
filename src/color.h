#include "Tuple.h"
#include <iostream>

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

            float EPSILON = 0.000999;

            if (std::abs(a - b) < EPSILON) {
                return true;
            } else {
                return false;
            }
        }

        bool isEqual(Color other) {       
            Color self = *this;
            if ( equal(self.getBlue(), other.getBlue()) == false ) {
                return false;
            } else if ( equal(self.getGreen(), other.getGreen()) == false ) {
                return false;
            } else if ( equal(self.getRed(), other.getRed()) == false ) {
                return false;
            } else {
                return true;
            }
        }

        Color add(Color a, Color b) {
            return Color ( 
                (a.getRed() + b.getRed()), 
                (a.getGreen() + b.getGreen()),
                (a.getBlue() + b.getBlue())
            );
        }

        Color addColors(Color other) {
            Color self = *this;

            self.mBlue += other.getBlue();
            self.mGreen += other.getGreen();
            self.mRed += other.getRed();

            return self;
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

        Color multiplyScalar(float b) {
            Color self = *this;
            self.mBlue *= b;
            self.mGreen *= b;
            self.mRed *= b;

            return self;
        }

        Color multiplyColors(Color other) {
            Color self = *this;
            self.mBlue *= other.getBlue();
            self.mGreen *= other.getGreen();
            self.mRed *= other.getRed();

            return self;
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