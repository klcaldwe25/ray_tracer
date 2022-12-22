#include <vector>

#ifndef RAY_TRACER_MATRIX_H
#define RAY_TRACER_MATRIX_H

class Matrix {
    protected:
        int _rows;
        int _cols;
        std::vector< std::vector<float> > _matrix;

    public:
        Matrix() {}

        Matrix(int rows, int cols) {
            _rows = rows;
            _cols = cols;

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
            return _rows;
        }

        int getCols() {
            return _cols;
        }

        float getCell(int row, int col) {
            return _matrix[row][col];
        }

        std::vector< std::vector<float> > getMatrix() {
            return _matrix;
        }

        bool isEqual(Matrix a) {

            for (int i=0; i<_rows; i++) {
                for (int j=0; j<_cols; j++) {
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

            for (int i=0; i<_rows; i++) {
                for (int j=0; j<b.getCols(); j++) {
                    value = 0;
                    for (int k=0; k<_cols; k++) {
                        value += (_matrix[i][k] * b.getCell(k, j));
                    }
                    c.setCell(i, j, value);
                }
            } 

            return c;
        } 

        Matrix transpose() {
            Matrix a = Matrix(_rows, _cols);

            for (int i=0; i<_rows; i++) {
                for (int j=0; j<_cols; j++) {
                    a.setCell(i, j, _matrix[j][i]);
                }
            }

            return a;
        }

        float determinant() {
            if (_rows == 2 && _cols == 2) {
                return (_matrix[0][0] * _matrix[1][1]) - (_matrix[0][1] * _matrix[1][0]);
            }

            float det = 0;

            for (int i=0; i<_cols; i++) {
                det += _matrix[0][i] * cofactor(0, i);
            }

            return det;
        }

        Matrix submatrix(int row, int col) {
            Matrix a = Matrix((_rows - 1), (_cols - 1));

            int row1 = 0;
            int col1 = 0;
            for (int i=0; i<_rows; i++) {
                if (i != row) {
                    for (int j=0; j<_cols; j++) {
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
                std::cout << "Not invertible\n";
                throw std::invalid_argument("Not invertible");
            }

            Matrix a = Matrix(_rows, _cols);

            float det = determinant();
            float c = 0;

            for (int i=0; i<_rows; i++) {
                for (int j=0; j<_cols; j++) {
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

class IdentityMatrix : public Matrix { 
    public:
        IdentityMatrix() {
            _rows = 4;
            _cols = 4;

            for (int i=0; i<4; i++) {
                std::vector<float> v1;
                for (int j=0; j<4; j++) {
                    if (i == j) {
                        v1.push_back(1);
                    } else {
                        v1.push_back(0);
                    }
                }
                _matrix.push_back(v1);
            }
        }
    
        Matrix iMultiply (Matrix a) {
            return a;
        }
};

class TranslationMatrix : public Matrix {
    public:
        TranslationMatrix(float x, float y, float z) {
            _rows = 4;
            _cols = 4;
            
            _matrix.push_back({1, 0, 0, x});
            _matrix.push_back({0, 1, 0, y});
            _matrix.push_back({0, 0, 1, z});
            _matrix.push_back({0, 0, 0, 1});

        }
};

class ScalingMatrix : public Matrix {
    public:
        ScalingMatrix(float x, float y, float z) {
            _rows = 4;
            _cols = 4;

            _matrix.push_back({x, 0, 0, 0});
            _matrix.push_back({0, y, 0, 0});
            _matrix.push_back({0, 0, z, 0});
            _matrix.push_back({0, 0, 0, 1});

        }
};

#endif