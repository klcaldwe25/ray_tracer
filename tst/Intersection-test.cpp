#include "gtest/gtest.h"
#include "Intersection.h"

TEST (IntersectionTest, intersectOne) {
//    Shape s = Shape().sphereShape();

    Sphere s = Sphere();
    
    Intersection i = Intersection(3.5, s);

    EXPECT_EQ(i.getT(), 3.5);
}