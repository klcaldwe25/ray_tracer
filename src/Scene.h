#include "Color.h"
#include "Matrix.h"

#ifndef RAY_TRACER_SCENE_H
#define RAY_TRACER_SCENE_H

class Lights {
    protected:
        Color mIntensity;
        Matrix mPosition;

    public:
        Lights(){};

        Lights(Color intensity, Matrix position) {
            mIntensity = intensity;
            mPosition = position;
        }
};

class Material {
    protected:
        Color mColor;
        float mAmbient;
        float mDiffuse;
        float mSpecular;
        float mShininess;

    public:
        Material(){};

        Material(Color color,
                float ambient,
                float diffuse,
                float specular,
                float shininess) {
            mColor = color;
            mAmbient = ambient;
            mDiffuse = diffuse;
            mSpecular = specular;
            mShininess = shininess;
        }
};

#endif