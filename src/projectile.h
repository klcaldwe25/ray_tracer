#include "Tuple.h"

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
    Projectile p = Projectile(Point(0, 1, 0), tuple.normalize(Vector(1,1,0)));
    Environment e = Environment(Vector(0, -0.1, 0), Vector(-0.01, 0, 0));

    while (true) {

        p = tick(e, p);
        if (p.getPosition().getY() <= 0 ) {
            break;
        }

        std::cout << "( " << p.getPosition().getX() << ", " << p.getPosition().getY() << ", " << p.getPosition().getZ() << " )\n";
    }    
}

#endif