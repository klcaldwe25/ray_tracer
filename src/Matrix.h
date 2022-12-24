#include <vector>
#include <math.h>

#ifndef RAY_TRACER_MATRIX_H
#define RAY_TRACER_MATRIX_H

class RotationMatrix;

class Matrix {
    protected:
        int mRows;
        int mCols;
        std::vector< std::vector<float> > _matrix;

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
                _matrix.push_back(v1);
            }
        }

        Matrix pointMatrix(float x, float y, float z) {
            Matrix p = *this;

            p._matrix[0][0] = x;
            p._matrix[1][0] = y;
            p._matrix[2][0] = z;
            p._matrix[3][0] = 1;

            return p;
        }

        Matrix vectorMatrix(float x, float y, float z) {
            Matrix p = *this;

            p._matrix[0][0] = x;
            p._matrix[1][0] = y;
            p._matrix[2][0] = z;
            p._matrix[3][1] = 1;

            return p;
        }

        Matrix identityMatrix() {
            Matrix p = *this;

            p._matrix[0][0] = 1;
            p._matrix[1][1] = 1;
            p._matrix[2][2] = 1;
            p._matrix[3][3] = 1;

            return p;
        }

        Matrix translationMatrix(float x, float y, float z) {
            Matrix p = *this;

            p._matrix[0][0] = 1;
            p._matrix[1][1] = 1;
            p._matrix[2][2] = 1;
            p._matrix[3][3] = 1;
            p._matrix[0][3] = x;
            p._matrix[1][3] = y;
            p._matrix[2][3] = z;

            return p;
        }

        Matrix scalingMatrix(float x, float y, float z) {
            Matrix p = *this;

            p._matrix[0][0] = x;
            p._matrix[1][1] = y;
            p._matrix[2][2] = z;
            p._matrix[3][3] = 1;

            return p;           
        }

        
        Matrix x_rotation(float r) {
            Matrix a = *this;

            a._matrix[0][0] = 1;
            a._matrix[1][1] = cos(r);
            a._matrix[1][2] = -( sin(r) );
            a._matrix[2][1] = sin(r);
            a._matrix[2][2] = cos(r);
            a._matrix[3][3] = 1;

            return a;
        }

        Matrix y_rotation(float r) {
            Matrix a = *this;

            a._matrix[0][0] = cos(r);
            a._matrix[1][1] = 1;
            a._matrix[0][2] = sin(r);
            a._matrix[2][0] = -( sin(r) );
            a._matrix[2][2] = cos(r);
            a._matrix[3][3] = 1;

            return a;
        } 

        Matrix z_rotation(float r) {
            Matrix a = *this;

            a._matrix[0][0] = cos(r);
            a._matrix[0][1] = -( sin(r) );
            a._matrix[1][0] = sin(r) ;
            a._matrix[1][1] = cos(r);
            a._matrix[2][2] = 1;
            a._matrix[3][3] = 1;

            return a;
        } 

        Matrix shearingMatrix(float xY, float xZ, float yX, float yZ, float zX, float zY) {
            Matrix a = *this;

            a._matrix[0][0] = 1;
            a._matrix[0][1] = xY;
            a._matrix[0][2] = xZ;
            a._matrix[1][0] = yX;
            a._matrix[1][1] = 1;
            a._matrix[1][2] = yZ;
            a._matrix[2][0] = zX;
            a._matrix[2][1] = zY;
            a._matrix[2][2] = 1;
            a._matrix[3][3] = 1;   

            return a;        
        }

        Matrix x_rotate(float rad) {
            return Matrix(4,4).x_rotation(rad).multiply(*this);
        }

        Matrix y_rotate(float rad) {
            return Matrix(4,4).y_rotation(rad).multiply(*this);
        }

        Matrix z_rotate(float rad) {
            return Matrix(4,4).z_rotation(rad).multiply(*this);
        }        

        Matrix translate(float x, float y, float z) {
            return Matrix(4,4).translationMatrix(x, y, z).multiply(*this);
        }

        Matrix scale (float x, float y, float z) {
            return Matrix(4,4).scalingMatrix(x, y, z).multiply(*this);
        }

        void setCell(int row, int col, float value) {
            _matrix[row][col] = value;
        }

        int getRows() {
            return mRows;
        }

        int getCols() {
            return mCols;
        }

        float getCell(int row, int col) {
            return _matrix[row][col];
        }

        std::vector< std::vector<float> > getMatrix() {
            return _matrix;
        }

        bool isEqual(Matrix a) {

            for (int i=0; i<mRows; i++) {
                for (int j=0; j<mCols; j++) {
                    if (equal(_matrix[i][j], a.getCell(i, j)) == false) {
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
                        value += (_matrix[i][k] * b.getCell(k, j));
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
                    a.setCell(i, j, _matrix[j][i]);
                }
            }

            return a;
        }

        float determinant() {
            if (mRows == 2 && mCols == 2) {
                return (_matrix[0][0] * _matrix[1][1]) - (_matrix[0][1] * _matrix[1][0]);
            }

            float det = 0;

            for (int i=0; i<mCols; i++) {
                det += _matrix[0][i] * cofactor(0, i);
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
                            a.setCell(row1, col1, _matrix[i][j]);
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

#endif