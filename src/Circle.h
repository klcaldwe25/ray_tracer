#include "Matrix.h"
#include "Color.h"
#include "Canvas.h"
#include "Shape.h"
#include "Intersections.h"
#include "Intersection.h"
#include <limits>
#include <fstream>

#ifndef RAY_TRACER_CIRCLE_H
#define RAY_TRACER_CIRCLE_H

class Circle {
    private:
        Matrix ray_origin = Matrix(4,4).pointMatrix(0, 0, -10);
        float wall_z = 10;
        float wall_size = 7;
        int canvas_pixels = 500;

        float pixel_size = wall_size / canvas_pixels;
        float half = wall_size / 2;

        Canvas canvas = Canvas(canvas_pixels, canvas_pixels, Color(1,1,1));
        Color color = Color(1, 0, 0);
//      Shape sphere = Shape().sphereShape();

        Sphere sphere = Sphere();

    public:

        Circle() {
            float world_x = 0;
            float world_y = 0;
            Matrix position = Matrix(4,4).pointMatrix(0,0,0);         

            for (int y=0; y<canvas_pixels; y++) {
                world_y = half - (pixel_size * y);

                for (int x=0; x<canvas_pixels; x++) {
                    world_x = -half + (pixel_size * x);
                    position.setCell(0,0,world_x);
                    position.setCell(1,0,world_y);
                    position.setCell(2,0,wall_z);

                    Ray r = Ray(ray_origin, position.subtract(ray_origin).normalize());
                    Intersections xs = Intersections().intersectSphere(r, sphere);
                    Intersection hit = xs.hit();

                    if (hit.getT() != std::numeric_limits<float>::max()) {
                        canvas.setPixel(x, y, color);
                    }
                }
            }

            std::string ppm_str = canvas.to_ppm();

            std::ofstream file;
            file.open("circle.ppm", std::ios::out);

            file << ppm_str;

            file.close();              
        }
};

#endif