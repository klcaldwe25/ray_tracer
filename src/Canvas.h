#include "Color.h"
#include <vector>
#include <string>

#ifndef RAY_TRACER_CANVAS_H
#define RAY_TRACER_CANVAS_H

class Canvas {
    protected:
        int mWidth;
        int mHeight;
        std::vector< std::vector<Color> > mGrid;
    
    public:
        Canvas(){}

        Canvas(int width, int height, Color color) {
            mWidth = width;
            mHeight = height;
            for(int i=0; i<height; i++) {
                std::vector<Color> col;

                for (int k=0; k<width; k++) {
                    col.push_back(color);
                }

                mGrid.push_back(col);
            }
        }

        void setWidth(int width) {
            mWidth = width;
        }

        void setHeight(int height) {
            mHeight = height;
        }

        void setPixel(int col, int row, Color color) {
            mGrid[row][col] = color;
        }

        float getWidth() {
            return mWidth;
        }

        float getHeight() {
            return mHeight;
        }

        std::vector< std::vector<Color> > getGrid() {
            return mGrid;
        }

        Color getPixel(int col, int row) {
            return mGrid[row][col];
        }

        void printPixel(int row, int col) {
            std::cout << "( " << mGrid[row][col].getRed() << ", " << mGrid[row][col].getGreen() << ", " << mGrid[row][col].getBlue() << " )\n";
        }

        std::string to_ppm() {
            std::string value;
            std::string line;

            std::string ppm_string = "P3\n" + std::to_string(mWidth) + " " + std::to_string(mHeight) + "\n255\n";  

            for (int row=0; row<mHeight; row++) {
                line = "";
                for (int col=0; col<mWidth; col++) {
                    std::vector<float> colors;
                    colors.push_back(mGrid[row][col].getRed());
                    colors.push_back(mGrid[row][col].getGreen());
                    colors.push_back(mGrid[row][col].getBlue());
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