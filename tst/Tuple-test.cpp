#include "gtest/gtest.h"
#include <cmath>
#include "Tuple.h"
#include "iostream"

TEST(tupleTest, setTuple) {
    Tuple p = Tuple(1, 2, 3, 1);

    EXPECT_EQ(p.getX(), 1);
    EXPECT_EQ(p.getY(), 2);
    EXPECT_EQ(p.getZ(), 3);
    EXPECT_EQ(p.getW(), 1);           
}

TEST(tupleTest, setPoint) {
    Tuple p = point(1, 2, 3);

    EXPECT_EQ(p.getX(), 1);
    EXPECT_EQ(p.getY(), 2);
    EXPECT_EQ(p.getZ(), 3);
    EXPECT_EQ(p.getW(), 1);      
}

TEST(tupleTest, setVector) {
    Tuple p = vector(1, 2, 3);
    
    EXPECT_EQ(p.getX(), 1);
    EXPECT_EQ(p.getY(), 2);
    EXPECT_EQ(p.getZ(), 3);
    EXPECT_EQ(p.getW(), 0);      
}

TEST(tupleTest, isEqual) {
    float a = 1.0;
    float b = 1.0;

    EXPECT_TRUE(equal(a, b));
}

TEST(tupleTest, isNotEqual) {
    float a = 1.0;
    float b = 1.01;

    EXPECT_FALSE(equal(a, b));
}

TEST(tupleTest, addTuple) {
    Tuple a = Tuple(3, -2, 5, 1);
    Tuple b = Tuple(-2, 3, 1, 0);
    Tuple c = add(a, b);

    EXPECT_EQ(c.getX(), 1);
    EXPECT_EQ(c.getY(), 1);
    EXPECT_EQ(c.getZ(), 6);
    EXPECT_EQ(c.getW(), 1);        
}

TEST(tupleTest, subtract1) {
    Tuple a = point(3, 2, 1);
    Tuple b = point(5, 6, 7);
    Tuple c = subtract(a, b);

    EXPECT_EQ(c.getX(), -2);
    EXPECT_EQ(c.getY(), -4);
    EXPECT_EQ(c.getZ(), -6);
    EXPECT_EQ(c.getW(), 0);
}

TEST(tupleTest, subtract2) {
    Tuple a = point(3, 2, 1);
    Tuple b = vector(5, 6, 7);
    Tuple c = subtract(a, b);

    EXPECT_EQ(c.getX(), -2);
    EXPECT_EQ(c.getY(), -4);
    EXPECT_EQ(c.getZ(), -6);
    EXPECT_EQ(c.getW(), 1);
}

TEST(tupleTest, subtract3) {
    Tuple a = point(3, 2, 1);
    Tuple b = point(5, 6, 7);
    Tuple c = subtract(a, b);

    EXPECT_EQ(c.getX(), -2);
    EXPECT_EQ(c.getY(), -4);
    EXPECT_EQ(c.getZ(), -6);
    EXPECT_EQ(c.getW(), 0);
}

TEST(tupleTest, negate) {
    Tuple a = Tuple(1, -2, 3, -4);
    Tuple b = negate(a);

    EXPECT_EQ(b.getX(), -1);
    EXPECT_EQ(b.getY(), 2);
    EXPECT_EQ(b.getZ(), -3);
    EXPECT_EQ(b.getW(), 4);
}

TEST(tupleTest, multiply) {
    Tuple a = Tuple(1, -2, 3, -4);
    Tuple b = multiply(a, 3.5);

    EXPECT_EQ(b.getX(), 3.5);
    EXPECT_EQ(b.getY(), -7);
    EXPECT_EQ(b.getZ(), 10.5);
    EXPECT_EQ(b.getW(), -14);
}

TEST(tupleTest, divide) {
    Tuple a = Tuple(1, -2, 3, -4);
    Tuple b = divide(a, 2);

    EXPECT_EQ(b.getX(), 0.5);
    EXPECT_EQ(b.getY(), -1);
    EXPECT_EQ(b.getZ(), 1.5);
    EXPECT_EQ(b.getW(), -2);
}

TEST(tupleTest, magnitude) {
    Tuple a = vector(1, 2, 3);

    EXPECT_TRUE(equal(magnitude(a), std::sqrt(14)));

}

TEST(tupleTest, normalize) {
    Tuple a = vector(1, 2, 3);
    Tuple b = normalize(a);

    EXPECT_TRUE(equal(magnitude(b), 1.0));

}

TEST(tupleTest, dot) {
    Tuple a = vector(1, 2, 3);
    Tuple b = vector(2, 3, 4);

    EXPECT_TRUE(equal(dot(a, b), 20.0));
}

TEST(tupleTest, cross) {
    Tuple a = vector(1, 2, 3);
    Tuple b = vector(2, 3, 4);
    Tuple c = cross(a, b);
    Tuple d = cross(b, a);

    EXPECT_EQ(c.getX(), -1);
    EXPECT_EQ(c.getY(), 2);
    EXPECT_EQ(c.getZ(), -1); 

    EXPECT_EQ(d.getX(), 1);
    EXPECT_EQ(d.getY(), -2);
    EXPECT_EQ(d.getZ(), 1); 

}