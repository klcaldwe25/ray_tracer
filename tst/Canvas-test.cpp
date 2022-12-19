#include "gtest/gtest.h"
#include "Canvas.h"
#include <vector>

Canvas canvas;

TEST(CanvasTest, setCanvas) {
    Color color= Color(0, 0, 0);
    Canvas a = Canvas(2, 2, Color(0, 0 , 0));

    EXPECT_EQ(a.getHeight(), 2);
    EXPECT_EQ(a.getWidth(), 2);
}


TEST(CanvasTest, getPixel) {
    Canvas a = Canvas(2,2, Color(0, 0, 0));
    Color color1 = a.getPixel(1,1);

    a.printPixel(1, 1);

    std::cout << color1.getGreen() << "\n";

    EXPECT_TRUE(canvas.equal(color1.getRed(), 0));
    EXPECT_TRUE(canvas.equal(color1.getGreen(), 0));
    EXPECT_TRUE(canvas.equal(color1.getBlue(), 0));        

}


TEST(CanvasTest, setPixel) {
    Canvas a = Canvas(2,2, Color(0, 0, 0));
    Color color1 = Color(1, 0, 0);
    a.setPixel(1, 1, color1);

    Color color2 = a.getPixel(1,1);

    EXPECT_TRUE(canvas.equal(color2.getRed(), 1));
    EXPECT_TRUE(canvas.equal(color2.getGreen(), 0));
    EXPECT_TRUE(canvas.equal(color2.getBlue(), 0));   
}

TEST(CanvasTest, printPPMOne) {
    Canvas a = Canvas(5, 3, Color(0, 0, 0));
    a.setPixel(0, 0, Color(1.5, 0, 0) );
    a.setPixel(2, 1, Color(0, 0.5, 0) );
    a.setPixel(4, 2, Color(-0.5, 0, 1) );

    std::string ppm_str = "P3\n5 3\n255\n";
    ppm_str += "255 0 0 0 0 0 0 0 0 0 0 0 0 0 0\n";
    ppm_str += "0 0 0 0 0 0 0 128 0 0 0 0 0 0 0\n";
    ppm_str += "0 0 0 0 0 0 0 0 0 0 0 0 0 0 255\n";

    EXPECT_EQ(canvas.to_ppm(a), ppm_str);

}

TEST(CanvasTest, printPPMTwo) {
    Canvas a = Canvas(10, 2, Color(1, 0.8, 0.6));
    std::string ppm_str = "P3\n10 2\n255\n";
    ppm_str += "255 204 153 255 204 153 255 204 153 255 204 153 255 204 153 255 204\n";
    ppm_str += "153 255 204 153 255 204 153 255 204 153 255 204 153\n";
    ppm_str += "255 204 153 255 204 153 255 204 153 255 204 153 255 204 153 255 204\n";
    ppm_str += "153 255 204 153 255 204 153 255 204 153 255 204 153\n";

    EXPECT_EQ(canvas.to_ppm(a), ppm_str);
}
