#include "gtest/gtest.h"
#include <cmath>
#include "Tuple.h"

Tuple tuple;

TEST(tupleTest, setTuple) {
    Tuple p = Tuple(1, 2, 3, 1);

    EXPECT_EQ(p.getX(), 1);
    EXPECT_EQ(p.getY(), 2);
    EXPECT_EQ(p.getZ(), 3);
    EXPECT_EQ(p.getW(), 1);           
}

TEST(tupleTest, setPoint) {
    Point p = Point(1, 2, 3);

    EXPECT_EQ(p.getX(), 1);
    EXPECT_EQ(p.getY(), 2);
    EXPECT_EQ(p.getZ(), 3);
    EXPECT_EQ(p.getW(), 1);      
}

TEST(tupleTest, setVector) {
    Vector p = Vector(1, 2, 3);
    
    EXPECT_EQ(p.getX(), 1);
    EXPECT_EQ(p.getY(), 2);
    EXPECT_EQ(p.getZ(), 3);
    EXPECT_EQ(p.getW(), 0);      
}

TEST(tupleTest, isEqual) {
    float a = 1.0;
    float b = 1.0;

    EXPECT_TRUE(tuple.equal(a, b));
}

TEST(tupleTest, isNotEqual) {
    float a = 1.0;
    float b = 1.01;

    EXPECT_FALSE(tuple.equal(a, b));
}

TEST(tupleTest, addTuple) {
    Tuple a = Tuple(3, -2, 5, 1);
    Tuple b = Tuple(-2, 3, 1, 0);
    Tuple c = tuple.add(a, b);

    EXPECT_EQ(c.getX(), 1);
    EXPECT_EQ(c.getY(), 1);
    EXPECT_EQ(c.getZ(), 6);
    EXPECT_EQ(c.getW(), 1);        
}

TEST(tupleTest, subtract1) {
    Point a = Point(3, 2, 1);
    Point b = Point(5, 6, 7);
    Tuple c = tuple.subtract(a, b);

    EXPECT_EQ(c.getX(), -2);
    EXPECT_EQ(c.getY(), -4);
    EXPECT_EQ(c.getZ(), -6);
    EXPECT_EQ(c.getW(), 0);
}

TEST(tupleTest, subtract2) {
    Point a = Point(3, 2, 1);
    Vector b = Vector(5, 6, 7);
    Tuple c = tuple.subtract(a, b);

    EXPECT_EQ(c.getX(), -2);
    EXPECT_EQ(c.getY(), -4);
    EXPECT_EQ(c.getZ(), -6);
    EXPECT_EQ(c.getW(), 1);
}

TEST(tupleTest, subtract3) {
    Point a = Point(3, 2, 1);
    Point b = Point(5, 6, 7);
    Tuple c = tuple.subtract(a, b);

    EXPECT_EQ(c.getX(), -2);
    EXPECT_EQ(c.getY(), -4);
    EXPECT_EQ(c.getZ(), -6);
    EXPECT_EQ(c.getW(), 0);
}

TEST(tupleTest, negate) {
    Tuple a = Tuple(1, -2, 3, -4);
    Tuple b = tuple.negate(a);

    EXPECT_EQ(b.getX(), -1);
    EXPECT_EQ(b.getY(), 2);
    EXPECT_EQ(b.getZ(), -3);
    EXPECT_EQ(b.getW(), 4);
}

TEST(tupleTest, multiply) {
    Tuple a = Tuple(1, -2, 3, -4);
    Tuple b = tuple.multiply(a, 3.5);

    EXPECT_EQ(b.getX(), 3.5);
    EXPECT_EQ(b.getY(), -7);
    EXPECT_EQ(b.getZ(), 10.5);
    EXPECT_EQ(b.getW(), -14);
}

TEST(tupleTest, divide) {
    Tuple a = Tuple(1, -2, 3, -4);
    Tuple b = tuple.divide(a, 2);

    EXPECT_EQ(b.getX(), 0.5);
    EXPECT_EQ(b.getY(), -1);
    EXPECT_EQ(b.getZ(), 1.5);
    EXPECT_EQ(b.getW(), -2);
}

TEST(tupleTest, magnitude) {
    Vector a = Vector(1, 2, 3);

    EXPECT_TRUE(tuple.equal(tuple.magnitude(a), std::sqrt(14)));

}

TEST(tupleTest, normalize) {
    Vector a = Vector(1, 2, 3);
    Tuple b = tuple.normalize(a);

    EXPECT_TRUE(tuple.equal(tuple.magnitude(b), 1.0));

}

TEST(tupleTest, dot) {
    Vector a = Vector(1, 2, 3);
    Vector b = Vector(2, 3, 4);

    EXPECT_TRUE(tuple.equal(tuple.dot(a, b), 20.0));
}

TEST(tupleTest, cross) {
    Vector a = Vector(1, 2, 3);
    Vector b = Vector(2, 3, 4);
    Tuple c = tuple.cross(a, b);
    Tuple d = tuple.cross(b, a);

    EXPECT_EQ(c.getX(), -1);
    EXPECT_EQ(c.getY(), 2);
    EXPECT_EQ(c.getZ(), -1); 

    EXPECT_EQ(d.getX(), 1);
    EXPECT_EQ(d.getY(), -2);
    EXPECT_EQ(d.getZ(), 1); 

}