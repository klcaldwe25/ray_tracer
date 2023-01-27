#include "Color.h"
#include "Matrix.h"
#include <cmath>

#ifndef RAY_TRACER_SCENE_H
#define RAY_TRACER_SCENE_H

class Light {
    protected:
        Color mIntensity;
        Matrix mPosition;

    public:
        Light(){};

        Light(Color intensity, Matrix position) {
            mIntensity = intensity;
            mPosition = position;
        }

        Color getIntensity() {
            return mIntensity;
        }

        Matrix getPostion() {
            return mPosition;
        }
};

class Material {
    protected:
        Color mColor = Color(1,1,1);
        float mAmbient = 0.1;
        float mDiffuse = 0.9;
        float mSpecular = 0.9;
        float mShininess = 200.0;

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

        Color getColor() {
            return mColor;
        }

        float getAmbient() {
            return mAmbient;
        }

        float getDiffuse() {
            return mDiffuse;
        }

        float getSpecular() {
            return mSpecular;
        }

        float getShininess() {
            return mShininess;
        }

        Color lighting(Light light, Matrix position, Matrix eyeV, Matrix normalV) {
            Material self = *this;

            Color eColor = self.getColor().multiplyColors(light.getIntensity());

            Matrix lightV = light.getPostion().subtract(position).normalize();

            Color ambient = eColor.multiplyScalar(self.getAmbient());

            Color diffuse = Color(0,0,0);
            Color specular = Color (0,0,0);

            float lightDN = lightV.dot(normalV);

            if (lightDN >= 0) {
                diffuse = eColor.multiplyScalar(self.getDiffuse()).multiplyScalar(lightDN);
                Matrix reflectV = lightV.multiplyScalar(-1).reflect(normalV);
                float reflectDE = reflectV.dot(eyeV);

                if (reflectDE > 0) {
                    float factor = std::pow(reflectDE, self.getShininess());
                    specular = light.getIntensity().multiplyScalar(self.getSpecular()).multiplyScalar(factor);
                }
            }

            return ambient.addColors(diffuse).addColors(specular);

        }

};

#endif