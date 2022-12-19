#include "Tuple.h"
#include "Canvas.h"
#include <fstream>

#ifndef RAY_TRACER_PROJECTILE_H
#define RAY_TRACER_PROJECTILE_H

class Projectile {
    private:
        Tuple _position;
        Tuple _velocity;
    public:
        Projectile(){}

        Projectile(Tuple position, Tuple velocity) {
            _position = position;
            _velocity = velocity;
        }

        void setPosition(float x, float y, float z) {
            _position = Point(x, y, z);
        }

        void setVelocity(float x, float y, float z) {
            _velocity = Vector(x, y, z);
        }

        Tuple getPosition() {
            return _position;
        }

        Tuple getVelocity() {
            return _velocity;
        }
};

class Environment {
    private:
        Tuple _gravity;
        Tuple _wind;

    public:
        Environment() {}

        Environment(Tuple gravity, Tuple wind) {
            _gravity = gravity;
            _wind = wind;
        }

        void setGravity(float x, float y, float z) {
            _gravity = Vector(x, y, z);
        }

        void setWind(float x, float y, float z) {
            _wind = Vector(x, y, z);
        }

        Tuple getGravity() {
            return _gravity;
        }

        Tuple getWind() {
            return _wind;
        }        

};

Tuple tuple;

Projectile tick(Environment env, Projectile proj) {
    Tuple position = tuple.add(proj.getPosition(), proj.getVelocity());
    Tuple velocity = tuple.add(
        tuple.add(proj.getVelocity(), env.getGravity()),
        env.getWind()
    );

    return Projectile (position, velocity);
}

void fireProjectile() {
    Point start = Point(0, 1, 0);
    Tuple velocity = tuple.multiply(tuple.normalize(Vector(1,1.8,0)), 11.25);

    Projectile p = Projectile(start, velocity);
    Environment e = Environment(Vector(0, -0.1, 0), Vector(-0.01, 0, 0));

    int x = 0;
    int y = 0;
    int width = 900;
    int height = 550;

    Canvas c = Canvas(width, height, Color(0, 0, 0));

    while (true) {

        p = tick(e, p);
        if (p.getPosition().getY() <= 0 ) {
            break;
        }

        x = std::round(p.getPosition().getX());
        y = std::round(p.getPosition().getY());

        c.setPixel(x, (height - y), Color(1, 1 ,1));

    }   

    std::string ppm_str = c.to_ppm(c);

    std::ofstream file;
    file.open("cannon.ppm", std::ios::out);

    file << ppm_str;

    file.close();
}

#endif