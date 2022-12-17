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

        Canvas(int height, int width) {
            _width = width;
            _height = height;
            for(int i=0; i<height; i++) {
                std::vector<Color> col;

                for (int k=0; k<width; k++) {
                    col.push_back(Color(0, 0, 0));
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

        void setPixel(int row, int col, Color color) {
            _grid[row][col] = color;
        }

        float getWidth() {
            return _width;
        }

        float getHeight() {
            return _height;
        }

        std::vector<std::vector<Color>> getGrid() {
            return _grid;
        }

        Color getPixel(int row, int col) {
            return _grid[row][col];
        }

        void printPixel(int row, int col) {
            std::cout << "( " << _grid[row][col].getRed() << ", " << _grid[row][col].getGreen() << ", " << _grid[row][col].getBlue() << " )\n";
        }
/*
        std::string to_ppm(Canvas canvas) {
            std::string value;
            std::string line;

            std::string ppm_string = "93\n" + 
                std::to_string(canvas.getWidth()) + " " +
                std::to_string(canvas.getHeight()) + "\n255\n";

            for (Color pixel: canvas.getGrid()) {
                line = "";
                std::vector<float> colors = {pixel.getRed(), pixel.getGreen(), pixel.getBlue()};
                for (float color: colors) {
                    value = std::to_string(std::round(255 * color)) + " ";

                    if ((line.length() + value.length()) > 70 ){
                        ppm_string += line + "\n";
                        line = "";
                    }

                    line += value;
                }

                ppm_string += line + "\n";
            }    

            return ppm_string;
        }
*/
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