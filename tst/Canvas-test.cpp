#include "gtest/gtest.h"
#include "Canvas.h"
#include <vector>

Canvas canvas;

TEST(CanvasTest, setCanvas) {
    Color color= Color(0, 0, 0);
    Canvas a = Canvas(2, 1);

    EXPECT_EQ(a.getHeight(), 2);
    EXPECT_EQ(a.getWidth(), 1);
}


TEST(CanvasTest, getPixel) {
    Canvas a = Canvas(2,2);
    Color color1 = a.getPixel(1,1);

    a.printPixel(1, 1);

    std::cout << color1.getGreen() << "\n";

    EXPECT_TRUE(canvas.equal(color1.getRed(), 0));
    EXPECT_TRUE(canvas.equal(color1.getGreen(), 0));
    EXPECT_TRUE(canvas.equal(color1.getBlue(), 0));        

}


TEST(CanvasTest, setPixel) {
    Canvas a = Canvas(2,2);
    Color color1 = Color(1, 0, 0);
    a.setPixel(1, 1, color1);

    Color color2 = a.getPixel(1,1);

    EXPECT_TRUE(canvas.equal(color2.getRed(), 1));
    EXPECT_TRUE(canvas.equal(color2.getGreen(), 0));
    EXPECT_TRUE(canvas.equal(color2.getBlue(), 0));   
}
