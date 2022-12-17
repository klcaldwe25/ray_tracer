#include "gtest/gtest.h"
#include "Color.h"
#include <iostream>

Color color;

TEST(ColorTest, setColor) {
    Color c = Color(-0.5, 0.4, 1.7);

    EXPECT_TRUE( color.equal (c.getRed(), -0.5) );
    EXPECT_TRUE( color.equal( c.getGreen(), 0.4) );
    EXPECT_TRUE( color.equal( c.getBlue(), 1.7) );
}

TEST(ColorTest, add) {
    Color a = Color(0.9, 0.6, 0.75);
    Color b = Color(0.7, 0.1, 0.25);
    Color c = color.add(a, b);

    EXPECT_TRUE( color.equal (c.getRed(), 1.6) );
    EXPECT_TRUE( color.equal( c.getGreen(), 0.7) );
    EXPECT_TRUE( color.equal( c.getBlue(), 1.0) );    
}

TEST(ColorTest, subtract) {
    Color a = Color(0.9, 0.6, 0.75);
    Color b = Color(0.7, 0.1, 0.25);
    Color c = color.subtract(a, b);

    EXPECT_TRUE( color.equal (c.getRed(), 0.2) );
    EXPECT_TRUE( color.equal( c.getGreen(), 0.5) );
    EXPECT_TRUE( color.equal( c.getBlue(), 0.5) );    
}

TEST(ColorTest, multiply) {
    Color a = Color(0.2, 0.3, 0.4);
    Color b = color.multiply(a, 2.0);

    EXPECT_TRUE( color.equal (b.getRed(), 0.4) );
    EXPECT_TRUE( color.equal( b.getGreen(), 0.6) );
    EXPECT_TRUE( color.equal( b.getBlue(), 0.8) );        
}

TEST(ColorTest, hadamardProduct) {
    Color a = Color(1, 0.2, 0.4);
    Color b = Color(0.9, 1, 0.1);
    Color c = color.hadamard_product(a, b);

    EXPECT_TRUE( color.equal (c.getRed(), 0.9) );
    EXPECT_TRUE( color.equal( c.getGreen(), 0.2) );
    EXPECT_TRUE( color.equal( c.getBlue(), 0.04) );    

}