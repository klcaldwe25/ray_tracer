#include <vector>
#include <cmath>

#ifndef RAY_TRACER_MATRIX_H
#define RAY_TRACER_MATRIX_H

class Matrix {
    protected:
        int mRows;
        int mCols;
        std::vector< std::vector<float> > _matrix;

    public:
        // GETTERS / SETTERS
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

        // BASIC MATRIC ACTIONS
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

        bool equal(float a, float b) {

            float EPSILON = 0.00001;

            if (std::abs(a - b) < EPSILON) {
                return true;
            } else {
                return false;
            }
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

        // POINT
        Matrix pointMatrix(float x, float y, float z) {
            Matrix p = *this;

            p._matrix[0][0] = x;
            p._matrix[1][0] = y;
            p._matrix[2][0] = z;
            p._matrix[3][0] = 1;

            return p;
        }

        // VECTOR
        Matrix vectorMatrix(float x, float y, float z) {
            Matrix p = *this;

            p._matrix[0][0] = x;
            p._matrix[1][0] = y;
            p._matrix[2][0] = z;
            p._matrix[3][1] = 1;

            return p;
        }

        Matrix add(Matrix b) {
            Matrix a = *this;

            a._matrix[0][0] += b.getCell(0, 0);
            a._matrix[1][0] += b.getCell(1, 0);
            a._matrix[2][0] += b.getCell(2, 0);
            a._matrix[3][0] += b.getCell(3, 0);

            return a;
        }

        Matrix subtract(Matrix b) {
            Matrix a = *this;

            a._matrix[0][0] -= b.getCell(0, 0);
            a._matrix[1][0] -= b.getCell(1, 0);
            a._matrix[2][0] -= b.getCell(2, 0);
            a._matrix[3][0] -= b.getCell(3, 0);

            return a;
        }    

        Matrix negate() {
            Matrix a = *this;

            a._matrix[0][0] = 0 - a.getCell(0, 0);
            a._matrix[1][0] = 0 - a.getCell(1, 0);
            a._matrix[2][0] = 0 - a.getCell(2, 0);
            a._matrix[3][0] = 0 - a.getCell(3, 0);

            return a;
        }   

        Matrix multiplyScalar(float b) {
            Matrix a = *this;
            
            a._matrix[0][0] *= b;
            a._matrix[1][0] *= b;
            a._matrix[2][0] *= b;
            a._matrix[3][0] *= b;

            return a;
        }          

        Matrix divideScalar(float b) {
            Matrix a = *this;
            
            a._matrix[0][0] /= b;
            a._matrix[1][0] /= b;
            a._matrix[2][0] /= b;
            a._matrix[3][0] /= b;

            return a;
        } 

        float magnitude() {
            Matrix a = *this;

            return std::sqrt( 
                std::pow(a._matrix[0][0], 2.0) + 
                std::pow(a._matrix[1][0], 2.0) + 
                std::pow(a._matrix[2][0], 2.0) 
            );
        }

        Matrix normalize() {
            Matrix a = *this;

            float magnitude = a.magnitude();
            
            a._matrix[0][0] /= magnitude;
            a._matrix[1][0] /= magnitude;
            a._matrix[2][0] /= magnitude;
            a._matrix[3][0] /= magnitude;

            return a;            
        }

        float dot(Matrix b) {
            Matrix a = *this;

            return ( 
                (a._matrix[0][0] * b.getCell(0,0)) +
                (a._matrix[1][0] * b.getCell(1,0)) +
                (a._matrix[2][0] * b.getCell(2,0)) +
                (a._matrix[3][0] * b.getCell(3,0))
            );             
        }

        Matrix cross(Matrix b) {
            Matrix a = *this;

            a._matrix[0][0] = ((a._matrix[1][0] * b.getCell(2,0)) - (a._matrix[2][0] * b.getCell(1,0)));
            a._matrix[1][0] = ((a._matrix[2][0] * b.getCell(0,0)) - (a._matrix[0][0] * b.getCell(2,0)));
            a._matrix[2][0] = ((a._matrix[0][0] * b.getCell(1,0)) - (a._matrix[1][0] * b.getCell(0,0)));
            a._matrix[3][0] = 0;

            return a;
        }

        // IDENTITY
        Matrix identityMatrix() {
            Matrix p = *this;

            p._matrix[0][0] = 1;
            p._matrix[1][1] = 1;
            p._matrix[2][2] = 1;
            p._matrix[3][3] = 1;

            return p;
        }

        // TRANSLATE
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

        Matrix translate(float x, float y, float z) {
            return Matrix(4,4).translationMatrix(x, y, z).multiply(*this);
        }

        // SCALE
        Matrix scalingMatrix(float x, float y, float z) {
            Matrix p = *this;

            p._matrix[0][0] = x;
            p._matrix[1][1] = y;
            p._matrix[2][2] = z;
            p._matrix[3][3] = 1;

            return p;           
        }

        Matrix scale (float x, float y, float z) {
            return Matrix(4,4).scalingMatrix(x, y, z).multiply(*this);
        }

        // ROTATE        
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

        Matrix x_rotate(float rad) {
            return Matrix(4,4).x_rotation(rad).multiply(*this);
        }

        Matrix y_rotate(float rad) {
            return Matrix(4,4).y_rotation(rad).multiply(*this);
        }

        Matrix z_rotate(float rad) {
            return Matrix(4,4).z_rotation(rad).multiply(*this);
        }  

        // SHEARING
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

        // TRANSPOSE
        Matrix transpose() {
            Matrix a = Matrix(mRows, mCols);

            for (int i=0; i<mRows; i++) {
                for (int j=0; j<mCols; j++) {
                    a.setCell(i, j, _matrix[j][i]);
                }
            }

            return a;
        }

        // INVERSE ACTIONS
        Matrix inverse() {
            Matrix a = *this;     

            if (!a.invertible()) {
                throw std::invalid_argument("Not invertible");
            }

            float det = a.determinant();
            float c = 0;

            for (int i=0; i<a.mRows; i++) {
                for (int j=0; j<a.mCols; j++) {
                    c = cofactor(i, j);
                    a.setCell(j, i, (c/det) );
                }
            }

            return a;
        }

        bool invertible() {
            if (this->determinant() != 0) {
                return true;
            } else {
                return false;
            }
        }

        float determinant() {
            if (mRows == 2 && mCols == 2) {
                return (this->_matrix[0][0] * this->_matrix[1][1]) - (this->_matrix[0][1] * this->_matrix[1][0]);
            }

            float det = 0;

            for (int i=0; i<this->mCols; i++) {
                det += this->_matrix[0][i] * this->cofactor(0, i);
            }

            return det;
        }

        Matrix submatrix(int row, int col) {
            Matrix a = Matrix((mRows - 1), (mCols - 1));

            int row1 = 0;
            int col1 = 0;
            for (int i=0; i<this->mRows; i++) {
                if (i != row) {
                    for (int j=0; j<this->mCols; j++) {
                        if (j != col) {
                            a.setCell(row1, col1, this->_matrix[i][j]);
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
            return this->submatrix(row, col).determinant();
        }

        float cofactor(int row, int col) {
            float minor = this->submatrix(row, col).determinant();

            if ((row + col) % 2 != 0) {
                minor = minor * -1;
            }

            return minor;
        }     
};

#endif