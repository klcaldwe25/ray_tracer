#include "gtest/gtest.h"
#include "Ray.h"

TEST (RayTest, setRay) {
    Matrix origin = Matrix(4, 1).pointMatrix(1, 2, 3);
    Matrix direction = Matrix(4, 1).vectorMatrix(4, 5, 6);

    Ray r = Ray(origin, direction);

    EXPECT_TRUE(origin.isEqual(r.getOrigin()));
    EXPECT_TRUE(direction.isEqual(r.getDirection()));
}

TEST (RayTest, position) {
    Ray r = Ray(Matrix(4,1).pointMatrix(2, 3, 4), Matrix(4, 1).vectorMatrix(1, 0, 0));

    Matrix p1 = Matrix(4,1).pointMatrix(2, 3, 4);
    Matrix p2 = Matrix(4,1).pointMatrix(3, 3, 4);
    Matrix p3 = Matrix(4,1).pointMatrix(1, 3, 4);
    Matrix p4 = Matrix(4,1).pointMatrix(4.5, 3, 4);

    EXPECT_TRUE(p1.isEqual(r.position(0)));
    EXPECT_TRUE(p2.isEqual(r.position(1)));
    EXPECT_TRUE(p3.isEqual(r.position(-1)));
    EXPECT_TRUE(p4.isEqual(r.position(2.5)));    
}