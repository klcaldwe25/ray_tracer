#include "gtest/gtest.h"
#include "Shape.h"
#include "Matrix.h"

TEST (ShapeTest, testOne) {
    Shape s = Shape().sphereShape();

    Matrix m1 = Matrix(4,4).identityMatrix();

    EXPECT_TRUE(m1.isEqual(s.getTransform()));
}

TEST (ShapeTest, testTwo) {
    Shape s = Shape().sphereShape();

    Matrix t = Matrix(4,4).translationMatrix(2, 3, 4);

    s.setTransform(t);

    EXPECT_TRUE(t.isEqual(s.getTransform()));       
}