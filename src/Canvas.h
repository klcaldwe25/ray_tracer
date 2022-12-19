#include "Color.h"
#include <vector>
#include <string>

#ifndef RAY_TRACER_CANVAS_H
#define RAY_TRACER_CANVAS_H

class Canvas {
    protected:
        int _width;
        int _height;
        std::vector< std::vector<Color> > _grid;
    
    public:
        Canvas(){}

        Canvas(int width, int height, Color color) {
            _width = width;
            _height = height;
            for(int i=0; i<height; i++) {
                std::vector<Color> col;

                for (int k=0; k<width; k++) {
                    col.push_back(color);
                }

                _grid.push_back(col);
            }
        }

        void setWidth(int width) {
            _width = width;
        }

        void setHeight(int height) {
            _height = height;
        }

        void setPixel(int col, int row, Color color) {
            _grid[row][col] = color;
        }

        float getWidth() {
            return _width;
        }

        float getHeight() {
            return _height;
        }

        std::vector< std::vector<Color> > getGrid() {
            return _grid;
        }

        Color getPixel(int col, int row) {
            return _grid[row][col];
        }

        void printPixel(int row, int col) {
            std::cout << "( " << _grid[row][col].getRed() << ", " << _grid[row][col].getGreen() << ", " << _grid[row][col].getBlue() << " )\n";
        }

        std::string to_ppm(Canvas canvas) {
            std::string value;
            std::string line;
            int height = canvas.getHeight();
            int width = canvas.getWidth();
            std::vector< std::vector<Color> > grid = canvas.getGrid();

            std::string ppm_string = "P3\n" + 
                std::to_string(width) + " " + std::to_string(height) + "\n255\n";  


            for (int row=0; row<height; row++) {
                line = "";
                for (int col=0; col<width; col++) {
                    std::vector<float> colors;
                    colors.push_back(grid[row][col].getRed());
                    colors.push_back(grid[row][col].getGreen());
                    colors.push_back(grid[row][col].getBlue());
                    for (float color : colors) {
                        if (color < 0) {
                            value = "0 ";
                        } else if (color > 1) {
                            value = "255 ";
                        } else {
                            value = std::to_string( std::lround(255 * color) ) + " ";
                        }

                        if ( (line.length() + value.length()) > 70 ) {
                            line.replace(line.size() - 1, 1, "\n");
                            ppm_string = ppm_string + line;
                            line = "";
                        }
                        line = line + value;
                    }
                }
                line.replace(line.size() - 1, 1, "\n");
                ppm_string = ppm_string + line;
            }

            return ppm_string;
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