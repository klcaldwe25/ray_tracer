#include "Canvas.h"
#include <iostream>
#include "Matrix.h"
#include <fstream>

#ifndef RAY_TRACER_CLOCK_H
#define RAY_TRACER_CLOCK_H

class Clock {
    public:
        Clock() {
            Canvas canvas = Canvas(500, 500, Color(1, 1, 1));
            float scale = canvas.getWidth() * 3/8;

            float x = 0;
            float y = 0;

            Matrix twelve = Matrix(4,1).pointMatrix(0, 0, 1);

            for (int i=1; i<13; i++) {

                Matrix current = twelve.y_rotate(i * (M_PI/6))
                        .scale(scale, 0, scale)
                        .translate(250, 0, 250);
                
                x = current.getCell(0,0);
                y = current.getCell(2, 0);    

                canvas.setPixel (x, y, Color(0, 0, 0));
                canvas.setPixel (x + 1, y + 1, Color(0, 0, 0));
                canvas.setPixel (x - 1, y - 1, Color(0, 0, 0));

            }

            std::string ppm_str = canvas.to_ppm();

            std::ofstream file;
            file.open("cannon.ppm", std::ios::out);

            file << ppm_str;

            file.close();   
                
        }

};

#endif