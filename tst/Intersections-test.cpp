#include "gtest/gtest.h"
#include "Shape.h"
#include "Matrix.h"
#include "Ray.h"
#include "Intersection.h"
#include "Intersections.h"
#include <iostream>

TEST (IntersectionsTest, intersectOne) {
    Ray r = Ray(Matrix(4,1).pointMatrix(0,0,-5), Matrix(4,1).vectorMatrix(0,0,1));
    Shape s = Shape().sphereShape();

    Intersections xs = Intersections().intersectSphere(r, s);

    EXPECT_EQ(xs.getIntersections().size(), 2);
    EXPECT_EQ(xs.getIntersections()[0].getT(), 4.0);
    EXPECT_EQ(xs.getIntersections()[1].getT(), 6.0);
}

TEST (IntersectionsTest, intersectTwo) {
    Ray r = Ray(Matrix(4,1).pointMatrix(0,1,-5), Matrix(4,1).vectorMatrix(0,0,1));
    Shape s = Shape().sphereShape();

    Intersections xs = Intersections().intersectSphere(r, s);
    
    EXPECT_EQ(xs.getIntersections().size(), 2);
    EXPECT_EQ(xs.getIntersections()[0].getT(), 5.0);
    EXPECT_EQ(xs.getIntersections()[1].getT(), 5.0);
}

TEST (IntersectionsTest, intersectThree) {
    Ray r = Ray(Matrix(4,1).pointMatrix(0,2,-5), Matrix(4,1).vectorMatrix(0,0,1));    
    Shape s = Shape().sphereShape();

    Intersections xs = Intersections().intersectSphere(r, s);

    EXPECT_EQ(xs.getIntersections().size(), 0);
}

TEST (IntersectionsTest, intersectFour) {
    Ray r = Ray(Matrix(4,1).pointMatrix(0,0,0), Matrix(4,1).vectorMatrix(0,0,1));    
    Shape s = Shape().sphereShape();

    Intersections xs = Intersections().intersectSphere(r, s);

    EXPECT_EQ(xs.getIntersections().size(), 2);
    EXPECT_EQ(xs.getIntersections()[0].getT(), -1.0);
    EXPECT_EQ(xs.getIntersections()[1].getT(), 1.0);
}

TEST (IntersectionsTest, intersectFive) {
    Ray r = Ray(Matrix(4,1).pointMatrix(0,0,5), Matrix(4,1).vectorMatrix(0,0,1));    
    Shape s = Shape().sphereShape();

    Intersections xs = Intersections().intersectSphere(r, s);

    EXPECT_EQ(xs.getIntersections().size(), 2);
    EXPECT_EQ(xs.getIntersections()[0].getT(), -6.0);
    EXPECT_EQ(xs.getIntersections()[1].getT(), -4.0);    
}

TEST (IntersectionsTest, intersectSix) {
    Shape s = Shape().sphereShape();
    Intersections intersections = Intersections();
    intersections.setIntersections(Intersection(1, s));
    intersections.setIntersections(Intersection(2, s));

    EXPECT_EQ(intersections.getIntersections().size(), 2);
    EXPECT_EQ(intersections.getIntersections()[0].getT(), 1);
    EXPECT_EQ(intersections.getIntersections()[1].getT(), 2);    
}