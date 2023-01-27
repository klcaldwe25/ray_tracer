#include "gtest/gtest.h"
#include "Scene.h"
#include "Color.h"
#include "Matrix.h"

TEST (SphereTest, testOne) {
    Color intensity = Color(1,1,1);
    Matrix position = Matrix(4,1).pointMatrix(0,0,0);

    Light light = Light(intensity, position);

    EXPECT_TRUE(position.isEqual(light.getPostion()));
    EXPECT_TRUE(intensity.isEqual(light.getIntensity()));
}

TEST (SphereTest, testTwo) {
    Material m = Material();
    Matrix position = Matrix(4,1).pointMatrix(0,0,0);

    Matrix eyeV = Matrix(4,1).vectorMatrix(0,0,-1);
    Matrix normalV = Matrix(4,1).vectorMatrix(0,0,-1);
    Light light = Light(Color(1,1,1), Matrix(4,1).pointMatrix(0,0,-10));

    Color result = m.lighting(light, position, eyeV, normalV);

    EXPECT_TRUE(result.isEqual(Color(1.9, 1.9, 1.9)));
}

TEST (SphereTest, testThree) {
    Material m = Material();
    Matrix position = Matrix(4,1).pointMatrix(0,0,0);

    Matrix eyeV = Matrix(4,1).vectorMatrix(0, std::sqrt(2)/2, std::sqrt(2)/2);
    Matrix normalV = Matrix(4,1).vectorMatrix(0,0,-1);
    Light light = Light(Color(1,1,1), Matrix(4,1).pointMatrix(0,0,-10));

    Color result = m.lighting(light, position, eyeV, normalV);

    EXPECT_TRUE(result.isEqual(Color(1.0, 1.0, 1.0)));
}

TEST (SphereTest, testFour) {
    Material m = Material();
    Matrix position = Matrix(4,1).pointMatrix(0,0,0);

    Matrix eyeV = Matrix(4,1).vectorMatrix(0, 0, -1);
    Matrix normalV = Matrix(4,1).vectorMatrix(0,0,-1);
    Light light = Light(Color(1,1,1), Matrix(4,1).pointMatrix(0, -10, -10));

    Color result = m.lighting(light, position, eyeV, normalV);

    EXPECT_TRUE(result.isEqual(Color(0.7364, 0.7364, 0.7364)));
}

TEST (SphereTest, testFive) {
    Material m = Material();
    Matrix position = Matrix(4,1).pointMatrix(0,0,0);

    Matrix eyeV = Matrix(4,1).vectorMatrix(0, -(std::sqrt(2)/2), -(std::sqrt(2)/2));
    Matrix normalV = Matrix(4,1).vectorMatrix(0,0,-1);
    Light light = Light(Color(1,1,1), Matrix(4,1).pointMatrix(0, 10, -10));

    Color result = m.lighting(light, position, eyeV, normalV);

    EXPECT_TRUE(result.isEqual(Color(1.6364, 1.6364, 1.6364)));
}

TEST (SphereTest, testSix) {
    Material m = Material();
    Matrix position = Matrix(4,1).pointMatrix(0,0,0);
    Matrix eyeV = Matrix(4,1).vectorMatrix(0, 0, -1);
    Matrix normalV = Matrix(4,1).vectorMatrix(0,0,-1);

    Light light = Light(Color(1,1,1), Matrix(4,1).pointMatrix(0, 0, 10)); 

   Color result = m.lighting(light, position, eyeV, normalV);   

   EXPECT_TRUE(result.isEqual(Color(0.1, 0.1, 0.1)));  
}