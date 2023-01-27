#include "gtest/gtest.h"
#include "Color.h"
#include <iostream>

Color color;

TEST(ColorTest, testOne) {
    Color a = Color(-0.5, 0.4, 1.7);
    EXPECT_TRUE(a.isEqual(Color(-0.5, 0.4, 1.7)));
}

TEST(ColorTest, testTwo) {
    Color a = Color(0.9, 0.6, 0.75);
    EXPECT_TRUE(a.add(Color(0.7, 0.1, 0.25)).isEqual(Color(1.6, 0.7, 1.0)));
}

TEST(ColorTest, testThree) {
    Color a = Color(0.9, 0.6, 0.75);
    EXPECT_TRUE(a.subtract(Color(0.7, 0.1, 0.25)).isEqual(Color(0.2, 0.5, 0.5)));
}

TEST(ColorTest, testFour) {
    Color a = Color(0.2, 0.3, 0.4);
    EXPECT_TRUE(a.multiplyScalar(2.0).isEqual(Color(0.4, 0.6, 0.8)));    
}

TEST(ColorTest, testFive) {
    Color a = Color(1, 0.2, 0.4);
    EXPECT_TRUE(a.multiplyColors(Color(0.9, 1, 0.1)).isEqual(Color(0.9, 0.2, 0.04)));  
}