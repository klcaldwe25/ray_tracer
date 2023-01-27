#include "gtest/gtest.h"
#include "Matrix.h"
#include "Tuple.h"
#include <cmath>

TEST(MatrixTest, getCell) {
    Matrix a = Matrix(2, 2);
    EXPECT_TRUE(a.equal(a.getCell(0, 0), 0));
}

TEST(MatrixTest, setCell) {
    Matrix a = Matrix(2, 2);
    a.setCell(0, 0, -3);
    a.setCell(0, 1, 5);
    a.setCell(1, 0, 1);
    a.setCell(1, 1, -2);

    EXPECT_TRUE(a.equal(a.getCell(0, 0), -3));
    EXPECT_TRUE(a.equal(a.getCell(0, 1), 5));
    EXPECT_TRUE(a.equal(a.getCell(1, 0), 1));
    EXPECT_TRUE(a.equal(a.getCell(1, 1), -2));
}

TEST(MatrixTest, isEqual) {
    Matrix a = Matrix(2, 2);
    a.setCell(0, 0, -3);
    a.setCell(0, 1, 5);
    a.setCell(1, 0, 1);
    a.setCell(1, 1, -2);

    Matrix b = Matrix(2, 2);
    b.setCell(0, 0, -3);
    b.setCell(0, 1, 5);
    b.setCell(1, 0, 1);
    b.setCell(1, 1, -2);   

    EXPECT_TRUE(a.isEqual(b));

    Matrix c = Matrix(2, 2);
    c.setCell(0, 0, -3);
    c.setCell(0, 1, 5);
    c.setCell(1, 0, 1);
    c.setCell(1, 1, -2.5);     

    EXPECT_FALSE(a.isEqual(c));
}

TEST(MatrixTest, multiplyOne) {
    Matrix a = Matrix(4, 4);
    a.setCell(0, 0, 1);
    a.setCell(0, 1, 2);
    a.setCell(0, 2, 3);
    a.setCell(0, 3, 4);
    a.setCell(1, 0, 5);
    a.setCell(1, 1, 6);
    a.setCell(1, 2, 7);
    a.setCell(1, 3, 8);
    a.setCell(2, 0, 9);
    a.setCell(2, 1, 8);
    a.setCell(2, 2, 7);
    a.setCell(2, 3, 6);    
    a.setCell(3, 0, 5);
    a.setCell(3, 1, 4);
    a.setCell(3, 2, 3);
    a.setCell(3, 3, 2);        

    Matrix b = Matrix(4, 4);
    b.setCell(0, 0, -2);
    b.setCell(0, 1, 1);
    b.setCell(0, 2, 2);
    b.setCell(0, 3, 3);
    b.setCell(1, 0, 3);
    b.setCell(1, 1, 2);
    b.setCell(1, 2, 1);
    b.setCell(1, 3, -1);
    b.setCell(2, 0, 4);
    b.setCell(2, 1, 3);
    b.setCell(2, 2, 6);
    b.setCell(2, 3, 5);    
    b.setCell(3, 0, 1);
    b.setCell(3, 1, 2);
    b.setCell(3, 2, 7);
    b.setCell(3, 3, 8);      

    Matrix c = Matrix(4, 4);

    c.setCell(0, 0, 20);
    c.setCell(0, 1, 22);
    c.setCell(0, 2, 50);
    c.setCell(0, 3, 48);
    c.setCell(1, 0, 44);
    c.setCell(1, 1, 54);
    c.setCell(1, 2, 114);
    c.setCell(1, 3, 108);
    c.setCell(2, 0, 40);
    c.setCell(2, 1, 58);
    c.setCell(2, 2, 110);
    c.setCell(2, 3, 102);    
    c.setCell(3, 0, 16);
    c.setCell(3, 1, 26);
    c.setCell(3, 2, 46);
    c.setCell(3, 3, 42);   

    EXPECT_TRUE(c.isEqual(a.multiply(b)));
}

TEST(MatrixTest, multiplyTwo) {
    Matrix a = Matrix(4, 4);
    a.setCell(0, 0, 1);
    a.setCell(0, 1, 2);
    a.setCell(0, 2, 3);
    a.setCell(0, 3, 4);
    a.setCell(1, 0, 2);
    a.setCell(1, 1, 4);
    a.setCell(1, 2, 4);
    a.setCell(1, 3, 2);
    a.setCell(2, 0, 8);
    a.setCell(2, 1, 6);
    a.setCell(2, 2, 4);
    a.setCell(2, 3, 1);    
    a.setCell(3, 0, 0);
    a.setCell(3, 1, 0);
    a.setCell(3, 2, 0);
    a.setCell(3, 3, 1); 

    Matrix b = Matrix(4, 1);
    b.setCell(0, 0, 1);
    b.setCell(1, 0, 2);
    b.setCell(2, 0, 3);
    b.setCell(3, 0, 1);

    Matrix c = Matrix(4, 1);
    c.setCell(0, 0, 18);
    c.setCell(1, 0, 24);
    c.setCell(2, 0, 33);
    c.setCell(3, 0, 1);

    EXPECT_TRUE(c.isEqual(a.multiply(b)));
}

TEST(MatrixTest, identityMatrixOne) {
    Matrix a = Matrix(4, 4);
    a.setCell(0, 0, 0);
    a.setCell(0, 1, 1);
    a.setCell(0, 2, 2);
    a.setCell(0, 3, 4);
    a.setCell(1, 0, 1);
    a.setCell(1, 1, 2);
    a.setCell(1, 2, 4);
    a.setCell(1, 3, 8);
    a.setCell(2, 0, 2);
    a.setCell(2, 1, 4);
    a.setCell(2, 2, 8);
    a.setCell(2, 3, 16);    
    a.setCell(3, 0, 4);
    a.setCell(3, 1, 8);
    a.setCell(3, 2, 16);
    a.setCell(3, 3, 32); 

    Matrix b = Matrix(4,4).identityMatrix();

   EXPECT_TRUE(a.isEqual(a.multiply(b)));
}

TEST (MatrixTest, identityMatrixTwo) {
    Matrix a = Matrix(4, 1);
    a.setCell(0, 0, 1);
    a.setCell(1, 0, 2);
    a.setCell(2, 0, 3);
    a.setCell(3, 0, 4);    

    Matrix b = Matrix(4,4).identityMatrix();

    EXPECT_TRUE(a.isEqual(b.multiply(a)));    
}

TEST (MatrixTest, transpose) {
    Matrix a = Matrix(4, 4);
    a.setCell(0, 0, 0);
    a.setCell(0, 1, 9);
    a.setCell(0, 2, 3);
    a.setCell(0, 3, 0);
    a.setCell(1, 0, 9);
    a.setCell(1, 1, 8);
    a.setCell(1, 2, 0);
    a.setCell(1, 3, 8);
    a.setCell(2, 0, 1);
    a.setCell(2, 1, 8);
    a.setCell(2, 2, 5);
    a.setCell(2, 3, 3);    
    a.setCell(3, 0, 0);
    a.setCell(3, 1, 0);
    a.setCell(3, 2, 5);
    a.setCell(3, 3, 8);     

    Matrix b = Matrix(4, 4);
    b.setCell(0, 0, 0);
    b.setCell(0, 1, 9);
    b.setCell(0, 2, 1);
    b.setCell(0, 3, 0);
    b.setCell(1, 0, 9);
    b.setCell(1, 1, 8);
    b.setCell(1, 2, 8);
    b.setCell(1, 3, 0);
    b.setCell(2, 0, 3);
    b.setCell(2, 1, 0);
    b.setCell(2, 2, 5);
    b.setCell(2, 3, 5);    
    b.setCell(3, 0, 0);
    b.setCell(3, 1, 8);
    b.setCell(3, 2, 3);
    b.setCell(3, 3, 8);   

    EXPECT_TRUE(b.isEqual(a.transpose())); 
}

TEST (MatrixTest, determinantOne) {
    Matrix a = Matrix(2, 2);
    a.setCell(0, 0, 1);
    a.setCell(0, 1, 5);
    a.setCell(1, 0, -3);
    a.setCell(1, 1, 2);

    EXPECT_TRUE(a.equal(a.determinant(), 17));
}


TEST (MatrixTest, subtestOne) {
    Matrix a = Matrix(3, 3);
    a.setCell(0, 0, 1);
    a.setCell(0, 1, 5);
    a.setCell(0, 2, 0);
    a.setCell(1, 0, -3);
    a.setCell(1, 1, 2);
    a.setCell(1, 2, 7);
    a.setCell(2, 0, 0);
    a.setCell(2, 1, 6);
    a.setCell(2, 2, -3);

    Matrix b = Matrix(2, 2);
    b.setCell(0, 0, -3);
    b.setCell(0, 1, 2);
    b.setCell(1, 0, 0);
    b.setCell(1, 1, 6);   

    EXPECT_TRUE(b.isEqual(a.submatrix(0, 2)));
}

TEST (MatrixTest, subtestTwo) {
    Matrix a = Matrix(4, 4);
    a.setCell(0, 0, -6);
    a.setCell(0, 1, 1);
    a.setCell(0, 2, 1);
    a.setCell(0, 3, 6);
    a.setCell(1, 0, -8);
    a.setCell(1, 1, 5);
    a.setCell(1, 2, 8);
    a.setCell(1, 3, 6);
    a.setCell(2, 0, -1);
    a.setCell(2, 1, 0);
    a.setCell(2, 2, 8);
    a.setCell(2, 3, 2);    
    a.setCell(3, 0, -7);
    a.setCell(3, 1, 1);
    a.setCell(3, 2, -1);
    a.setCell(3, 3, 1);    

    Matrix b = Matrix(3, 3);
    b.setCell(0, 0, -6);
    b.setCell(0, 1, 1);
    b.setCell(0, 2, 6);
    b.setCell(1, 0, -8);
    b.setCell(1, 1, 8);
    b.setCell(1, 2, 6);
    b.setCell(2, 0, -7);
    b.setCell(2, 1, -1);
    b.setCell(2, 2, 1);    

    EXPECT_TRUE(b.isEqual(a.submatrix(2, 1)));    
}

TEST (MatrixTest, minor) {
    Matrix a = Matrix(3, 3);
    a.setCell(0, 0, 3);
    a.setCell(0, 1, 5);
    a.setCell(0, 2, 0);
    a.setCell(1, 0, 2);
    a.setCell(1, 1, -1);
    a.setCell(1, 2, -7);
    a.setCell(2, 0, 6);
    a.setCell(2, 1, -1);
    a.setCell(2, 2, 5);    

    EXPECT_TRUE(a.equal(a.minor(1, 0), 25));
}

TEST (MatrixTest, cofactor) {
    Matrix a = Matrix(3, 3);
    a.setCell(0, 0, 3);
    a.setCell(0, 1, 5);
    a.setCell(0, 2, 0);
    a.setCell(1, 0, 2);
    a.setCell(1, 1, -1);
    a.setCell(1, 2, -7);
    a.setCell(2, 0, 6);
    a.setCell(2, 1, -1);
    a.setCell(2, 2, 5);    

    EXPECT_TRUE(a.equal(a.cofactor(0, 0), -12));
    EXPECT_TRUE(a.equal(a.cofactor(1, 0), -25));

}

TEST (MatrixTest, determinantTwo) {
    Matrix a = Matrix(3, 3);
    a.setCell(0, 0, 1);
    a.setCell(0, 1, 2);
    a.setCell(0, 2, 6);
    a.setCell(1, 0, -5);
    a.setCell(1, 1, 8);
    a.setCell(1, 2, -4);
    a.setCell(2, 0, 2);
    a.setCell(2, 1, 6);
    a.setCell(2, 2, 4); 

    EXPECT_TRUE(a.equal(a.cofactor(0, 0), 56));
    EXPECT_TRUE(a.equal(a.cofactor(0, 1), 12)); 
    EXPECT_TRUE(a.equal(a.cofactor(0, 2), -46));       
    EXPECT_TRUE(a.equal(a.determinant(), -196));     

    Matrix b = Matrix(4, 4);
    b.setCell(0, 0, -2);
    b.setCell(0, 1, -8);
    b.setCell(0, 2, 3);
    b.setCell(0, 3, 5);
    b.setCell(1, 0, -3);
    b.setCell(1, 1, 1);
    b.setCell(1, 2, 7);
    b.setCell(1, 3, 3);
    b.setCell(2, 0, 1);
    b.setCell(2, 1, 2);
    b.setCell(2, 2, -9);
    b.setCell(2, 3, 6);    
    b.setCell(3, 0, -6);
    b.setCell(3, 1, 7);
    b.setCell(3, 2, 7);
    b.setCell(3, 3, -9);     

    EXPECT_TRUE(b.equal(b.cofactor(0, 0), 690));
    EXPECT_TRUE(b.equal(b.cofactor(0, 1), 447)); 
    EXPECT_TRUE(b.equal(b.cofactor(0, 2), 210)); 
    EXPECT_TRUE(b.equal(b.cofactor(0, 3), 51));           
    EXPECT_TRUE(b.equal(b.determinant(), -4071));       
}

TEST (MatrixTest, invertible) {
    Matrix a = Matrix(4, 4);
    a.setCell(0, 0, 6);
    a.setCell(0, 1, 4);
    a.setCell(0, 2, 4);
    a.setCell(0, 3, 4);
    a.setCell(1, 0, 5);
    a.setCell(1, 1, 5);
    a.setCell(1, 2, 7);
    a.setCell(1, 3, 6);
    a.setCell(2, 0, 4);
    a.setCell(2, 1, -9);
    a.setCell(2, 2, 3);
    a.setCell(2, 3, -7);    
    a.setCell(3, 0, 9);
    a.setCell(3, 1, 1);
    a.setCell(3, 2, 7);
    a.setCell(3, 3, -6);   

    EXPECT_TRUE(a.equal(a.determinant(), -2120));  
    EXPECT_TRUE(a.invertible());

    Matrix b = Matrix(4, 4);
    b.setCell(0, 0, -4);
    b.setCell(0, 1, 2);
    b.setCell(0, 2, -2);
    b.setCell(0, 3, -3);
    b.setCell(1, 0, 9);
    b.setCell(1, 1, 6);
    b.setCell(1, 2, 2);
    b.setCell(1, 3, 6);
    b.setCell(2, 0, 0);
    b.setCell(2, 1, -5);
    b.setCell(2, 2, 1);
    b.setCell(2, 3, -5);    
    b.setCell(3, 0, 0);
    b.setCell(3, 1, 0);
    b.setCell(3, 2, 0);
    b.setCell(3, 3, 0);  

    EXPECT_TRUE(b.equal(b.determinant(), 0));  
    EXPECT_FALSE(b.invertible());    
}

TEST (MatrixTest, inverseOne) {
    Matrix a = Matrix(4, 4);
    a.setCell(0, 0, -5);
    a.setCell(0, 1, 2);
    a.setCell(0, 2, 6);
    a.setCell(0, 3, -8);
    a.setCell(1, 0, 1);
    a.setCell(1, 1, -5);
    a.setCell(1, 2, 1);
    a.setCell(1, 3, 8);
    a.setCell(2, 0, 7);
    a.setCell(2, 1, 7);
    a.setCell(2, 2, -6);
    a.setCell(2, 3, -7);    
    a.setCell(3, 0, 1);
    a.setCell(3, 1, -3);
    a.setCell(3, 2, 7);
    a.setCell(3, 3, 4); 

    Matrix b = Matrix(4, 4);
    b.setCell(0, 0, 0.21805);
    b.setCell(0, 1, 0.45113);
    b.setCell(0, 2, 0.24060);
    b.setCell(0, 3, -0.04511);
    b.setCell(1, 0, -0.80827);
    b.setCell(1, 1, -1.45677);
    b.setCell(1, 2, -0.44361);
    b.setCell(1, 3, 0.52068);
    b.setCell(2, 0, -0.07895);
    b.setCell(2, 1, -0.22368);
    b.setCell(2, 2, -0.05263);
    b.setCell(2, 3, 0.19737);    
    b.setCell(3, 0, -0.52256);
    b.setCell(3, 1, -0.81391);
    b.setCell(3, 2, -0.30075);
    b.setCell(3, 3, 0.30639);  

    EXPECT_TRUE(b.isEqual(a.inverse()));
}

TEST (MatrixTest, inverseTwo) {
    Matrix a = Matrix(4, 4);
    a.setCell(0, 0, 8);
    a.setCell(0, 1, -5);
    a.setCell(0, 2, 9);
    a.setCell(0, 3, 2);
    a.setCell(1, 0, 7);
    a.setCell(1, 1, 5);
    a.setCell(1, 2, 6);
    a.setCell(1, 3, 1);
    a.setCell(2, 0, -6);
    a.setCell(2, 1, 0);
    a.setCell(2, 2, 9);
    a.setCell(2, 3, 6);    
    a.setCell(3, 0, -3);
    a.setCell(3, 1, 0);
    a.setCell(3, 2, -9);
    a.setCell(3, 3, -4); 

    Matrix b = Matrix(4, 4);
    b.setCell(0, 0, -0.15385);
    b.setCell(0, 1, -0.15385);
    b.setCell(0, 2, -0.28205);
    b.setCell(0, 3, -0.53846);
    b.setCell(1, 0, -0.07692);
    b.setCell(1, 1, 0.12308);
    b.setCell(1, 2, 0.02564);
    b.setCell(1, 3, 0.03077);
    b.setCell(2, 0, 0.35897);
    b.setCell(2, 1, 0.35897);
    b.setCell(2, 2, 0.43590);
    b.setCell(2, 3, 0.92308);    
    b.setCell(3, 0, -0.69231);
    b.setCell(3, 1, -0.69231);
    b.setCell(3, 2, -0.76923);
    b.setCell(3, 3, -1.92308);  

    EXPECT_TRUE(b.isEqual(a.inverse()));
}

TEST (MatrixTest, inverseThree) {
    Matrix a = Matrix(4, 4);
    a.setCell(0, 0, 9);
    a.setCell(0, 1, 3);
    a.setCell(0, 2, 0);
    a.setCell(0, 3, 9);
    a.setCell(1, 0, -5);
    a.setCell(1, 1, -2);
    a.setCell(1, 2, -6);
    a.setCell(1, 3, -3);
    a.setCell(2, 0, -4);
    a.setCell(2, 1, 9);
    a.setCell(2, 2, 6);
    a.setCell(2, 3, 4);    
    a.setCell(3, 0, -7);
    a.setCell(3, 1, 6);
    a.setCell(3, 2, 6);
    a.setCell(3, 3, 2); 

    Matrix b = Matrix(4, 4);
    b.setCell(0, 0, -0.04074);
    b.setCell(0, 1, -0.07778);
    b.setCell(0, 2, 0.14444);
    b.setCell(0, 3, -0.22222);
    b.setCell(1, 0, -0.07778);
    b.setCell(1, 1, 0.03333);
    b.setCell(1, 2, 0.36667);
    b.setCell(1, 3, -0.33333);
    b.setCell(2, 0, -0.02901);
    b.setCell(2, 1, -0.14630);
    b.setCell(2, 2, -0.10926);
    b.setCell(2, 3, 0.12963);    
    b.setCell(3, 0, 0.17778);
    b.setCell(3, 1, 0.06667);
    b.setCell(3, 2, -0.26667);
    b.setCell(3, 3, 0.33333);  

    EXPECT_TRUE(b.isEqual(a.inverse()));
}

TEST (MatrixTest, inverseFour) {
    Matrix a = Matrix(4, 4);
    a.setCell(0, 0, 3);
    a.setCell(0, 1, -9);
    a.setCell(0, 2, 7);
    a.setCell(0, 3, 3);
    a.setCell(1, 0, 3);
    a.setCell(1, 1, -8);
    a.setCell(1, 2, 2);
    a.setCell(1, 3, -9);
    a.setCell(2, 0, -4);
    a.setCell(2, 1, 4);
    a.setCell(2, 2, 4);
    a.setCell(2, 3, 1); 
    a.setCell(3, 0, -6);
    a.setCell(3, 1, 5);
    a.setCell(3, 2, -1);
    a.setCell(3, 3, 1); 

    Matrix b = Matrix(4, 4);
    b.setCell(0, 0, 8);
    b.setCell(0, 1, 2);
    b.setCell(0, 2, 2);
    b.setCell(0, 3, 2);
    b.setCell(1, 0, 3);
    b.setCell(1, 1, -1);
    b.setCell(1, 2, 7);
    b.setCell(1, 3, 0);
    b.setCell(2, 0, 7);
    b.setCell(2, 1, 0);
    b.setCell(2, 2, 5);
    b.setCell(2, 3, 4);
    b.setCell(3, 0, 6);
    b.setCell(3, 1, -2);
    b.setCell(3, 2, 0);
    b.setCell(3, 3, 5);      

    Matrix c = a.multiply(b);

    EXPECT_TRUE( a.isEqual( c.multiply( b.inverse() ) ) );
}

TEST (MatrixTest, translationOne) {
    Matrix a = Matrix(4,4).translationMatrix(5, -3, 2);

    Matrix p1 = Matrix(4,1).pointMatrix(-3, 4, 5);

    Matrix p2 = Matrix(4,1).pointMatrix(2, 1, 7); 

    EXPECT_TRUE( p2.isEqual(a.multiply(p1) ) );
}

TEST (MatrixTest, translationTwo) {
    Matrix a = Matrix(4,4).translationMatrix(5, -3, 2);

    Matrix b = a.inverse();

    Matrix p1 = Matrix(4,1).pointMatrix(-3, 4, 5);

    Matrix p2 = Matrix(4,1).pointMatrix(-8, 7, 3);

    EXPECT_TRUE( p2.isEqual( b.multiply(p1) ) );

}

TEST (MatrixTest, translationThree) {
    Matrix a = Matrix(4,4).translationMatrix(5, -3, 2);

    Matrix b = a.inverse();

    Matrix p1 = Matrix(4,1).vectorMatrix(-3, 4, 5);

    EXPECT_TRUE( p1.isEqual( b.multiply(p1) ) );

}

TEST (MatrixTest, scalingOne) {
    Matrix a = Matrix(4,4).scalingMatrix(2, 3, 4);

    Matrix p1 = Matrix(4,1).pointMatrix(-4, 6, 8);

    Matrix p2 = Matrix(4,1).pointMatrix(-8, 18, 32); 

    EXPECT_TRUE( p2.isEqual( a.multiply(p1) ) );
}

TEST (MatrixTest, scalingTwo) {
    Matrix a = Matrix(4,4).scalingMatrix(2, 3, 4);

    Matrix p1 = Matrix(4,1).vectorMatrix(-4, 6, 8);

    Matrix p2 = Matrix(4,1).vectorMatrix(-8, 18, 32);  

    EXPECT_TRUE( p2.isEqual( a.multiply(p1) ) );
}

TEST (MatrixTest, scalingThree) {
    Matrix a = Matrix(4,4).scalingMatrix(2, 3, 4);

    Matrix b = a.inverse();

    Matrix p1 = Matrix(4,1).vectorMatrix(-4, 6, 8); 

    Matrix p2 = Matrix(4,1).vectorMatrix(-2, 2, 2);

    EXPECT_TRUE( p2.isEqual( b.multiply(p1) ) );
}

TEST (MatrixTest, scalingFour) {
    Matrix a = Matrix(4,4).scalingMatrix(-1, 1, 1);

    Matrix p1 = Matrix(4,1).pointMatrix(2, 3, 4);

    Matrix p2 = Matrix(4,1).pointMatrix(-2, 3, 4);

    EXPECT_TRUE( p2.isEqual( a.multiply(p1) ) );
}

TEST (MatrixTest, rotationOne) {
    Matrix half_quarter = Matrix(4,4).x_rotation(M_PI/4);
    
    Matrix full_quarter = Matrix(4,4).x_rotation(M_PI/2);   

    Matrix p1 = Matrix(4,1).pointMatrix(0, 1, 0);

    Matrix p2 = Matrix(4,1).pointMatrix( 0, ( std::sqrt(2)/2 ), ( std::sqrt(2)/2 ) );

    Matrix p3 = Matrix(4,1).pointMatrix(0, 0, 1);

    EXPECT_TRUE( p2.isEqual( half_quarter.multiply(p1) ) );

    EXPECT_TRUE( p3.isEqual( full_quarter.multiply(p1) ) );    
}

TEST (MatrixTest, rotationTwo) {
    Matrix half_quarter = Matrix(4,4).x_rotation(M_PI/4);

    Matrix inv = half_quarter.inverse();

    Matrix p1 = Matrix(4,1).pointMatrix(0, 1, 0);

    Matrix p2 = Matrix(4,1).pointMatrix( 0, ( std::sqrt(2)/2 ), -( std::sqrt(2)/2 ) );

    EXPECT_TRUE( p2.isEqual( inv.multiply(p1) ) );
}

TEST (MatrixTest, rotationThree) {
    Matrix half_quarter = Matrix(4,4).y_rotation(M_PI/4);

    Matrix full_quarter = Matrix(4,4).y_rotation(M_PI/2);

    Matrix p1 = Matrix(4,1).pointMatrix(0, 0, 1);

    Matrix p2 = Matrix(4,1).pointMatrix( ( std::sqrt(2)/2 ), 0, ( std::sqrt(2)/2 ) );

    Matrix p3 = Matrix(4,1).pointMatrix( 1, 0, 0);

    EXPECT_TRUE( p2.isEqual( half_quarter.multiply(p1) ) );
    EXPECT_TRUE( p3.isEqual( full_quarter.multiply(p1) ) );
}

TEST (MatrixTest, rotationFour) {
    Matrix half_quarter = Matrix(4,4).z_rotation(M_PI/4);

    Matrix full_quarter = Matrix(4,4).z_rotation(M_PI/2);

    Matrix p1 = Matrix(4,1).pointMatrix(0, 1, 0);

    Matrix p2 = Matrix(4,1).pointMatrix( -(std::sqrt(2)/2), (std::sqrt(2)/2), 0);

    Matrix p3 = Matrix(4,1).pointMatrix(-1, 0, 0);

    EXPECT_TRUE( p2.isEqual( half_quarter.multiply(p1) ) );
    EXPECT_TRUE( p3.isEqual( full_quarter.multiply(p1) ) );
}

TEST (MatrixTest, shearingOne) {
    Matrix a = Matrix(4,4).shearingMatrix(1, 0, 0, 0, 0, 0);

    Matrix p1 = Matrix(4,1).pointMatrix(2, 3, 4);

    Matrix p2 = Matrix(4,1).pointMatrix(5, 3, 4);

    EXPECT_TRUE( p2.isEqual( a.multiply(p1) ) );
}

TEST (MatrixTest, shearingTwo) {
    Matrix a = Matrix(4,4).shearingMatrix(0, 1, 0, 0, 0, 0);

    Matrix p1 = Matrix(4,1).pointMatrix(2, 3, 4);

    Matrix p2 = Matrix(4,1).pointMatrix(6, 3, 4);

    EXPECT_TRUE( p2.isEqual( a.multiply(p1) ) );
}

TEST (MatrixTest, shearingThree) {
    Matrix a = Matrix(4,4).shearingMatrix(0, 0, 1, 0, 0, 0);

    Matrix p1 = Matrix(4,1).pointMatrix(2, 3, 4);

    Matrix p2 = Matrix(4,1).pointMatrix(2, 5, 4);

    EXPECT_TRUE( p2.isEqual( a.multiply(p1) ) );
}

TEST (MatrixTest, shearingFour) {
    Matrix a = Matrix(4,4).shearingMatrix(0, 0, 0, 1, 0, 0);

    Matrix p1 = Matrix(4,1).pointMatrix(2, 3, 4);

    Matrix p2 = Matrix(4,1).pointMatrix(2, 7, 4);

    EXPECT_TRUE( p2.isEqual( a.multiply(p1) ) );
}

TEST (MatrixTest, shearingFive) {
    Matrix a = Matrix(4,4).shearingMatrix(0, 0, 0, 0, 1, 0);

    Matrix p1 = Matrix(4,1).pointMatrix(2, 3, 4);

    Matrix p2 = Matrix(4,1).pointMatrix(2, 3, 6);

    EXPECT_TRUE( p2.isEqual( a.multiply(p1) ) );
}

TEST (MatrixTest, shearingSix) {
    Matrix a = Matrix(4,4).shearingMatrix(0, 0, 0, 0, 0, 1);

    Matrix p1 = Matrix(4,1).pointMatrix(2, 3, 4);

    Matrix p2 = Matrix(4,1).pointMatrix(2, 3, 7);

    EXPECT_TRUE( p2.isEqual( a.multiply(p1) ) );
}

TEST (MatrixTest, chainingOne) {
    Matrix a = Matrix(4,4).x_rotation(M_PI/2);

    Matrix b = Matrix(4,4).scalingMatrix(5, 5, 5);

    Matrix c = Matrix(4,4).translationMatrix(10, 5, 7);

    Matrix p1 = Matrix(4,1).pointMatrix(1, 0, 1);

    Matrix p2 = a.multiply(p1);

    EXPECT_TRUE(p2.isEqual(Matrix(4,1).pointMatrix(1, -1, 0)));

    Matrix p3 = b.multiply(p2);

    EXPECT_TRUE(p3.isEqual(Matrix(4,1).pointMatrix(5, -5, 0)));

    Matrix p4 = c.multiply(p3);

    EXPECT_TRUE(p4.isEqual(Matrix(4,1).pointMatrix(15, 0, 7)));
}

TEST (MatrixTest, chainingTwo) {
    Matrix a = Matrix(4,4).x_rotation(M_PI/2);

    Matrix b = Matrix(4,4).scalingMatrix(5, 5, 5);

    Matrix c = Matrix(4,4).translationMatrix(10, 5, 7);

    Matrix p1 = Matrix(4,1).pointMatrix(1, 0, 1);

    Matrix T = c.multiply( b.multiply(a) );

    Matrix p2 = Matrix(4,1).pointMatrix(15, 0, 7);

    EXPECT_TRUE( p2.isEqual( T.multiply(p1) ) );
}

TEST (MatrixTest, reflectOne) {
    Matrix v = Matrix(4,1).vectorMatrix(1, -1, 0);
    Matrix n = Matrix(4,1).vectorMatrix(0, 1, 0);
    Matrix a = Matrix(4,1).vectorMatrix(1, 1, 0);

    EXPECT_TRUE(a.isEqual(v.reflect(n)));
}

TEST (MatrixTest, reflectTwo) {
    Matrix v = Matrix(4,1).vectorMatrix(0, -1, 0);
    Matrix n = Matrix(4,1).vectorMatrix(sqrt(2)/2, sqrt(2)/2, 0);
    Matrix a = Matrix(4,1).vectorMatrix(1, 0, 0);

    EXPECT_TRUE(a.isEqual(v.reflect(n)));
}