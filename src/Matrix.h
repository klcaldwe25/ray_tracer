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
            Matrix self = *this;

            self._matrix[0][0] = x;
            self._matrix[1][0] = y;
            self._matrix[2][0] = z;
            self._matrix[3][0] = 1;

            return self;
        }

        // VECTOR
        Matrix vectorMatrix(float x, float y, float z) {
            Matrix self = *this;

            self._matrix[0][0] = x;
            self._matrix[1][0] = y;
            self._matrix[2][0] = z;
            self._matrix[3][0] = 0;

            return self;
        }

        Matrix add(Matrix b) {
            Matrix self = *this;

            self._matrix[0][0] += b.getCell(0, 0);
            self._matrix[1][0] += b.getCell(1, 0);
            self._matrix[2][0] += b.getCell(2, 0);
            self._matrix[3][0] += b.getCell(3, 0);

            return self;
        }

        Matrix subtract(Matrix b) {
            Matrix self = *this;

            self._matrix[0][0] -= b.getCell(0, 0);
            self._matrix[1][0] -= b.getCell(1, 0);
            self._matrix[2][0] -= b.getCell(2, 0);
            self._matrix[3][0] -= b.getCell(3, 0);

            return self;
        }    

        Matrix negate() {
            Matrix self = *this;

            self._matrix[0][0] = 0 - self.getCell(0, 0);
            self._matrix[1][0] = 0 - self.getCell(1, 0);
            self._matrix[2][0] = 0 - self.getCell(2, 0);
            self._matrix[3][0] = 0 - self.getCell(3, 0);

            return self;
        }   

        Matrix multiplyScalar(float b) {
            Matrix self = *this;
            
            self._matrix[0][0] *= b;
            self._matrix[1][0] *= b;
            self._matrix[2][0] *= b;
            self._matrix[3][0] *= b;

            return self;
        }          

        Matrix divideScalar(float b) {
            Matrix self = *this;
            
            self._matrix[0][0] /= b;
            self._matrix[1][0] /= b;
            self._matrix[2][0] /= b;
            self._matrix[3][0] /= b;

            return self;
        } 

        float magnitude() {
            return std::sqrt( 
                std::pow(this->getCell(0,0), 2.0) + 
                std::pow(this->getCell(1,0), 2.0) + 
                std::pow(this->getCell(2,0), 2.0) 
            );
        }

        Matrix normalize() {
            float magnitude = this->magnitude();

            return Matrix(4,1).vectorMatrix(this->getCell(0,0) / magnitude, 
                                            this->getCell(1,0) / magnitude, 
                                            this->getCell(2,0) / magnitude);
            
        }

        float dot(Matrix b) {
            Matrix self = *this;

            return ( 
                (self._matrix[0][0] * b.getCell(0,0)) +
                (self._matrix[1][0] * b.getCell(1,0)) +
                (self._matrix[2][0] * b.getCell(2,0)) +
                (self._matrix[3][0] * b.getCell(3,0))
            );             
        }

        Matrix cross(Matrix b) {
            Matrix self = *this;

            self._matrix[0][0] = ((self._matrix[1][0] * b.getCell(2,0)) - (self._matrix[2][0] * b.getCell(1,0)));
            self._matrix[1][0] = ((self._matrix[2][0] * b.getCell(0,0)) - (self._matrix[0][0] * b.getCell(2,0)));
            self._matrix[2][0] = ((self._matrix[0][0] * b.getCell(1,0)) - (self._matrix[1][0] * b.getCell(0,0)));
            self._matrix[3][0] = 0;

            return self;
        }

        Matrix reflect(Matrix normal) {
            Matrix self = *this;
            return self.subtract(normal.multiplyScalar(2).multiplyScalar(self.dot(normal)));
        }

        // IDENTITY
        Matrix identityMatrix() {
            Matrix self = *this;

            self._matrix[0][0] = 1;
            self._matrix[1][1] = 1;
            self._matrix[2][2] = 1;
            self._matrix[3][3] = 1;

            return self;
        }

        // TRANSLATE
        Matrix translationMatrix(float x, float y, float z) {
            Matrix self = *this;

            self._matrix[0][0] = 1;
            self._matrix[1][1] = 1;
            self._matrix[2][2] = 1;
            self._matrix[3][3] = 1;
            self._matrix[0][3] = x;
            self._matrix[1][3] = y;
            self._matrix[2][3] = z;

            return self;
        }

        Matrix translate(float x, float y, float z) {
            return Matrix(4,4).translationMatrix(x, y, z).multiply(*this);
        }

        // SCALE
        Matrix scalingMatrix(float x, float y, float z) {
            Matrix self = *this;

            self._matrix[0][0] = x;
            self._matrix[1][1] = y;
            self._matrix[2][2] = z;
            self._matrix[3][3] = 1;

            return self;           
        }

        Matrix scale (float x, float y, float z) {
            return Matrix(4,4).scalingMatrix(x, y, z).multiply(*this);
        }

        // ROTATE        
        Matrix x_rotation(float r) {
            Matrix self = *this;

            self._matrix[0][0] = 1;
            self._matrix[1][1] = cos(r);
            self._matrix[1][2] = -( sin(r) );
            self._matrix[2][1] = sin(r);
            self._matrix[2][2] = cos(r);
            self._matrix[3][3] = 1;

            return self;
        }

        Matrix y_rotation(float r) {
            Matrix self = *this;

            self._matrix[0][0] = cos(r);
            self._matrix[1][1] = 1;
            self._matrix[0][2] = sin(r);
            self._matrix[2][0] = -( sin(r) );
            self._matrix[2][2] = cos(r);
            self._matrix[3][3] = 1;

            return self;
        } 

        Matrix z_rotation(float r) {
            Matrix self = *this;

            self._matrix[0][0] = cos(r);
            self._matrix[0][1] = -( sin(r) );
            self._matrix[1][0] = sin(r) ;
            self._matrix[1][1] = cos(r);
            self._matrix[2][2] = 1;
            self._matrix[3][3] = 1;

            return self;
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
            Matrix self = *this;

            self._matrix[0][0] = 1;
            self._matrix[0][1] = xY;
            self._matrix[0][2] = xZ;
            self._matrix[1][0] = yX;
            self._matrix[1][1] = 1;
            self._matrix[1][2] = yZ;
            self._matrix[2][0] = zX;
            self._matrix[2][1] = zY;
            self._matrix[2][2] = 1;
            self._matrix[3][3] = 1;   

            return self;        
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
            Matrix self = *this;     

            if (!self.invertible()) {
                throw std::invalid_argument("Not invertible");
            }

            float det = self.determinant();
            float c = 0;

            for (int i=0; i<self.mRows; i++) {
                for (int j=0; j<self.mCols; j++) {
                    c = cofactor(i, j);
                    self.setCell(j, i, (c/det) );
                }
            }

            return self;
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