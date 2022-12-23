#include <vector>
#include <math.h>

#ifndef RAY_TRACER_MATRIX_H
#define RAY_TRACER_MATRIX_H

class Matrix {
    protected:
        int mRows;
        int mCols;
        std::vector< std::vector<float> > mMatrix;

    public:
        Matrix() {}

        Matrix(int rows, int cols) {
            mRows = rows;
            mCols = cols;

            for (int i=0; i<rows; i++) {
                std::vector<float> v1;
                for (int j=0; j<cols; j++) {
                    v1.push_back(0.0);
                }
                mMatrix.push_back(v1);
            }
        }

        void setCell(int row, int col, float value) {
            mMatrix[row][col] = value;
        }

        int getRows() {
            return mRows;
        }

        int getCols() {
            return mCols;
        }

        float getCell(int row, int col) {
            return mMatrix[row][col];
        }

        std::vector< std::vector<float> > getMatrix() {
            return mMatrix;
        }

        bool isEqual(Matrix a) {

            for (int i=0; i<mRows; i++) {
                for (int j=0; j<mCols; j++) {
                    if (equal(mMatrix[i][j], a.getCell(i, j)) == false) {
                        return false;
                    }
                }
            }
            return true;
        }

        Matrix multiply(Matrix b) {

            Matrix c = Matrix(b.getRows(), b.getCols());
            float value = 0;

            for (int i=0; i<mRows; i++) {
                for (int j=0; j<b.getCols(); j++) {
                    value = 0;
                    for (int k=0; k<mCols; k++) {
                        value += (mMatrix[i][k] * b.getCell(k, j));
                    }
                    c.setCell(i, j, value);
                }
            } 

            return c;
        } 

        Matrix transpose() {
            Matrix a = Matrix(mRows, mCols);

            for (int i=0; i<mRows; i++) {
                for (int j=0; j<mCols; j++) {
                    a.setCell(i, j, mMatrix[j][i]);
                }
            }

            return a;
        }

        float determinant() {
            if (mRows == 2 && mCols == 2) {
                return (mMatrix[0][0] * mMatrix[1][1]) - (mMatrix[0][1] * mMatrix[1][0]);
            }

            float det = 0;

            for (int i=0; i<mCols; i++) {
                det += mMatrix[0][i] * cofactor(0, i);
            }

            return det;
        }

        Matrix submatrix(int row, int col) {
            Matrix a = Matrix((mRows - 1), (mCols - 1));

            int row1 = 0;
            int col1 = 0;
            for (int i=0; i<mRows; i++) {
                if (i != row) {
                    for (int j=0; j<mCols; j++) {
                        if (j != col) {
                            a.setCell(row1, col1, mMatrix[i][j]);
                            col1++;
                        }
                    }
                    col1 = 0;
                    row1++;               
                }
            }

            return a;
        }

        float minor(int row, int col) {
            return submatrix(row, col).determinant();
        }

        float cofactor(int row, int col) {
            float minor = submatrix(row, col).determinant();

            if ((row + col) % 2 != 0) {
                minor = minor * -1;
            }

            return minor;
        }

        bool invertible() {
            if (determinant() != 0) {
                return true;
            } else {
                return false;
            }
        }

        Matrix inverse() {
            if (!invertible()) {
                throw std::invalid_argument("Not invertible");
            }

            Matrix a = Matrix(mRows, mCols);

            float det = determinant();
            float c = 0;

            for (int i=0; i<mRows; i++) {
                for (int j=0; j<mCols; j++) {
                    c = cofactor(i, j);
                    a.setCell(j, i, (c/det) );
                }
            }

            return a;
        }

        bool equal(float a, float b) {

            float EPSILON = 0.00001;

            if (std::abs(a - b) < EPSILON) {
                return true;
            } else {
                return false;
            }
        }        
};

class PointMatrix : public Matrix {
    public:
        PointMatrix(float x, float y, float z) {
            mRows = 4;
            mCols = 1;

            mMatrix.push_back({x});
            mMatrix.push_back({y});
            mMatrix.push_back({z});
            mMatrix.push_back({1});            
        }
};

class VectorMatrix : public Matrix {
    public:
        VectorMatrix(float x, float y, float z) {
            mRows = 4;
            mCols = 1;

            mMatrix.push_back({x});
            mMatrix.push_back({y});
            mMatrix.push_back({z});
            mMatrix.push_back({0});            
        }
};

class IdentityMatrix : public Matrix { 
    public:
        IdentityMatrix() {
            mRows = 4;
            mCols = 4;

            for (int i=0; i<4; i++) {
                std::vector<float> v1;
                for (int j=0; j<4; j++) {
                    if (i == j) {
                        v1.push_back(1);
                    } else {
                        v1.push_back(0);
                    }
                }
                mMatrix.push_back(v1);
            }
        }
    
        Matrix iMultiply (Matrix a) {
            return a;
        }
};

class TranslationMatrix : public Matrix {
    public:
        TranslationMatrix(float x, float y, float z) {
            mRows = 4;
            mCols = 4;

            mMatrix.push_back({1, 0, 0, x});
            mMatrix.push_back({0, 1, 0, y});
            mMatrix.push_back({0, 0, 1, z});
            mMatrix.push_back({0, 0, 0, 1});

        }
};

class ScalingMatrix : public Matrix {
    public:
        ScalingMatrix(float x, float y, float z) {
            mRows = 4;
            mCols = 4;

            mMatrix.push_back({x, 0, 0, 0});
            mMatrix.push_back({0, y, 0, 0});
            mMatrix.push_back({0, 0, z, 0});
            mMatrix.push_back({0, 0, 0, 1});

        }
};

class RotationMatrix : public Matrix {
    public:
        RotationMatrix() {
            mRows = 4;
            mCols = 4;

            for (int i=0; i<mRows; i++) {
                std::vector<float> v1;
                for (int j=0; j<mCols; j++) {
                    if (i == j) {
                        v1.push_back(1);
                    } else {
                        v1.push_back(0);
                    }
                }
                mMatrix.push_back(v1);
            }      
        }

        void x_rotation(float r) {
            mMatrix[1][1] = cos(r);
            mMatrix[1][2] = -( sin(r) );
            mMatrix[2][1] = sin(r);
            mMatrix[2][2] = cos(r);
        }

        void y_rotation(float r) {
            mMatrix[0][0] = cos(r);
            mMatrix[0][2] = sin(r);
            mMatrix[2][0] = -( sin(r) );
            mMatrix[2][2] = cos(r);
        }        

        void z_rotation(float r) {
            mMatrix[0][0] = cos(r);
            mMatrix[0][1] = -( sin(r) );
            mMatrix[1][0] = sin(r) ;
            mMatrix[1][1] = cos(r);
        } 
};

class ShearingMatrix : public Matrix {
    public:
        ShearingMatrix(float xY, float xZ, float yX, float yZ, float zX, float zY) {
            mRows = 4;
            mCols = 4;

            mMatrix.push_back({1, xY, xZ, 0});
            mMatrix.push_back({yX, 1, yZ, 0});
            mMatrix.push_back({zX, zY, 1, 0});
            mMatrix.push_back({0, 0, 0, 1});            
        }
};

#endif