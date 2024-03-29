#include "gtest/gtest.h"
#include "Shape.h"
#include "Matrix.h"
#include "Ray.h"
#include "Intersection.h"
#include "Intersections.h"
#include <iostream>
#include <limits>

TEST (IntersectionsTest, intersectOne) {
    Ray r = Ray(Matrix(4,1).pointMatrix(0,0,-5), Matrix(4,1).vectorMatrix(0,0,1));

    Sphere s = Sphere();

    Intersections xs = Intersections().intersectSphere(r, s);

    EXPECT_EQ(xs.getIntersections().size(), 2);
    EXPECT_EQ(xs.getIntersections()[0].getT(), 4.0);
    EXPECT_EQ(xs.getIntersections()[1].getT(), 6.0);

}

TEST (IntersectionsTest, intersectTwo) {
    Ray r = Ray(Matrix(4,1).pointMatrix(0,1,-5), Matrix(4,1).vectorMatrix(0,0,1));

    Sphere s = Sphere();

    Intersections xs = Intersections().intersectSphere(r, s);
    
    EXPECT_EQ(xs.getIntersections().size(), 2);
    EXPECT_EQ(xs.getIntersections()[0].getT(), 5.0);
    EXPECT_EQ(xs.getIntersections()[1].getT(), 5.0);
}

TEST (IntersectionsTest, intersectThree) {
    Ray r = Ray(Matrix(4,1).pointMatrix(0,2,-5), Matrix(4,1).vectorMatrix(0,0,1));    

    Sphere s = Sphere();

    Intersections xs = Intersections().intersectSphere(r, s);

    EXPECT_EQ(xs.getIntersections().size(), 0);
}

TEST (IntersectionsTest, intersectFour) {
    Ray r = Ray(Matrix(4,1).pointMatrix(0,0,0), Matrix(4,1).vectorMatrix(0,0,1));    

    Sphere s = Sphere();

    Intersections xs = Intersections().intersectSphere(r, s);

    EXPECT_EQ(xs.getIntersections().size(), 2);
    EXPECT_EQ(xs.getIntersections()[0].getT(), -1.0);
    EXPECT_EQ(xs.getIntersections()[1].getT(), 1.0);
}

TEST (IntersectionsTest, intersectFive) {
    Ray r = Ray(Matrix(4,1).pointMatrix(0,0,5), Matrix(4,1).vectorMatrix(0,0,1));    

    Sphere s = Sphere();

    Intersections xs = Intersections().intersectSphere(r, s);

    EXPECT_EQ(xs.getIntersections().size(), 2);
    EXPECT_EQ(xs.getIntersections()[0].getT(), -6.0);
    EXPECT_EQ(xs.getIntersections()[1].getT(), -4.0);    
}

TEST (IntersectionsTest, intersectSix) {
    Sphere s = Sphere();

    Intersections intersections = Intersections();
    intersections.setIntersections(Intersection(1, s));
    intersections.setIntersections(Intersection(2, s));

    EXPECT_EQ(intersections.getIntersections().size(), 2);
    EXPECT_EQ(intersections.getIntersections()[0].getT(), 1);
    EXPECT_EQ(intersections.getIntersections()[1].getT(), 2);    
}

TEST (IntersectionsTest, intersectSeven) {
    Sphere s = Sphere();

    Intersections xs = Intersections();
    xs.setIntersections(Intersection(1, s));
    xs.setIntersections(Intersection(2, s));

    Intersection i = xs.hit();

    EXPECT_EQ(i.getT(), 1);
}

TEST (IntersectionsTest, intersectEight) {
    Sphere s = Sphere();

    Intersections xs = Intersections();
    xs.setIntersections(Intersection(-1, s));
    xs.setIntersections(Intersection(1, s));

    Intersection i = xs.hit();

    EXPECT_EQ(i.getT(), 1);
}

TEST (IntersectionsTest, intersectNine) {
    Sphere s = Sphere();

    Intersections xs = Intersections();
    xs.setIntersections(Intersection(-2, s));
    xs.setIntersections(Intersection(-1, s));

    Intersection i = xs.hit();

    EXPECT_EQ(i.getT(), std::numeric_limits<float>::max());
}

TEST (IntersectionsTest, intersectTen) {
    Sphere s = Sphere();

    Intersections xs = Intersections();
    xs.setIntersections(Intersection(5, s));
    xs.setIntersections(Intersection(7, s));
    xs.setIntersections(Intersection(-3, s));
    xs.setIntersections(Intersection(2, s));    

    Intersection i = xs.hit();

    EXPECT_EQ(i.getT(), 2);
}

TEST (IntersectionsTest, intersectEleven) {
    Ray r = Ray(Matrix(4,1).pointMatrix(0,0,-5), Matrix(4,1).vectorMatrix(0,0,1));    

    Sphere s = Sphere();

    s.setTransform(Matrix(4,4).scalingMatrix(2,2,2));

    Intersections xs = Intersections().intersectSphere(r, s);

    EXPECT_EQ(xs.getIntersections().size(), 2);
    EXPECT_EQ(xs.getIntersections()[0].getT(), 3);
    EXPECT_EQ(xs.getIntersections()[1].getT(), 7);     
}

TEST (IntersectionsTest, intersectTwelve) {
    Ray r = Ray(Matrix(4,1).pointMatrix(0,0,-5), Matrix(4,1).vectorMatrix(0,0,1));    

    Sphere s = Sphere();

    s.setTransform(Matrix(4,4).translationMatrix(5,0,0));

    Intersections xs = Intersections().intersectSphere(r, s);

    EXPECT_EQ(xs.getIntersections().size(), 0);   
}