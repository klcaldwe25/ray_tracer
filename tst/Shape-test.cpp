#include "gtest/gtest.h"
#include "Shape.h"
#include "Matrix.h"

TEST (ShapeTest, testOne) {
//    Shape s = Shape().sphereShape();

    Sphere s = Sphere();

    Matrix m1 = Matrix(4,4).identityMatrix();

    EXPECT_TRUE(m1.isEqual(s.getTransform()));
}

TEST (ShapeTest, testTwo) {
//    Shape s = Shape().sphereShape();

    Sphere s = Sphere();

    Matrix t = Matrix(4,4).translationMatrix(2, 3, 4);

    s.setTransform(t);

    EXPECT_TRUE(t.isEqual(s.getTransform()));       
}

TEST (ShapeTest, testThree) {
//    Shape s = Shape().sphereShape();

    Sphere s = Sphere();

    Matrix n = s.normal_at(Matrix(4,1).pointMatrix(1,0,0));

    Matrix v = Matrix(4,1).vectorMatrix(1,0,0);

    EXPECT_TRUE(n.isEqual(v));
}

TEST (ShapeTest, testFour) {
//    Shape s = Shape().sphereShape();

    Sphere s = Sphere();

    Matrix n = s.normal_at(Matrix(4,1).pointMatrix(0,1,0));

    Matrix v = Matrix(4,1).vectorMatrix(0,1,0);

    EXPECT_TRUE(n.isEqual(v));
}

TEST (ShapeTest, testFive) {
//    Shape s = Shape().sphereShape();

    Sphere s = Sphere();

    Matrix n = s.normal_at(Matrix(4,1).pointMatrix(0,0,1));

    Matrix v = Matrix(4,1).vectorMatrix(0,0,1);

    EXPECT_TRUE(n.isEqual(v));
}

TEST (ShapeTest, testSix) {
//    Shape s = Shape().sphereShape();

    Sphere s = Sphere();

    float val = std::sqrt(3)/3;

    Matrix n = s.normal_at(Matrix(4,1).pointMatrix(val, val, val));

    Matrix v = Matrix(4,1).vectorMatrix(val, val, val);

    EXPECT_TRUE(n.isEqual(v));
}

TEST (ShapeTest, testSeven) {
//    Shape s = Shape().sphereShape();

    Sphere s = Sphere();

    float val = std::sqrt(3)/3;

    Matrix n = s.normal_at(Matrix(4,1).pointMatrix(val, val, val));

    EXPECT_TRUE(n.isEqual(n.normalize()));
}

TEST (ShapeTest, testEight) {
//    Shape s = Shape().sphereShape();

    Sphere s = Sphere();

    s.setTransform(Matrix(4,4).translationMatrix(0,1,0));

    Matrix n = s.normal_at(Matrix(4,1).pointMatrix(0, 1.70711, -0.70711));

    Matrix v = Matrix(4,1).vectorMatrix(0, 0.70711, -0.70711);

    EXPECT_TRUE(n.isEqual(v));
}

TEST (ShapeTest, testNine) {
//    Shape s = Shape().sphereShape();

    Sphere s = Sphere();

    Matrix m = Matrix(4,4).scalingMatrix(1, 0.5, 1).multiply(Matrix(4,4).z_rotation(M_PI/5));

    s.setTransform(m);

   float val = std::sqrt(2)/2;

    Matrix n = s.normal_at(Matrix(4,1).pointMatrix(0, std::sqrt(2)/2, -(std::sqrt(2)/2)));

    Matrix v = Matrix(4,1).vectorMatrix(0, 0.97014, -0.24254);

    EXPECT_TRUE(n.isEqual(v));
 
}