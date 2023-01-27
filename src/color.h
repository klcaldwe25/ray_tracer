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

        Color add(Color other) {
            Color self = *this;
            self.mRed += other.getRed();
            self.mGreen += other.getGreen();
            self.mBlue += other.getBlue();
            return self;
        }

        Color subtract(Color other) {
            Color self = *this;
            self.mRed -= other.getRed();
            self.mGreen -= other.getGreen();
            self.mBlue -= other.getBlue();
            return self;            
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
};

#endif